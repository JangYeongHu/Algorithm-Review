a,b,c=map(int,input().split())
x=[a+b,a-b,a*b]
if a%b==0: x.append(a//b)
ans=1e9
for i in x:
    if i+c>=0:ans=min(ans,i+c)
    if i-c>=0:ans=min(ans,i-c)
    if i*c>=0:ans=min(ans,i*c)
    if i//c>=0 and i%c == 0:ans=min(ans,i//c)
print(ans)
    