N,M = map(int,input().split())
P,S = [0]*M,[0]*M
for i in range(M):
    P[i],S[i] = map(int,input().split())
P.sort()
S.sort()
pr = 0
if S[0] * 6 <= P[0]:
    print(S[0]*N)
else:
    pr += P[0]*(N//6)
    N %= 6
    if N * S[0] >= P[0]:
        print(pr+P[0])
    else:
        print(pr + S[0]*N)