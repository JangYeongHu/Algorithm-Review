k=int(input())
a=[]
for i in range(k):
 n=int(input())
 if n==0:a.pop()
 else:a.append(n)
print(sum(a))