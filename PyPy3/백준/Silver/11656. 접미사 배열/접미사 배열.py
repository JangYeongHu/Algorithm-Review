n=reversed(input())
a = ['']
for i in n:a.append(i+a[-1])
a.pop(0)
a=sorted(a)
for i in a:print(i)