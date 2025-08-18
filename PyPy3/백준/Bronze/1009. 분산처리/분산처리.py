for i in range(int(input())):
    a,b=map(int,input().split())
    n=1
    for j in range(b):
        n*=a
        n%=10
    if n==0:print(10)
    else:print(n)