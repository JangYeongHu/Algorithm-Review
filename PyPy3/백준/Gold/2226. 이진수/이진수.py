n=int(input())
a=1
for i in range(n-2):
    if i&1:a=a*2+1
    else:a=a*2-1
if n==1:print(0)
else:print(a)