import pyarma as pa 
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

infile = open('ThingsVsTemp.txt', 'r')

Temp = []
E = []
M = []

for line in infile:
    words = line.split()
    T = float(words[0])
    e = float(words[1])
    m = float(words[2])
    Temp.append(T)
    E.append(e)
    M.append(m)

def beta(t):
    return(1/(t))
def ef(t):
    up = -2*np.sinh(8*beta(t))
    down = 3+np.cosh(8*beta(t))
    return(up/down)

A = np.zeros(100)

for i in range(100):
    A[i] = ef(Temp[i])

plt.plot(Temp,E)
plt.plot(Temp,A)
plt.show()