a=int(input())
b=sum([*map(int,input().split())])+8*a-8
print(b//24,b%24)