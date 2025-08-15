while 1:
    n,d=map(int, input().split())
    if n+d==0:break
    arr=[1]*n
    for _ in range(d):
        b=[*map(int, input().split())]
        for i in range(n):
            if b[i]==0:arr[i]=0
    if any(arr):print("yes")
    else:print("no")