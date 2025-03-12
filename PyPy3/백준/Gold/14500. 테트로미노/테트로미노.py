import sys
N,M=map(int,input().split())
a=[]
b=[[1,2,3],[0,0,0],[1,0,1],[0,0,1],[1,2,2],[0,1,1],[1,1,2],[0,1,0],[1,1,2]]
d=[[0,0,0],[1,2,3],[0,1,1],[1,2,2],[0,0,1],[1,1,2],[0,1,0],[1,1,2],[0,1,1]]
e=[1,1,-1,-1]
f=[1,-1,1,-1]
m=0
for i in range(N):a.append(list(map(int,sys.stdin.readline().split())))
for x in range(M):
 for y in range(N):
  for i in range(9):
   for r in range(4):
    c=0;g=a[y][x];h,l=b[i],d[i]
    for j in range(3):
     o=x+h[j]*e[r];p=y+l[j]*f[r]
     if o<0 or o>=M or p<0 or p>=N:c=1;break
     g+=a[p][o]
    if c:continue
    if m<g:m=g
print(m)