a=[*map(int,input().split(":"))]
b=[*map(int,input().split(":"))]
c=a[0]*3600+a[1]*60+a[2]
d=b[0]*3600+b[1]*60+b[2]
if c<d:e=d-c
else:e=24*3600-c+d
print(f"{e//3600:02}:{e%3600//60:02}:{e%60:02}")