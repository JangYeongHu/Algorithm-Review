a=int(input())
r=sorted([*map(int,input().split())])
n=a//2-1
if a%2:n+=1
print(r[n])