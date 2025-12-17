x1,y1,x2,y2,x3,y3 = map(int,input().split())
r = [0,0,0]
r[0] = ((x1-x2)**2 + (y1-y2)**2)**0.5
r[1] = ((x2-x3)**2 + (y2-y3)**2)**0.5
r[2] = ((x3-x1)**2 + (y3-y1)**2)**0.5
r.sort()
if (x3-x1)*(y2-y1) == (x2-x1)*(y3-y1):print(-1)
else:print((r[2]-r[0])*2)