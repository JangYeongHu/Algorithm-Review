import sys
input = sys.stdin.readline
N = int(input())
arr = [*map(int, input().split())]

ans = [arr[0]]
if ans[0] < 1 or ans[0] > 1000000000:
    print(-1)
    exit()

sum_val = ans[0]

for i in range(1, N):
    b = arr[i]
    if b < 0 or b > 1000000000:
        print(-1)
        exit()
        
    avg = sum_val / i
    a1 = b
    if a1 >= avg and 1 <= a1 <= 1000000000:
        ans.append(a1)
        sum_val += a1
        continue
    a2 = b + 1
    if a2 < avg and 1 <= a2 <= 1000000000:
        ans.append(a2)
        sum_val += a2
        continue
    print(-1)
    exit()

print(*ans)