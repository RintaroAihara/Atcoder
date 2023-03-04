import matplotlib.pyplot as plt
import numpy as np
import math


def calc_cost(p: int, s: int, c):
    cost = ((s+p-1)//(p)) * (p+c)
    return cost


def mean_cost(p, c):
    s = 0
    for i in range(1, 5000+1):
        s += calc_cost(p, i, c)

    s /= 5000
    return s


def calc_min(x):
    c = x

    return np.argmin([mean_cost(p, c)
                      for p in range(1, 5001)])


plt.plot([i for i in range(5000)], [math.exp((99-i)/2500)
         for i in range(5000)])
plt.show()
