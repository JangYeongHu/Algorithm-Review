a,b,n=map(int,input().split())
ans=9999
for i in range(n):
    c,m=map(int,input().split())
    arr=[*map(int,input().split())]
    if a not in arr or b not in arr:continue
    if arr.index(a)<arr.index(b):ans=min(ans,c)
if ans==9999:print(-1)
else:print(ans)