import sys
N = int(input())
for i in range(N):
    x1,y1,r1,x2,y2,r2 = map(int,sys.stdin.readline().split())
    di2 = abs(x1-x2)**2 + abs(y1-y2)**2
    if x1 == x2 and y1 == y2 and r1 == r2:
        if r1 and r2: print(-1)
        else: print(1)
        continue
    if di2 == (r1+r2)**2 or di2 == abs(r1-r2)**2:print(1)
    if di2 < (r1+r2)**2 and di2 > abs(r1-r2)**2:print(2)
    if di2 > (r1+r2)**2 or di2 < abs(r1-r2)**2:
        if r1 and r2:print(0)
        else:print(1)