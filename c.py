
ans = ""
for i in range(26):
    for _ in range(i+1):
        ans += chr(ord("A")+i)


for i in range(len(ans)):
    if i % 16 == 0:
        print(ans[i], end="")

print()
