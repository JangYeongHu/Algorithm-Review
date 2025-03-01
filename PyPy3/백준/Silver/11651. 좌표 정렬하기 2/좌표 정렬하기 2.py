import sys
input = sys.stdin.readline
print = sys.stdout.write
n=int(input())
a=[]
for i in range(1, n+1):
    b= [*map(int,input().split())]
    a.append(b)
a.sort(key=lambda x: (x[1], x[0]))
for i in a:print(str(i[0])+' '+str(i[1])+'\n')