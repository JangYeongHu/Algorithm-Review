n=int(input())
f=int(input())
n=n//100*100
for i in range(100):
    if (n+i)%f==0:
        print("{0:02d}".format(i))
        exit(0)