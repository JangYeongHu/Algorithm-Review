a=int(input())
c=0
for i in range(3):
 b=int(input())
 c+=(a>b)-(a<b)*4
 a=b
if c==-12:print("Fish Rising")
elif c==3:print("Fish Diving")
elif c==0:print("Fish At Constant Depth")
else:print("No Fish")