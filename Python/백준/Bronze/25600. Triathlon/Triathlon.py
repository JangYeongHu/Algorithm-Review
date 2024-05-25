n=int(input())
r=0
for i in range(n):
 a,d,g=map(int,input().split())
 if a==d+g:a*=2
 a=a*(d+g)
 r=max(r,a)
print(r)