import math
n=int(input())
a=[*map(int,input().split())]
t,p=map(int,input().split())
s=0
for i in a:s+=math.ceil(i/t)
print(s)
print(n//p,n%p)