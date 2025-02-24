for _ in range(int(input())):
 a,b=input().split()
 print(''.join([x*int(a) for x in list(b)]))