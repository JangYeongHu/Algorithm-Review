n=int(input())
b=int(input())
a=[b]
if n>19:a.append(b*3//4)
if n>14:a.append(b-2000)
if n>9:a.append(b*9//10)
if n>4:a.append(b-500)
print(max(0,min(a)))