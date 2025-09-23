import sys
input=sys.stdin.readline
while 1:
    a,b=map(int,input().split())
    ca,cb=a,b
    if a+b==0:break
    d={a:0}
    while a!=1:
        c=d[a]
        if a&1:
            a=a*3+1
            d[a]=c+1
        else:
            a>>=1
            d[a]=c+1
    c=0
    while b not in d:
        if b&1: b=b*3+1
        else: b>>=1
        c+=1
    print(f"{ca} needs {d[b]} steps, {cb} needs {c} steps, they meet at {b}")
