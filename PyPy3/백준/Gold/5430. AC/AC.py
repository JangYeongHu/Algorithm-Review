from collections import deque
for _ in range(int(input())):
    p=input()
    n=int(input())
    d=deque(input()[1:-1].split(','))
    if n==0:d=deque()
    c=0
    k=0
    for i in p:
        if i=='R':k=(k+1)%2
        else:
            if not d:c=1;break
            if k:d.pop()
            else:d.popleft()
    if c:print('error')
    else:print('['+','.join(d if k==0 else reversed(d))+']')