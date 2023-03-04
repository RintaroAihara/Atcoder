week = 1
Y = 2010
M = 1
D = 2

m1 = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m2 = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
ans = 0

while True:
    if D == 13:
        ans += 1
        print(ans)

    if ans == 666:
        print(Y, M, D)
        break
    if Y % 4 == 0:
        if D > m2[M-1]:
            D %= m2[M-1]
            M += 1
        if M == 13:
            Y += 1
            M = 1
    else:
        if D > m1[M-1]:
            D %= m1[M-1]
            M += 1
        if M == 13:
            Y += 1
            M = 1

    D += 7
