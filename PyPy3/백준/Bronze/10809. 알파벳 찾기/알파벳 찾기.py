a=[-1]*26
b=input()
for i in range(len(b)-1,-1,-1):a[ord(b[i])-97]=i
print(*a)