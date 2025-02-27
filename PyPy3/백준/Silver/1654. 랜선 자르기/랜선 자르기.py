k,n=map(int,input().split())
a=[int(input()) for _ in range(k)]
s=1
e=max(a)
while s<=e:
 m=(s+e)//2
 c=0
 for i in a:c+=i//m
 if c<n:e=m-1
 else:s=m+1
print(e)