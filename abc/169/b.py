n = int(input())

a = list(map(int,input().split()))

ans = 1

for i in range(n):
   if a[i] == 0:
        print(0)
        exit()

for i in range(n):
    ans *= a[i]
    if ans > 1e18:
        print(-1)
        exit()

print(ans)