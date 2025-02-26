n,k=map(int,input().split())
a=b=1
for _ in range(k):a*=n;n-=1
for i in range(1,k+1):b*=i
print(a//b)