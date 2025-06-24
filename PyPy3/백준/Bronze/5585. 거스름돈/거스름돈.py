a=1000-int(input())
b=[500,100,50,10,5,1]
s=0
for i in b:
 s+=a//i
 a%=i
print(s)