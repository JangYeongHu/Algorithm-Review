import sys
input = sys.stdin.readline
n,m=map(int,input().split())
a={}
c={}
for i in range(n):
    b=input().strip()
    a[b]=i+1
    c[i+1]=b
for i in range(m):
    b=input().strip()
    if b.isdigit():print(c[int(b)])
    else:print(a[b])