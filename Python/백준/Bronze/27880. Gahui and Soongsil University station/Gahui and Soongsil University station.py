c=0
for i in range(4):
 a,b=input().split()
 c+=[21,17][{'Es':0,'Stair':1}[a]]*int(b)
print(c)