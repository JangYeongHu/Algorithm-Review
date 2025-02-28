m,n=map(int,input().split())
a=[2]
for i in range(3,n+1):
 for j in a:
  if i%j==0:break
  if j*j>i:a.append(i);break
 else:a.append(i)
for i in a:
 if i>=m:print(i)