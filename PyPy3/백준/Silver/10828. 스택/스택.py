s=[]
for _ in range(int(input())):
 a=input().split()
 if a[0]=='push':s.append(a[1])
 elif a[0]=='pop':print(s.pop()if s else-1)
 elif a[0]=='size':print(len(s))
 elif a[0]=='top':print(s[-1]if s else-1)
 else:print(0 if s else 1)