a=[2]
for i in range(3,1001):
  for j in a:
    if i%j==0:break
    if j==a[-1]:a.append(i)
n=int(input())
b=[*map(int,input().split())]
s=0
for i in b:
  if i in a:s+=1
print(s)