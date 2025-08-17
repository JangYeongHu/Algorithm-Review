T_1 = int(input())
L_1 = 0

while L_1<T_1:
    cnt=0
    L_2=0
    x1,y1,x2,y2 = map(int, input().split())
    T_2 = int(input())
    while L_2 < T_2:
        xp,yp,rp = map(int, input().split())

        if((((xp-x1)**2 + (yp-y1)**2)**(0.5) < rp) ^ (((xp-x2)**2 + (yp-y2)**2)**(0.5) < rp)):
            cnt+=1
        L_2 += 1
    print(cnt)
    L_1 += 1