a=[input() for _ in range(3)]
for i in range(3):
 if a[i].isdigit():n=int(a[i])+3-i
b=''
if(n%3==0):b+='Fizz'
if(n%5==0):b+='Buzz'
print(b or n)