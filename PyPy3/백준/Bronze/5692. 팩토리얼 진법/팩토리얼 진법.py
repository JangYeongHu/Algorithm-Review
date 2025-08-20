import sys
input = sys.stdin.readline

while 1:
    b=int(input())
    if b==0:break
    a,r,s=1,0,2
    while b:
        r+=a*(b%10)
        a*=s
        s+=1
        b//=10
    print(r)
