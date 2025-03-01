for _ in range(int(input())):
 k=int(input())
 n=int(input())
 a=[[0]*n for _ in range(k+1)]
 for i in range(n):a[0][i]=i+1
 for i in range(1,k+1):
  for j in range(n):a[i][j]=sum(a[i-1][:j+1])
 print(a[-1][-1])