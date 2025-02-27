for i in range(int(input())):
 p=input()
 s=[]
 for j in p:
  if j=='(':s.append(j)
  else:
   if len(s):s.pop()
   else:
    s.append(j)
    break
 print('NO'if len(s)else'YES')