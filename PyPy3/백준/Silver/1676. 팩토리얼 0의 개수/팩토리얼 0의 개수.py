a=1
c=0
for i in range(2,int(input())+1):a*=i
while a%10==0:
 a//=10
 c+=1
print(c)