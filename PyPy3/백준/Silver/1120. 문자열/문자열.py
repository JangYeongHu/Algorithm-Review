a,b=input().split()
if len(a)>len(b):a,b=b,a
ans=51
for i in range(len(b)-len(a)+1):
    cnt=0
    for j in range(len(a)):
        if b[i+j]!=a[j]:cnt+=1
    ans=min(cnt,ans)
print(ans)