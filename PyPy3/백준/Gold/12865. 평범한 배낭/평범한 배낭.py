N,K=map(int,input().split())
ls=[[*map(int,input().split())] for i in range(N)]
arr = [[0]*(K+1) for i in range(N+1)]
for i in range(1,N+1):
    for j in range(K+1):
        if j<ls[i-1][0]:arr[i][j]=arr[i-1][j]
        else:arr[i][j]=max(arr[i-1][j],ls[i-1][1] + arr[i-1][j-ls[i-1][0]])
print(arr[-1][-1])