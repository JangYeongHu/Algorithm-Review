N,M=map(int,input().split())
L,R=1,M
ans=0
for _ in range(int(input())):
    a = int(input())
    if a < L:
        d=L-a
        ans+=d
        L-=d
        R-=d
    elif a>R:
        d=a-R
        ans+=d
        L+=d
        R+=d
print(ans)