n=1
while 1:
 o,w=map(int,input().split())
 if o==0:break
 c=0
 while 1:
  a,b=input().split()
  if a=='#':break
  if a=='F':w+=int(b)
  else:w-=int(b)
  if w<=0:c=1
 if c:print(n,'RIP')
 elif w>o/2 and w<2*o:print(n,':-)')
 else:print(n,':-(')
 n+=1