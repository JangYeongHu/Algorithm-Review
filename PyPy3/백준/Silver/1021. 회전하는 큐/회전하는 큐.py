N,M = map(int,input().split())
arr = [9] * N
cnt = 0
for a in range(N):
    arr[a] = a+1
ans = list(map(int,input().split()))
for a in range(M):
    ind = arr.index(ans[a])
    if ind <= (N-a)/2:  
        arr.reverse()
        for _ in range(ind):
            arr.insert(0,arr.pop())
            cnt += 1
        arr.pop()
        arr.reverse()
    else:
        for _ in range(N-a-1-ind):
            arr.insert(0,arr.pop())
            cnt += 1
        arr.pop()
        cnt += 1
print(cnt)
