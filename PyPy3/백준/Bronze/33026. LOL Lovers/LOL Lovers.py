a=input()
b=input()
l=b.count('L')
o=b.count('O')
ll=oo=ans=0
for i in b:
    if i=='L':
        ll+=1
        l-=1
    else:
        oo+=1
        o-=1
    ans+=1
    if ll==l or oo==o:continue
    if len(b)==ans:print(-1)
    else:print(ans)
    break