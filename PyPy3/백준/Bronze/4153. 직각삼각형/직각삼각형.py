while 1:
 a=[*map(int,input().split())]
 if a[0]==0:break
 a.sort()
 print('right'if a[0]**2+a[1]**2==a[2]**2 else'wrong')