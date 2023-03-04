ans = 0

for i in range(1, 4116):
    x = (i-1)*3+1
    ans += x*(x+1)/(x+2)

print(ans)
