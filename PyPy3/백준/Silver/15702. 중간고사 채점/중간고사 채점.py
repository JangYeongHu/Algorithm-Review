n,m=map(int,input().split())
arr=[*map(int,input().split())]
s1=1000000
s2=0
for i in range(m):
    t = input().split()
    sm=0
    for i in range(1,n+1):
        if t[i]=='O':sm+=arr[i-1]
    if s2 < sm:
        s1 = int(t[0])
        s2 = sm
    elif s2 == sm and s1 > int(t[0]):
        s1=int(t[0])
print(s1,s2)