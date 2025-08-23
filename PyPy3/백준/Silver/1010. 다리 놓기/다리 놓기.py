for _ in range(int(input())):
    N,M = map(int,input().split())
    D = M - N
    r1,r2,r3 = 1,1,1
    for item in range(1, N+1, 1):
        r1 *= item
    for item in range(1, M+1, 1):
        r2 *= item
    for item in range(1, D+1, 1):
        r3 *= item
    print(int(r2/(r1*r3)))