import matplotlib.pyplot as plt
import numpy as np

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
# Numerical Specific Heat Capacity & Magnetic Susceptibility
def cap_num(t,x,y):
    return beta(t)*beta(t)*(x-y)
def xsup_num(t,x,y):
    return beta(t)*(x-y)
# Temperature & Analytical
def analytical():
    infile = open('TempPlot1000.txt','r')
    for line in infile:
        words = line.split()
        T.append(float(words[0]))
    for j in range(100):
        Ae[j] = ae(T[j])
        Am[j] = am(T[j])
        Acv[j] = cap(T[j])
        Ax[j] = xsup(T[j])
    infile.close()
# Export Data for Physical Conditions
def readup(temptemp):
    infile = open(f'TempPlot{temptemp}.txt', 'r')
    Eq = []
    Mq = []
    E2q = []
    M2q = []
    CVq = []
    Xq = []
    for line in infile:
        words = line.split()
        t = float(words[0])
        e = float(words[1])
        m = float(words[2])
        e2 = float(words[3])
        m2 = float(words[4])
        Eq.append(e)
        Mq.append(m)
        E2q.append(e2)
        M2q.append(m2)
        CVq.append(cap_num(t,e2,e*e))
        Xq.append(xsup_num(t,m2,m*m))
    Eq = np.array(Eq)/N
    Mq = np.array(Mq)/N
    CVq = np.array(CVq)/N
    Xq = np.array(Xq)/N
    infile.close()
    return Eq,Mq,CVq,Xq
def relerr(num,teo):
    return (teo-num)/teo
def avg(x):
    return np.average(x)
def unc(x):
    return (np.amax(x)-np.amin(x))/2

# Initialize
N = 4
T = []
Ae = np.zeros(100)
Am = np.zeros(100)
Acv = np.zeros(100)
Ax = np.zeros(100)
analytical()

#Remove First 40 points
indeks = range(0,40)
T = np.delete(T,indeks)
Ae = np.delete(Ae,indeks)
Am = np.delete(Am,indeks)
Acv = np.delete(Acv,indeks)
Ax = np.delete(Ax,indeks)

tmpf = [1000,10000,100000,1000000,10000000]

# # For Print out of Values
# for i in range(5):
#     E,M,CV,X = readup(tmpf[i])
    
#     #Remove First 40 points
#     indeks = range(0,40)
#     E = np.delete(E,indeks)
#     M = np.delete(M,indeks)
#     CV= np.delete(CV,indeks)
#     X = np.delete(X,indeks)
    
#     rE = relerr(E,Ae)
#     rM = relerr(M,Am)
#     rCV = relerr(CV,Acv)
#     rX = relerr(X,Ax)
#     print(" ")
#     print("Monte Carlo Cycles:" , tmpf[i])
#     print(r"Relative Error for <$\epsilon$>: ", avg(rE), r"+-", unc(rE))
#     print(r"Relative Error for <$m$>: ", avg(rM), r"+-", unc(rM))
#     print(r"Relative Error for $C_v$: ", avg(rCV), r"+-", unc(rCV))
#     print(r"Relative Error for $\chi$: ", avg(rX), r"+-", unc(rX))
#     print(" ")

# For Plots
for i in range(5):
    E,M,CV,X = readup(tmpf[i])
    
    #Remove First 40 points
    indeks = range(0,40)
    E = np.delete(E,indeks)
    M = np.delete(M,indeks)
    CV= np.delete(CV,indeks)
    X = np.delete(X,indeks)
    
    rE = relerr(E,Ae)
    rM = relerr(M,Am)
    rCV = relerr(CV,Acv)
    rX = relerr(X,Ax)
    
    # Energy per Spin
    plt.plot(T,E, label=f"Num=1e{i+3}")
    plt.plot(T,Ae, label="Analytical")
    plt.plot(T,rE, label="Relative Error")
    plt.xlabel(r"T [ J/$k_b$ ]")
    plt.ylabel(r"<$\epsilon$> [J]")
    plt.legend()
    plt.savefig(f'e_relerr_cycle_{tmpf[i]}_1e{i+3}.pdf')
    plt.show()
    
    # Magnetization Per Spin
    plt.plot(T,M, label=f"Num=1e{i+3}")
    plt.plot(T,Am, label="Analytical")
    plt.plot(T,rM, label="Relative Error")
    plt.xlabel(r"T [ J/$k_b$ ]")
    plt.ylabel(r"<$m$>")
    plt.legend()
    plt.savefig(f'm_relerr_cycle_{tmpf[i]}_1e{i+3}.pdf')
    plt.show()
    
    # Specific Heat Capacity
    plt.plot(T,CV, label=f"Num=1e{i+3}")
    plt.plot(T,Acv, label="Analytical")
    plt.plot(T,rCV, label="Relative Error")
    plt.xlabel(r"T [ J/$k_b$ ]")
    plt.ylabel(r"$C_v$ [ J/K ]")
    plt.legend()
    plt.savefig(f'cv_relerr_cycle_{tmpf[i]}_1e{i+3}.pdf')
    plt.show()
    
    # Magnetic Susceptibility
    plt.plot(T,X, label=f"Num=1e{i+3}")
    plt.plot(T,Ax, label="Analytical")
    plt.plot(T,rX, label="Relative Error")
    plt.xlabel(r"T [ J/$k_b$ ]")
    plt.ylabel(r"$\chi$")
    plt.legend()
    plt.savefig(f'x_relerr_cycle_{tmpf[i]}_1e{i+3}.pdf')
    plt.show()


