n=input()
b={}
for i in [*map(int,input().split())]:b[i]=b.get(i,0)+1
m=input()
for i in[*map(int,input().split())]:print(b.get(i,0),end=' ')