import numpy as np
import matplotlib.pyplot as plt

# Initialization
n = np.arange(1,5)
eps_max = np.arange(1,len(n)+2)

# Initialize subplots
fig, (ax1,ax2) = plt.subplots(2)

# Loop through n
for i in range(1,len(n)+1):         
    # Unload correct .txt file
    N = 10**i    
    filename = f"prob8{N}.txt"
    x,v,u = np.loadtxt(filename, usecols=(0,1,2), unpack=True)  

    # Remove borders initial and end 
    x = np.delete(x, [0,-1], None)
    v = np.delete(v, [-1,-2], None)    # The boundarie values 0 are still at -1 and -2 index
    u = np.delete(u, [0,-1], None)
    #x = np.log10(x)                   #logify x values
    
     #Checking purposes
    print(i,"  ",filename, "   ", v[0] , " space! " , u[-1], "\n")     

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
    
ax1.set(xlabel="x", ylabel=r'$log_{10}(\Delta_{i})$')
ax2.set(xlabel="x", ylabel=r'$log_{10}(\epsilon_{i})$')
#ax3.set(xlabel="x", ylabel=r'$\epsilon_{i})$')
ax1.legend(loc='center left', bbox_to_anchor=(0.85,1))
#plt.savefig("Error_Plots.pdf")
plt.show()

# Fix max. epsilon array
eps_max = np.delete(eps_max,[0], None)
print('The Maximum Relative Error for each n is: ', eps_max)

plt.plot(n,eps_max,'o')
plt.title(r'max $\epsilon_{i}$ vs. n', fontsize=10)
plt.xticks(np.arange(1,len(n)+1))
plt.xlabel('n')
plt.ylabel(r'$\epsilon_{i}$')
#plt.savefig("Max_Relative_Error.pdf")
plt.show()