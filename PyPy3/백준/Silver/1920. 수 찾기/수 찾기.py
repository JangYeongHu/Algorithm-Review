n=int(input())
a={*map(int,input().split())}
m=int(input())
b=[*map(int,input().split())]
for i in b:
 if i in a:print(1)
 else:print(0)