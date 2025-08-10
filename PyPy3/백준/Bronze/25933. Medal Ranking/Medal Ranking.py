for i in range(int(input())):
    ans=0
    a,b,c,d,e,f=map(int,input().split())
    color = (a+b+c > d+e+f)
    count = (a>d) or (a==d and b>e) or (a==d and b==e and c>f)
    print(a,b,c,d,e,f)
    print(['none','count','color','both'][color + count*2],)
    print()