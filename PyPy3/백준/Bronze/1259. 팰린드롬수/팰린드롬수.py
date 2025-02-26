while 1:
 n=input()
 if n=='0':break
 c=1
 for i in range(len(n)//2):
  if n[i]!=n[-1-i]:
   print('no')
   c=0
   break
 if c:print('yes')