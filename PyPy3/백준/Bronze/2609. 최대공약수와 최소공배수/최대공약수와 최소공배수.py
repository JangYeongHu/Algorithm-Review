a,b=map(int,input().split())
c,d=a,b
while b:a,b=b,a%b
print(a)
print(c*d//a)