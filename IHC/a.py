import matplotlib.pyplot as plt
import numpy as np

T0 = 1e6
T1 = 5e3

x = np.linspace(0, 1, 1000)
T = T0 ** (1 - x) * T1 ** x

plt.plot(x, T)
plt.show()