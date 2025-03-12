x=input()
print(sum([a*b for a,b in zip(sorted([*map(int,input().split())]),sorted([*map(int,input().split())],reverse=1))]))