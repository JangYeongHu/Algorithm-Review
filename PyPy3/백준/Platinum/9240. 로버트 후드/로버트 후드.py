import math
def ccw(a, b, c):
    res = (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1])
    if res > 0:return 1
    if res < 0:return -1
    return 0

def subtract(p1, p2):
    return (p1[0] - p2[0], p1[1] - p2[1])

def make_convex_hull(points):
    p0 = min(points, key=lambda p: (p[1], p[0]))

    points.sort(key=lambda p: (
        math.atan2(p[1] - p0[1], p[0] - p0[0]),
        p[1], p[0]
    ))

    poly = []
    for i in range(len(points)):
        while len(poly) >= 2:
            second = poly[-1]
            first = poly[-2]
            if ccw(points[first], points[second], points[i]) > 0:
                break
            poly.pop()
        poly.append(i)

    return poly

def get_distance(a, b):
    return math.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2)

def do_calipers(points, poly):
    a, b = 0, 1
    size = len(poly)
    max_distance = 0

    while True:
        max_distance = max(max_distance, get_distance(points[poly[a]], points[poly[b]]))

        next_a = (a + 1) % size
        next_b = (b + 1) % size

        res = ccw(
            (0,0),
            subtract(points[poly[b]], points[poly[next_b]]),
            subtract(points[poly[a]], points[poly[next_a]])
        )

        if res > 0:
            a = next_a
            if a == 0:
                break
        else:
            b = next_b
            if b == 1:
                break

    return max_distance

C = int(input())
points = []

for _ in range(C):
    x,y=map(int,input().split())
    points.append((x,y))

poly=make_convex_hull(points)
result=do_calipers(points,poly)

print(result)