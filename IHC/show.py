import matplotlib.pyplot as plt
import numpy as np

path = 'test.txt'

score = []

f = open(path)

with open(path) as f:
    for s_line in f:
        score.append(int(s_line))

f.close()
n=26**4
x = [i for i in range(n)]
score = score[0:n]

plt.plot(x, score, lw=1)

plt.show()
