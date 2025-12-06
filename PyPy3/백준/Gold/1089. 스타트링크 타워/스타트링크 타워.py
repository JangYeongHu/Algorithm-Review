def check(n):
    res = []
    for i in range(10):
        c = 1
        for j in range(15):
            if sample[j//3][j%3+i*3] == '.' and arr[j//3][j%3+n*4] != '.':
                c = 0
                break
        if c: res.append(i)
    return res

N = int(input())
cnt = 0
m = 1
res = []
sample = ["###..########.################",
          "#.#..#..#..##.##..#....##.##.#",
          "#.#..################..#######",
          "#.#..##....#..#..##.#..##.#..#",
          "###..#######..#######..#######"]
arr = [list(input()) for i in range(5)]
for i in range(N): 
    t = check(i)
    res.append(t)
    m *= len(t)
if m == 0: 
    print(-1)
    exit()
for i in range(N): cnt += sum(res[N-1-i])*10**i*(m//len(res[N-1-i]))
print(cnt/m)