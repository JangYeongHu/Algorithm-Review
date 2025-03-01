from collections import deque
for _ in range(int(input())):
    im=[0]*10
    n,m=map(int,input().split())
    a=[*map(int,input().split())]
    for i in a:im[i]+=1
    q=deque(a)
    cnt=0
    r=9
    while q:
        while im[r] == 0:r-=1
        if q[0]==r:
            cnt+=1
            if m==0:break
            im[r]-=1
            q.popleft()
            m-=1
        else:
            q.append(q.popleft())
            if m==0:m=len(q)-1
            else:m-=1
    print(cnt)