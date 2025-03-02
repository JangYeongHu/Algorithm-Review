d=[0]*41
d[1]=d[2]=1
for i in range(3,41):d[i]=d[i-1]+d[i-2]
for _ in range(int(input())):
 a=int(input())
 print(*(d[a-1],d[a]) if a!=0 else (1,0))