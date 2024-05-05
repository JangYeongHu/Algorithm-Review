a,b=map(int,input().split())
if not a+b: print("Not a moose")
elif a==b: print("Even",a+b)
else: print("Odd",max(a,b)*2)