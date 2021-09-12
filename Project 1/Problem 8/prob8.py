import numpy as np
import matplotlib.pyplot as plt

# Initialization
n = np.arange(1,8)
eps_max = np.arange(1,len(n)+2)

# Figure size mod
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

# For loop k for plots
for k in range(2):
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
        #print(i,"  ",filename, "   ", v[0] , " space! " , u[-1], "\n")     

        #Compute Arrays for absolute error
        delta = np.absolute(v-u)

        # Log10(Absolute Error)
        if k==0:
            log10abserr = np.log10(delta)

            # Plot x vs. log10absolute error
            plt.plot(x,log10abserr,'--',label=f'N={N}')
        
        # Log10(Relative Error)
        else:
            epsilon = np.absolute(delta/u)
            log10relerr = np.log10(epsilon)

            # Get the maximum relative error
            #eps_max[i] = np.max(epsilon)
            eps_max[i] = np.max(log10relerr)    # with logs

            # Plot x vs. log10relative_error
            plt.plot(x,log10relerr,'--',label=f'N={N}')    
    
    name = [r'$log_{10}(\Delta_{i})$',r'$log_{10}(\epsilon_{i})$']
    tittel = [r'Log10 of Absolute Error vs. $x_{i}$',r'Log10 of Relative Error vs. $x_{i}$']
    savename = ['logAbsError_plot.pdf','logRelError_plot.pdf']
    plt.xlabel('x')
    plt.ylabel(name[k])
    plt.title(tittel[k], fontsize=10)
    plt.legend(loc='upper right')
    plt.savefig(savename[k])
    plt.show()

if k==1:
    # Fix Max. Epsilon Array
    eps_max = np.delete(eps_max,[0], None)
    print('The Maximum Relative Error for each n is: ', eps_max)

    # Plot Max. Relative Error vs. N
    plt.plot(n,eps_max,'o')
    plt.xlabel('N')
    plt.ylabel(r'$\epsilon_{i}$')
    plt.xticks(np.arange(1,len(n)+1))
    plt.title(r'Max. $\epsilon_{i}$ vs. N', fontsize=10)
    plt.savefig("Max_Relative_Error.pdf")
    plt.show()