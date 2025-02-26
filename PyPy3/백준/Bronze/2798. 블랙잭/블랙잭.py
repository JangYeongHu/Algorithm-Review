n,m=map(int,input().split())
a=[*map(int,input().split())]
s=0
for i in range(n-2):
 for j in range(i+1,n-1):
  for k in range(j+1,n):
   if a[i]+a[j]+a[k]>m:continue
   s=max(s,a[i]+a[j]+a[k])
print(s)