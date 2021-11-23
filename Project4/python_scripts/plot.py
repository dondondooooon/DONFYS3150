import matplotlib.pyplot as plt
import numpy as np

L = 2 # 20
N = L*L
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
def cap_num(t,x,y):
    return beta(t)*beta(t)*(x-y)
def xsup_num(t,x,y):
    return beta(t)*(x-y)

# 1. Printout for T = 1

# cycles = 1000000 #100000 10000 1000
# infile = open(f'T=1_printout{cycles}.txt', 'r')
# for line in infile:
#     words = line.split()
#     e = float(words[1])
#     m = float(words[2])
#     e2 = float(words[3])
#     m2 = float(words[4])
# e = np.array(e)
# m = np.array(m)
# print()
# print("Numerical:")
# print("Monte Carlo cycles: ", cycles)
# print("Energy per Spin: ", e/N)
# print("Magnetization per Spin: ", m/N)
# print("Heat Capacity per Spin: ", cap_num(1,e2,e*e)/N)
# print("Magnetic Suceptibility per Spin: ", xsup_num(1,m2,m*m)/N)
# print()
# print("Analytical:")
# print("Energy per Spin: ", ae(1))
# print("Magnetization per Spin: ", am(1))
# print("Heat Capacity per Spin: ", cap(1))
# print("Magnetic Suceptibility per Spin: ", xsup(1))
# print()

# 2. For VS. Temperature plots

# Ae = np.zeros(100)
# Am = np.zeros(100)
# Acv = np.zeros(100)
# Ax = np.zeros(100)
# tmpf = [1000,10000,100000,1000000,10000000]
# for i in range(5):
#     infile = open(f'TempPlot{tmpf[i]}.txt', 'r')
#     T = []
#     E = []
#     M = []
#     E2 = []
#     M2 = []
#     CV = []
#     X = []
#     for line in infile:
#         words = line.split()
#         t = float(words[0])
#         e = float(words[1])
#         m = float(words[2])
#         e2 = float(words[3])
#         m2 = float(words[4])
#         T.append(t)
#         E.append(e)
#         M.append(m)
#         E2.append(e2)
#         M2.append(m2)
#         CV.append(cap_num(t,e2,e*e))
#         X.append(xsup_num(t,m2,m*m))
#     E = np.array(E)/N
#     M = np.array(M)/N
#     CV = np.array(CV)/N
#     X = np.array(X)/N
#     for j in range(100):
#         Ae[j] = ae(T[j])
#         Am[j] = am(T[j])
#         Acv[j] = cap(T[j])
#         Ax[j] = xsup(T[j])
#
# # Choose Physical Quantity to Plot and uncomment accordingly
#
#    # Energy Per Spin
#    plt.plot(T,E, label=f"Num=1e{i+3}")
#    if i==4:
#        plt.plot(T,Ae, label="Analytical")
#     # Magnetization Per Spin
#     plt.plot(T,M, label=f"Num=1e{i+3}")
#     if i==4:
#         plt.plot(T,Am, label="Analytical")
#     # Specific Heat Capacity
#     plt.plot(T,CV, label=f"Num=1e{i+3}")
#     if i==4:
#         plt.plot(T,Acv, label="Analytical")
#     # Magnetic Susceptibility
#     plt.plot(T,X, label=f"Num=1e{i+3}")
#     if i==4:
#        plt.plot(T,Ax, label="Analytical")
# # Energy Per Spin
# plt.xlabel(r"T [ J/$k_b$ ]")
# plt.ylabel(r"<$\epsilon$> [J]")
# plt.legend()
# # plt.savefig('epsVsT.pdf')
# plt.show()
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

# 3. For epsilon and magnetization VS. Monte Carlo cycles plots

# N = 20*20
# l = [1,2.4]
# for i in range(2):
#     infile1 = open(f'cycle_ordered{l[i]}.txt', 'r')
#     infile2 = open(f'cycle_unordered{l[i]}.txt', 'r')
#     cycle = []
#     E = []
#     M = []
#     cycle2 = []
#     E2 = []
#     M2 = []
#     for line in infile1:
#         words = line.split()
#         cyc = float(words[0])
#         e = float(words[1])
#         m = float(words[2])
#         cycle.append(cyc)
#         E.append(e)
#         M.append(m)
#     for line in infile2:
#         words = line.split()
#         cyc = float(words[0])
#         e = float(words[1])
#         m = float(words[2])
#         cycle2.append(cyc)
#         E2.append(e)
#         M2.append(m)
#     # Per spin
#     E = np.array(E)/N
#     M = np.array(M)/N
#     E2 = np.array(E2)/N 
#     M2 = np.array(M2)/N
#     # Energy Per Spin
#     plt.plot(cycle,E, label=f"T={l[i]} : Ordered")
#     plt.plot(cycle2,E2, label=f"T={l[i]} : Unordered")
#     plt.xlabel("MC Cycles")
#     plt.ylabel(r"$\epsilon$")
#     # Uncomment if statements if zoomed
#     if i==0:
#         plt.ylim(-1.999,-1.995)
#     elif i==1:
#         plt.ylim(-1.1575,-1.3550)
#     plt.legend()
#     # plt.savefig(f"T={l[i]}cyclesE.pdf")
#     # plt.savefig(f"ZOOM_T={l[i]}cyclesE.pdf")
#     plt.show()
#     # Magnetization Per Spin
#     plt.plot(cycle,M, label=f"T={l[i]} : Ordered")
#     plt.plot(cycle2,M2, label=f"T={l[i]} : Unordered")
#     plt.xlabel("MC Cycles")
#     plt.ylabel(r"$m$")
#     if i==0:
#         plt.ylim(0.998,1.001)
#     elif i==1:
#         plt.ylim(0.20,0.6)
#     plt.legend()
#     # plt.savefig(f"T={l[i]}cyclesM.pdf")
#     # plt.savefig(f"ZOOM_T={l[i]}cyclesM.pdf")
#     plt.show()

# 4. For Histogram plot

# tmpf = [1000,10000,100000]
# for i in range(1):
#     infile = open(f'TempPlot{tmpf[i]}.txt', 'r')
#     E = []
#     for line in infile:
#         words = line.split()
#         e = float(words[0])
#         E.append(e)
#     E = np.array(E)/N
# results, edges = np.histogram(E, normed=True)
# binWidth = edges[1] - edges[0]
# plt.grid(axis='y', alpha=0.75)
# plt.bar(edges[:-1], results*binWidth, binWidth,color=(0.0, 0.75, 1.0),edgecolor='black')
# plt.xlabel('Energy[J]')
# plt.ylabel('P(E)')
# plt.text(23, 45, r'$\mu=15, b=3$')
# plt.savefig('Prob2-4.pdf')
# plt.show()
