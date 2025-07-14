import sys
input = sys.stdin.readline

n = int(input())
d = [0] * (n + 2)
a = list(map(int, input().split()))
for i in range(1, n + 1):
    d[i] = a[i - 1]

q = int(input())
for _ in range(q):
    parts = input().split()
    cmd = int(parts[0])
    if cmd == 1:
        c = int(parts[1])
        x = int(parts[2])
        t=c
        xt=x
        while xt>0:
            so=min(d[t], xt)
            d[t]+=so
            xt-=so
            t-=1
            if t <= 0:break
        t = c + 1
        xt = x
        while xt>0:
            so=min(d[t],xt)
            d[t]+=so
            xt-=so
            t+=1
            if t > n:break
    else:
        c=int(parts[1])
        print(d[c])
