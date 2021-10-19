import pyarma as pa 
import numpy as np
import matplotlib.pyplot as plt

r = pa.mat()
v = pa.mat()
r.load("Rpos.bin")
v.load("Vhas.bin")

#r.load("Rpos_RK4.bin")
#v.load("Vhas_RK4.bin")

t = np.linspace(0,100,100)
print(r)
plt.plot(t,r[:,2])
plt.show()