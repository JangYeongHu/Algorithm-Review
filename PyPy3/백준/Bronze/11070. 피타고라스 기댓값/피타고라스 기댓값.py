for _ in range(int(input())):
    n,m=map(int,input().split())
    mx = 0
    mn = 1000000000
    r=[[0]*2 for i in range(n)]
    for i in range(m):
        a,b,p,q=map(int,input().split())
        r[a-1][0]+=p
        r[b-1][1]+=p
        r[b-1][0]+=q
        r[a-1][1]+=q
    for s,a in r:
        x=0
        if s+a:x=s*s/(s*s+a*a)
        mx=max(mx,x)
        mn=min(mn,x)
    print(int(mx*1000))
    print(int(mn*1000))