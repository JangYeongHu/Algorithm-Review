n=int(input())
a=[[*map(int,input().split())] for i in range(n)]
r=0
for i in range(n):r+=a[i-1][0]*a[i][1]-a[i-1][1]*a[i][0]
print(f"%.1f"%(abs(r)/2))