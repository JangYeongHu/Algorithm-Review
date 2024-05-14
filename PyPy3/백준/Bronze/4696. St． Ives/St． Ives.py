while(1):
 a=float(input())
 if a==0: break
 r=0
 c=1
 for i in range(5):
  r+=c
  c*=a
 print(f"{r:.2f}")