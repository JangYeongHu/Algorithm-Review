n=int(input())
a=[1]
c=2
r='+\n'
for i in range(n):
 b=int(input())
 while len(a)==0 or a[-1]<b:
  a.append(c)
  c+=1
  r+='+\n'
 if a[-1]!=b or len(a)==0:r='NO';break
 a.pop();r+='-\n'
print(r)