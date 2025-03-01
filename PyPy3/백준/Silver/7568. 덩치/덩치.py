n=int(input())
a=[[*map(int,input().split())]for _ in range(n)]
for i in range(n):
 r=1
 for j in range(n):
  if a[i][0]<a[j][0]and a[i][1]<a[j][1]:r+=1
 print(r,end=' ')