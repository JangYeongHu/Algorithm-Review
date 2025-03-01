while 1:
 a=input()
 s=[]
 if a=='.':break
 for i in a:
  if i=='('or i=='[':s.append(i)
  elif i==')':
   if s and s[-1]=='(':s.pop()
   else:s.append(i);break
  elif i==']':
   if s and s[-1]=='[':s.pop()
   else:s.append(i);break
 print('yes'if not s else'no')