l=int(input())
s=input()
a=0
b=1
for i in range(l):
 a+=(ord(s[i])-96)*b%1234567891
 b*=31
print(a)