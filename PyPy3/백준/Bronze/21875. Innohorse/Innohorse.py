a=input()
b=input()
print(*sorted([abs(ord(b[0])-ord(a[0])),abs(int(b[1])-int(a[1]))]))