while 1:
 a,b=map(int,input().split())
 if a+b==0:break
 c=d=0
 while a or b:
  c,a,b=(a%10+b%10+c)//10,a//10,b//10
  d+=c
 print(d)