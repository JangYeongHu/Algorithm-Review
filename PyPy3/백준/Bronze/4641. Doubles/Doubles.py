while 1:
    a=[*map(int, input().split())]
    if a[0]==-1:break
    a.pop()
    s=set(a)
    c=0
    for x in a:
        if x*2 in s:
            c+=1
    print(c)