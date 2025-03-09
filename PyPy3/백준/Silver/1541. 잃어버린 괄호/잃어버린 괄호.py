a=list(input().split("-"))
s=sum(map(int,a[0].split("+")))
for i in a[1:]:s-=sum(map(int,i.split("+")))
print(s)