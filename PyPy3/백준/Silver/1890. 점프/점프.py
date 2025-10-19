n=int(input())
arr = [list(map(int,input().split())) for i in range(n)]
li = [[0]*n for i in range(n)]
li[0][0] = 1
for i in range(n):
    for j in range(n):
        for x in range(j):
            if arr[i][x] == j-x: li[i][j] += li[i][x]
        for y in range(i):
            if arr[y][j] == i-y: li[i][j] += li[y][j]
print(li[-1][-1])