n = int(input())
arr = [input() for i in range(n)]
arr.sort()
cnt = 0
for i in range(n):
    k = 0
    c = arr.pop(0)
    for j in arr:
        if c == j[:len(c)]: k+=1
    if k == 0: cnt+=1
print(cnt)