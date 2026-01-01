a=input()
n=0
for i in range(len(a)):
    if a[i]=='*':continue
    if i%2==0:n+=int(a[i])
    else:n+=3*int(a[i])

for i in range(10):
    if a.index("*")%2==0 and (n+i)%10==0: print(i)
    elif a.index("*")%2==1 and (n+i*3)%10==0: print(i)
