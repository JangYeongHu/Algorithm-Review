for i in range(int(input())):
 a,b,c=input().split()
 print(a.replace(a[int(b):int(c)],""))