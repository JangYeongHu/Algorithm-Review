b=input()
a=sum(map(int,input().split()))
r=[*map(int,input().split())]
for i in r:
    if i>0:a*=i
print(a)