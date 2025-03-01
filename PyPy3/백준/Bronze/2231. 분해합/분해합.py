n=int(input())
now=1
while now<n:
 if now+sum(map(int,str(now)))==n:
  print(now)
  break
 now+=1
if now==n:print(0)