import sys
input = sys.stdin.readline
n,q=map(int,input().split())
arr=[[0]*3 for i in range(n+1)]
for i in range(1,n+1):
    arr[i][0]+=arr[i-1][0]
    arr[i][1]+=arr[i-1][1]
    arr[i][2]+=arr[i-1][2]
    arr[i][int(input())-1]+=1
for i in range(q):
    a,b=map(int,input().split())
    print(arr[b][0]-arr[a-1][0],arr[b][1]-arr[a-1][1],arr[b][2]-arr[a-1][2])