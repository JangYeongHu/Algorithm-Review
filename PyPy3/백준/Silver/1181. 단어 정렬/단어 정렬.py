n=int(input())
print(*sorted({input() for _ in range(n)},key=lambda x:(len(x),x)),sep='\n')