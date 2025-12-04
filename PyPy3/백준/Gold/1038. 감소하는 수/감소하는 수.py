from collections import deque
N = int(input())
dq = deque([i for i in range(10)])
cnt = 0
while dq:
    t = dq.popleft()
    if cnt == N:
        print(t)
        exit()
    cnt+=1
    for i in range(t%10): dq.append(t*10+i)
print(-1)