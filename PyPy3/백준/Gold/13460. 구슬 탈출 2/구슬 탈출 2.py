dx=[-1,1,0,0]
dy=[0,0,-1,1]
def go(rx,ry,bx,by,d):
    r = 0
    b = 0
    while(1):
        rtx = rx + dx[d]
        rty = ry + dy[d]
        btx = bx + dx[d]
        bty = by + dy[d]
        if arr[rty][rtx] == '#': r = 1
        if arr[rty][rtx] == 'O': r = 2
        if arr[bty][btx] == '#': b = 1
        if arr[bty][btx] == 'O': b = 2
        if rtx == bx and rty == by and b: r = b
        if btx == rx and bty == ry and r: b = r
        if r*b == 4: return -1
        elif r*b == 2:
            if b == 2: return -1
            else : return 1
        elif r*b: return [rx,ry,bx,by]

        if not r:
            rx = rtx
            ry = rty
        if not b:
            bx = btx
            by = bty

n,m = map(int,input().split())
arr = [[*input()] for i in range(n)]
a = [0]*5
q = []
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'R':
            a[0] = j
            a[1] = i
            arr[i][j] = '.'
        if arr[i][j] == 'B':
            a[2] = j
            a[3] = i
            arr[i][j] = '.'
q.append(a)
while(q):
    t = q.pop(0)
    if t[4] > 9: continue
    for i in range(4):
        k = go(t[0],t[1],t[2],t[3],i)
        if k == 1: 
            print(t[4]+1)
            exit()
        elif k == -1: continue
        if k == t[:4]: continue
        q.append(k + [t[4]+1])
print(-1)