from matplotlib import lines
import pyarma as pa 
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

def beta(t):
    return(1/(t))
def cap_num(t,x,y):
    return beta(t)*beta(t)*(x-y)
def xsup_num(t,x,y):
    return beta(t)*(x-y)

L = 40
N = L*L

# For VS. Temperature plots
tmpf = [1000,10000,100000,1000000,10000000,500000]
for i in range(1):
    # infile = open(f'TempPlot{tmpf[1]}.txt','r')
    #infile = open(f'L={L}Cycle={tmpf[5]}.txt', 'r')
    infile = open(f'L={L}Cycle=500000.txt', 'r')
    T = []
    E = []
    M = []
    E2 = []
    M2 = []
    CV = []
    X = []
    for line in infile:
        words = line.split()
        t = float(words[0])
        e = float(words[1])
        m = float(words[2])
        e2 = float(words[3])
        m2 = float(words[4])
        T.append(t)
        E.append(e)
        M.append(m)
        E2.append(e2)
        M2.append(m2)
        CV.append(cap_num(t,e2,e*e))
        X.append(xsup_num(t,m2,m*m))
    E = np.array(E)/N
    M = np.array(M)/N
    CV = np.array(CV)/N
    X = np.array(X)/N
    # print(T)
    
    # bongk = np.zeros((len(E),len(E)))
    # bongk[0][:] = T
    # bongk[1][:] = E
    # bongk[2][:] = M
    # bongk[3][:] = CV
    # bongk[4][:] = X

    # tordered = np.sort(T)
    # np.array(T)
    # np.array(tordered)
    # print(tordered)
    # ordre = (T==tordered)
    # # print("What this: ", type(ordre))
    # k = 0
    # while k<10:
    #     for i in range(9):
    #         if T[i] > T[i+1]:
    #             low = T[i+1]
    #             high = T[i]
    #             T[i] = low
    #             T[i+1] = high

    #             low = E[i+1]
    #             high = E[i]
    #             E[i] = low
    #             E[i+1] = high

    #             low = M[i+1]
    #             high = M[i]
    #             M[i] = low
    #             M[i+1] = high

    #             low = CV[i+1]
    #             high = CV[i]
    #             CV[i] = low
    #             CV[i+1] = high

    #             low = X[i+1]
    #             high = X[i]
    #             X[i] = low
    #             X[i+1] = high
    #     print("update: ", T)
    #     # ordre = (T==tordered)
    #     k += 1

    # Energy Per Spin
    # plt.plot(T,E, label=f"Num=1e{i+2}")
#    if i==1:
#        plt.plot(T,Ae, label="Analytical")
#     # Magnetization Per Spin
#     plt.plot(T,M, label=f"Num=1e{i+3}")
#     if i==2:
#         plt.plot(T,Am, label="Analytical")
#     # Specific Heat Capacity
    plt.plot(T,CV, label=f"Num=1e{i+3}")
#     if i==2:
#         plt.plot(T,Acv, label="Analytical")
#     # Magnetic Susceptibility
#     plt.plot(T,X, label=f"Num=1e{i+3}")
#     if i==2:
#        plt.plot(T,Ax, label="Analytical")





# # Energy Per Spin
plt.xlabel(r"T [ J/$k_b$ ]")
plt.ylabel(r"<$\epsilon$> [J]")
plt.legend()
# plt.savefig('epsVsT.pdf')
plt.show()
maxi = np.amax(CV)
here = np.where(CV==maxi)
print("max cv: ", maxi)
print("temp at: ", T[int(here[0])])
# # Magnetization Per Spin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$m$>")
# plt.legend()
# # plt.savefig('mVsT.pdf')
# plt.show()
# # Specific Heat Capacity
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"$C_v$")
# plt.legend()
# # plt.savefig('cvVsT.pdf')
# plt.show()
# # Magnetic Susceptibility
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"$\chi$")
# plt.legend()
# # plt.savefig('xVsT.pdf')
# plt.show()