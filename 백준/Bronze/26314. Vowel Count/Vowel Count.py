for i in range(int(input())):
 a=input()
 print(a)
 print(int(a.count('a')+a.count('e')+a.count('i')+a.count('o')+a.count('u') > len(a)/2))