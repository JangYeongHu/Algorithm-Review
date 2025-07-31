r=[25,10,5,1]
for i in range(int(input())):
    a=int(input())
    for i in r:
        print(a//i,end=" ")
        a%=i