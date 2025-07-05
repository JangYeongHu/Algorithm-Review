a=[*map(int,input().split())]
s=0
for i in a:
    if i==1:s+=500
    elif i==2:s+=800
    else:s+=1000
print(5000-s)