import decimal

a, b = input().split()

a = int(a)
b = decimal.Decimal(b)
b *= 100

ans = a * b

ans //= 100

print(ans)