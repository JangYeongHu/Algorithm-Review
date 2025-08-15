for i in range(int(input())):
    a=input()
    b=int(''.join(reversed(a)))
    c=int(a)
    d=str(b+c)
    for i in range(len(d)//2):
        if d[i] != d[len(d)-1-i]:
            print("NO")
            break
    else:print("YES")