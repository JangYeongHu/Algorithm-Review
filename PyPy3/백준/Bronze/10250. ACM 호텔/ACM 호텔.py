for i in range(int(input())):
 h,w,n=map(int,input().split())
 c=101
 print(c+(n-1)%h*100+(n-1)//h)