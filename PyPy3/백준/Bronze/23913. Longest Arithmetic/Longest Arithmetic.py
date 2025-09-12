for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    s=a[1]-a[0]
    k=1
    m=1
    for i in range(n-2):
        if a[i+2]-a[i+1]==s:k+=1
        else:k=1
        m=max(m,k)
        s=a[i+2]-a[i+1]
    print(f"Case #{_+1}: {m+1}")