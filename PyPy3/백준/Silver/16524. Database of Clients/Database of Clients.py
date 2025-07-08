s={}
for i in range(int(input())):
    a,b=input().split("@")
    s[a.split("+")[0].replace(".","")+'@'+b] = 1
print(len(s))