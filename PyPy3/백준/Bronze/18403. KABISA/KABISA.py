for i in range(int(input())):
 arr = list(map(int, input().replace(',', ' ').split()))
 print(*[y for y in arr if y % 4 == 0 and (y % 100 != 0 or y % 400 == 0)])