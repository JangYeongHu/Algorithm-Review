a=input()
print("YES"if sum(1 for c in 'MOBIS'if c in a)>4 else"NO")