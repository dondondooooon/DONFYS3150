import pyarma as pa 
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

N = 4
# Analytical 
def beta(t):
    return(1/(t))
def ae(t):
    up = -2*np.sinh(8*beta(t))
    down = 3+np.cosh(8*beta(t))
    return(up/down)
def am(t):
    up = np.exp(8*beta(t)) + 2
    down = 2*(3+np.cosh(8*beta(t)))
    return(up/down)
def cap(t):
    x = np.cosh(8*beta(t))
    y = np.sinh(8*beta(t))
    term1 = N*beta(t)**2
    term2 = (4*x)/(3+x)
    term3 = ((-2*y)/(3+x))**2
    return term1*(term2-term3)
def xsup(t):
    ex = np.exp(8*beta(t))
    x = 3 + np.cosh(8*beta(t))
    term1 = (ex+1)/(2*x)
    term2 = ( (ex+2) / (2*x) )**2
    return N*beta(t)*(term1-term2)
# # Printout For T = 1
# print("Energy per Spin: ", ae(1))
# print("Magnetization per Spin: ", am(1))
# print("Heat Capacity per Spin: ", cap(1))
# print("Magnetic Suceptibility per Spin: ", xsup(1))
# Ae = np.zeros(100)
# Am = np.zeros(100)
# Acv = np.zeros(100)
# Ax = np.zeros(100)
# tmpf = [1000,10000,100000]
# for i in range(3):
#     infile = open(f'TempPlot{tmpf[i]}.txt', 'r')
#     T = []
#     E = []
#     M = []
#     # E2 = []
#     # M2 = []
#     CV = []
#     X = []
#     for line in infile:
#         words = line.split()
#         t = float(words[0])
#         e = float(words[1])
#         m = float(words[2])
#         # e2 = float(words[3])
#         # m2 = float(words[4])
#         cv = float(words[3])
#         x = float(words[4])
#         T.append(t)
#         E.append(e)
#         M.append(m)
#         #E2.append(e2)
#         #M2.append(m2)
#         CV.append(cv)
#         X.append(x)

#     for j in range(100):
#         Ae[j] = ae(T[j])
#         Am[j] = am(T[j])
#         Acv[j] = cap(T[j])
#         Ax[j] = xsup(T[j])

    # # Energy Per Spin
    # plt.plot(T,E,
    # if i==2:
    #     plt.plot(T,Ae, label="Analytical")
    # # Magnetization Per Spin
    # plt.plot(T,M, label=f"Num=1e{i+3}")
    # if i==2:
    #     plt.plot(T,Am, label="Analytical")
# # Energy Per Spin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$\epsilon$> [J]")
# plt.legend()
# # plt.savefig('epsVsT.pdf')
# plt.show()
# Magnetization Per Spin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$m$>")
# plt.legend()
# # plt.savefig('mVsT.pdf')
# plt.show()

# #plt.plot(T,CV, label="Numerical")
# plt.plot(T,Acv, label="Analytical")
# plt.xlabel("Temperature")
# plt.ylabel(r"$C_v$")
# plt.legend()
# plt.show()

# plt.plot(T,X, label="Numerical")
# plt.plot(T,Ax, label="Analytical")
# plt.xlabel("Temperature")
# plt.ylabel(r"$\chi$")
# plt.legend()
# plt.show()