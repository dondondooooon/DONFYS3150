import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt



N_1 = 9
N_2 = 100
B = pa.mat() #Create pa.mat object (just as arma::mat in C++)
C = pa.mat() #Create pa.mat object (just as arma::mat in C++)
B.load('jarovec.bin')
C.load('jarovec-new.bin')

xx = np.linspace(0,1,N_2)
x = np.linspace(0,1,N_1)


plt.plot(xx,C[0,:], label=f'Jacobi[0]')
plt.plot(xx,C[4,:], label=f'Jacobi [1]')
plt.plot(xx,C[6,:], label=f'Jacobi [2]')
# plt.plot(x,B[0,:], label=f'Jacobi[0]')
# plt.plot(x,B[4,:], label=f'Jacobi [1]')
# plt.plot(x,B[6,:], label=f'Jacobi [2]')
plt.xlabel("horizontal position of the beam x$_i$")
plt.ylabel("vertical displacement of the beam v$_i$")
plt.legend()
plt.show()
