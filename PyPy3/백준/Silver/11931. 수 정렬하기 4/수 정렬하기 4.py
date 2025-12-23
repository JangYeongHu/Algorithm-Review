n=int(input())
a=reversed(sorted(int(input()) for i in range(n)))
for i in a:print(i)