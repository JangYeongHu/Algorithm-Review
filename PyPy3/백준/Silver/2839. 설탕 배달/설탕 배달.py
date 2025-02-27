n=int(input())
a=[9999]*5001
a[3]=1
a[5]=1
for i in range(6,n+1):a[i]=min(a[i-3],a[i-5])+1
print(a[n] if a[n]<9999 else -1)