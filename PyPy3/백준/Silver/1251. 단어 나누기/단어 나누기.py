s=input()
l=len(s)
arr=[]
for i in range(1,l-1):
    for j in range(i+1,l):
        t=''.join(reversed(s[:i]))+''.join(reversed(s[i:j]))+''.join(reversed(s[j:]))
        arr.append(t)
print(sorted(arr)[0])