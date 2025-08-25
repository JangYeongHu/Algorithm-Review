n,t=map(int,input().split())
ans=1000001
for _ in range(n):
    s,i,c=map(int,input().split())
    if t<s:ans=min(ans,s-t)
    elif i*(c-1)+s<t:
        continue
    else:
        x=i-(t-s)%i
        if x==i:ans=0
        else:ans=min(ans,x)
if ans==1000001:print(-1)
else:print(ans)