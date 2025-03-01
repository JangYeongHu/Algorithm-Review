import math
n=int(input())
if n==0:
 print(0)
 exit()
a=[int(input()) for i in range(n)]
a.sort()
z=(math.floor(n*15/100+0.5))
print(math.floor(sum(a[z:n-z])/(n-2*z)+0.5))