n,m=map(int,input().split())
chess = [list(input()) for _ in range(n)]
res = 100
for i in range(n-7):
 for j in range(m-7):
  cnt1=0
  cnt2=0
  for x in range(i,i+8):
   for y in range(j,j+8):
    if (x+y)%2==0:
     if chess[x][y]=='W':cnt1+=1
     else:cnt2+=1
    else:
     if chess[x][y]=='B':cnt1+=1
     else:cnt2+=1
  res=min(res,cnt1,cnt2)
print(res)