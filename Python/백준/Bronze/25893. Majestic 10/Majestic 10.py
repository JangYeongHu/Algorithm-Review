for i in range(int(input())):
 a,b,c=map(int,input().split())
 print(a,b,c)
 print(['triple-double','double-double','double','zilch'][(a<10)+(b<10)+(c<10)],"\n")