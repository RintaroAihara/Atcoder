import collections

n = int(input())


def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


x = 1

for i in range(1, n+1):
    x *= i

p = collections.Counter(prime_factorize(x))

q = list(p.values())
ans = 0

ans += sum(1 for i in q if i >= 74)

for i in range(len(q)):
    for j in range(len(q)):
        if i == j:
            continue
        if q[i] >= 4 and q[j] >= 14:
            ans += 1
        if q[i] >= 2 and q[j] >= 24:
            ans += 1

for i in range(len(q)):
    for j in range(i + 1, len(q)):
        for k in range(len(q)):
            if i == k or j == k:
                continue
            if q[i] >= 4 and q[j] >= 4 and q[k] >= 2:
                ans += 1

print(ans)
