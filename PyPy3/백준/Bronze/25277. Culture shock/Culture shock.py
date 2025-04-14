a=input()
b=input().split()
c=0
for i in b:
    if i=='he' or i=='him' or i=='she' or i=='her':
        c+=1
print(c)