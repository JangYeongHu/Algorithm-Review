from functools import cmp_to_key

def compare(a, b, criteria):
    for crit in criteria:
        if not crit: 
            continue
        o = crit[-1]
        n = crit[:-1]
        idx = int(n) - 1
        va = a[idx]
        vb = b[idx]
        cmp_val = (va > vb) - (va < vb)
        if cmp_val != 0:
            return cmp_val if o == 'A' else -cmp_val
    return 0

while 1:
    h = input()
    if h == '#':
        break
    r = []
    while 1:
        l = input()
        if l == '#': break
        r.append(l.split(','))
    print(h)
    while 1:
        l = input()
        if l == '0#':
            break
        criteria = l.split(',')
        rs = sorted(r, key=cmp_to_key(lambda x, y: compare(x, y, criteria)))
        for s in rs:
            print("  ",end='')
            print(*s,sep=',')
        print()