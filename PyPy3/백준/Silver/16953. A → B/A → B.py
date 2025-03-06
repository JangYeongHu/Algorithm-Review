from collections import deque
a,b=map(int,input().split())
q=deque()
q.append((a,1))
while q:
 x,cnt=q.popleft()
 if x==b:print(cnt);exit()
 if x*2>b:continue
 q.append((x*2,cnt+1))
 d=x*10+1
 if b<d:continue
 q.append((d,cnt+1))
print(-1)