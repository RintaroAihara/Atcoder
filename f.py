w = 40
h = 40
l = []
l1 = []
a = 0

for i in range(20):
    H = (20-i)*2
    l.append(a)
    a += (H-1)+(H-1)
    l1.append(a)
    a += (H-1)+(H-1)


for i in l:
    print(chr(65+(i % 26)), end="")

for i in range(len(l1)):
    print(chr(65+(l1[len(l1)-i-1] % 26)), end="")
