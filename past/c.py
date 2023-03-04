a, r, n = map(int, input().split())

ans = a * pow(r, n - 1)

if ans >= 1000000000:
    print("large")
else:
    print(ans)