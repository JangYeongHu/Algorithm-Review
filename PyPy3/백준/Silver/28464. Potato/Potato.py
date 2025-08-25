n=int(input())
a=sorted([*map(int,input().split())])
s=sum(a[:n//2])
print(s,sum(a)-s)