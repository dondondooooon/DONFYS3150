import matplotlib.pyplot as plt
import numpy as np

# Plotting for L = 40, 60, 80, 100 Lattices

def beta(t):
    return(1/(t))
def cap_num(t,x,y):
    return beta(t)*beta(t)*(x-y)
def xsup_num(t,x,y):
    return beta(t)*(x-y)
def peak(x,l):
    maxi = np.amax(x)
    here = np.where(x==maxi)
    print(f"L={l}")
    print("Max: ", maxi)
    print("Temp at: ", T[int(here[0])])

# For VS. Temperature plots
Ae = np.zeros(10)
Am = np.zeros(10)
Acv = np.zeros(10)
Ax = np.zeros(10)
tmpf = [40,60,80,100]
for i in range(4):
    L = tmpf[i]
    N = L*L
    infile = open(f'zoomL={tmpf[i]}Cycle=500000.txt', 'r')
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

    # Choose which quantity to print out

    # # Energy Per Spin
    # plt.plot(T,E, label=f"L={tmpf[i]}")
    # peak(E, tmpf[i])
    # # Magnetization Per Spin
    # plt.plot(T,M, label=f"L={tmpf[i]}")
    # peak(M, tmpf[i])
    # # Specific Heat Capacity
    # plt.plot(T,CV, label=f"L={tmpf[i]}")
    # peak(CV, tmpf[i])
    # # Magnetic Susceptibility
    # plt.plot(T,X, label=f"L={tmpf[i]}")
    # peak(X, tmpf[i])

# Energy Per pin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$\epsilon$> [J]")
# plt.legend()
# # plt.savefig('Leps.pdf')
# plt.show()
# # Magnetization Per Spin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$m$>")
# plt.legend()
# # plt.savefig('Lm.pdf')
# plt.show()
# # Specific Heat Capacity
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"$C_v$")
# plt.legend()
# # plt.savefig('Lcv.pdf')
# plt.savefig('zoomLcv.pdf')
# plt.show()
# # Magnetic Susceptibility
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"$\chi$")
# plt.legend()
# # plt.savefig('Lx.pdf')
# # plt.savefig('zoomLx.pdf')
# plt.show()