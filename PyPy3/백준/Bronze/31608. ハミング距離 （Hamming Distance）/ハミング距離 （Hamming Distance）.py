r=int(input())
d=0
b=[*input()]
c=[*input()]
for i in range(r):
 if b[i]!=c[i]:d+=1
print(d)