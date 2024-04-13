n=int(input())
t=0
a=[*map(int,input().split())]
b=[*map(int,input().split())]
for i in range(n):
 if b[i]>=a[i]:t+=1
print(t)