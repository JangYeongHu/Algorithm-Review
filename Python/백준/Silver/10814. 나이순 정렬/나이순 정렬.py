a=sorted([input().split() for _ in range(int(input()))],key=lambda x:(int(x[0])))
for i in a:print(*i)