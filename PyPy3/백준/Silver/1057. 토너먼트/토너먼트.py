N,K,L = map(int,input().split())
cnt = 0
while cnt < 100000:
    K = (K+1)//2
    L = (L+1)//2
    cnt+= 1
    if K == L:
        print(cnt)
        exit()
print(-1)