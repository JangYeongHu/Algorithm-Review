import math
n=int(input())
b=[0]*8001
c=[0]
a=[int(input()) for i in range(n)]
for i in a:b[i+4000]+=1
for i in range(1,8001):
 if b[i]>b[c[0]]:c=[i]
 elif b[i]==b[c[0]]:c.append(i)
print(math.floor(sum(a)/n+0.5))
print(sorted(a)[n//2])
print(c[0]-4000 if len(c)==1 else c[1]-4000)
print(max(a)-min(a))