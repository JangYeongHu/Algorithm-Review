b=''
while 1:
 a=input()
 if a=='99999': break
 if a[:2]=='00':print(b,a[2:])
 elif(int(a[0])+int(a[1]))%2:
  b="left"
  print(b,a[2:])
 else:
  b="right"
  print(b,a[2:])