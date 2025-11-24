import math

N,M = map(int,input().split())
arr = []
maxres = -1
for i in range(N):
    arr.append(list(map(int,input())))
for i in range(N):
    for j in range(M):
        for chaN in range(-8,9):
            for chaM in range(-8,9):
                for k in range(1,10):
                    res=0
                    temN,temM = i,j
                    for l in range(k):
                        res = res*10 + arr[temN][temM]
                        temN += chaN
                        temM += chaM
                        if temN >= N or temM >= M or temN < 0 or temM < 0:
                            break
                    if(res > maxres and int(math.sqrt(res)) == math.sqrt(res)):
                        maxres = res
print(maxres)