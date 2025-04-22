from collections import deque
n=int(input())
dq=deque()
for i in range(n):dq.append(i+1)
while len(dq)>1:
    print(dq.popleft(),end=' ')
    dq.append(dq.popleft())
print(dq[0])