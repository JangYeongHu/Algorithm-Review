n=int(input())
a=[1,1]
for i in range(2,n+1):a.append((a[i-1]+a[i-2])%10007)
print(a[n])