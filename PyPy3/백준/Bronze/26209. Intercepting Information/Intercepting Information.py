arr=[*map(int,input().split())]
for i in arr:
 if i != 0 and i != 1:
  print("F")
  exit(0)
print("S")