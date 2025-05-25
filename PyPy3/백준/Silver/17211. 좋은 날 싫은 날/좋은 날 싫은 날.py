N,M=map(int, input().split())
a,b,c,d=map(float,input().split())
s=[1.0,0.0]if M==0 else[0.0,1.0]
for _ in range(N):s=[s[0]*a+s[1]*c,s[0]*b +s[1]*d]
print(round(s[0]*1000))
print(round(s[1]*1000))