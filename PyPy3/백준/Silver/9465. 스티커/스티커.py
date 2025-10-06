import sys
s = sys.stdin.readline
T = int(s())
for _ in range(T):
    n = int(s())
    arr = [list(map(int,s().split())) for i in range(2)]
    if n-1:
        arr[0][1] += arr[1][0]
        arr[1][1] += arr[0][0]
    for i in range(2,n):
        for j in range(2):
            arr[j][i] += max(arr[(j+1)%2][i-1],arr[(j+1)%2][i-2])
    print(max(arr[0][-1],arr[1][-1]))