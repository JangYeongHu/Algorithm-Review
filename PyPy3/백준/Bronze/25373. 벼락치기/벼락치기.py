n=int(input())
r=(n-29)//7+8
if n<2:r=1
elif n<4:r=2
elif n<7:r=3
elif n<11:r=4
elif n<16:r=5
elif n<22:r=6
elif n<29:r=7
print(r)