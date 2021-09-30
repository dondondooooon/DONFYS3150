import numpy as np
import matplotlib.pyplot as plt

# Unload text file
x,y = np.loadtxt('prob2.txt', usecols=(0,1), unpack=True)

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

# Plot x vs. y (u(x))
plt.plot(x,y, label='Exact Solution')
plt.xlabel('x')
plt.ylabel('u(x)')
plt.legend()
plt.savefig('Exact_Solution_plot.pdf')
plt.show()