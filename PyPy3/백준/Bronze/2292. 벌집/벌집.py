n=int(input())
a=1
r=1
while(n>0):
 n-=a
 r+=1
 a=r*6-6
print(r-1)