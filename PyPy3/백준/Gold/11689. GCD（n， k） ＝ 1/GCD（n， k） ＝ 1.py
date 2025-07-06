from math import pow
n=int(input())
sosu=[]
for i in range(2,int(n**0.5+1)):
    for j in sosu:
        if j*j>i:
            sosu.append(i)
            break
        if i%j==0: break
    else: sosu.append(i)
ans=1
for i in sosu:
    cnt=0
    while not n%i:
        cnt+=1
        n//=i
    if cnt==1:ans*=i-1
    else:ans*=int(pow(i,cnt))-int(pow(i,cnt-1))
if n!=1:ans*=n-1
print(ans)