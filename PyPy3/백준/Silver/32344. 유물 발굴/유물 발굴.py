_ = input()
n = int(input())

arr = [[100000, 100000, 0, 0] for _ in range(n)]
used = [False] * n
for _ in range(n):
    a, v, h = map(int, input().split())
    a -= 1
    used[a] = True
    if arr[a][0] > v: arr[a][0] = v
    if arr[a][1] > h: arr[a][1] = h
    if arr[a][2] < v: arr[a][2] = v
    if arr[a][3] < h: arr[a][3] = h

ans = 0
x = 0
for i in range(n):
    if not used[i]:continue
    min_v, min_h, max_v, max_h = arr[i]
    t = (max_v - min_v + 1) * (max_h - min_h + 1)
    if t > ans:
        ans = t
        x = i

print(x + 1, ans)