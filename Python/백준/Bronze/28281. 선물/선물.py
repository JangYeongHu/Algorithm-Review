a,b=map(int,input().split())
c=[*map(int,input().split())]
m=sum(c)
for i in range(a-1):m=min(m,c[i]+c[i+1])
print(m*b)