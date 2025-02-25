a=[*map(int,input().split())]
s=0
for i in range(7):s+=a[i]<a[i+1]
print('ascending'if s>6 else'mixed'if s>0 else'descending')