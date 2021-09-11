import numpy as np
import matplotlib.pyplot as plt

eps_max = np.zeros(8,float)

fig, (ax1,ax2,ax3) = plt.subplots(3)
#for ax in fig.get_axes():
#    ax.label_outer()

# Loop through 0-7
for i in range(1,8):         
    # Iterate through N and find correct .txt file
    N = 10**i    
    filename = f"prob8{N}.txt"
    x,v,u = np.loadtxt(filename, usecols=(0,1,2), unpack=True)   # Unload correct text file 

    # Remove borders initial and end because they're equal to 0? it weird points
    x = np.delete(x, [0,-1], None)
    v = np.delete(v, [0,-1], None)
    u = np.delete(u, [0,-1], None)
    #x = np.log10(x)                     #logify x values
    print(i,"  ",filename, "   ", v[0] , " space! " , u[-1], "\n")      #Checking purposes

    #Compute Arrays for absolute and relative error, and log10 of them
    delta = np.absolute(v-u)
    epsilon = np.absolute(delta/u)
    log10abserr = np.log10(delta)
    log10relerr = np.log10(epsilon)

    # Get the maximum relative error
    eps_max[i] = np.max(epsilon)

    # Plot log10errors as a function of x_i
    ax1.plot(x,log10abserr,label=f'N={N}')
    ax2.plot(x,log10relerr,label=f'N={N}')
    ax3.plot(x,epsilon,label=f'N={N}')
    
print(eps_max)
ax1.set(xlabel="x", ylabel=r'$log_{10}(\Delta_{i})$')
ax2.set(xlabel="x", ylabel=r'$log_{10}(\epsilon_{i})$')
ax3.set(xlabel="x", ylabel=r'$\epsilon_{i})$')
plt.legend()
#plt.savefig("Error Plots.pdf")
plt.show()