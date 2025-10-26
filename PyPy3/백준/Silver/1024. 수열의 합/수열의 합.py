N,L = map(int,input().split())
st = 0
while L <= 101:
    if L == 101:
        print(-1)
        break
    if L%2 == 1:
        if N%L == 0 and N//L - L//2 >= 0:
            st = N//L - L//2
            for i in range(L):
                print(st,end=" ")
                st+=1
            break
    else:
        if N%L != 0 and 2*N%L == 0 and N//L - L//2 + 1 >= 0:
            st = N//L - L//2 + 1
            for i in range(L):
                print(st,end=" ")
                st+=1
            break
    L+=1