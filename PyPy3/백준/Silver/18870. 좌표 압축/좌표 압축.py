import sys
input = sys.stdin.readline
print = sys.stdout.write
a=int(input())
b=[*map(int,input().split())]
d=sorted(b)
c=dict()
now = 0
for i in range(a):
 if d[i] not in c:c[d[i]]=now;now+=1
for i in range(a):print(str(c[b[i]])+" ")