for _ in range(int(input())):
 ox=input()
 n=0
 s=0
 for i in ox:
  if i=='O':n+=1;s+=n
  else:n=0
 print(s)