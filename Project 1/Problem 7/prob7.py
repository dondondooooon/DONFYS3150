import numpy as np
import matplotlib.pyplot as plt

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

for i in range(1,6): 
    N = 10**i                      # Iterate through the different N-values
    filename = f"prob7{N}.txt"     # Set name properly for text
    #print(filename) for checking purposes
    x,v,u = np.loadtxt(filename, usecols=(0,1,2), unpack=True)  # Unload correct text file
    plt.plot(x,v,label=f'N={N}')                                # Plot v_n(x) vs. x

#Plots numeric solution with different N values in the same plot
plt.title("Numeric Solutions w/ N-values", fontsize=10)
plt.xlabel("x")
plt.ylabel("v_n(x)")
plt.legend()
plt.savefig("Approx_Numeric_Solutions.pdf")
plt.show()

#Plots numeric vs exact solution in same plot for N=1000
filename = "prob71000.txt"
x,v,u = np.loadtxt(filename, usecols=(0,1,2), unpack=True)
plt.plot(x,v, label='Approx. Solution')
plt.plot(x,u, label='Exact Solution')
plt.xlabel("x")
plt.ylabel("u(x)")
plt.legend()
plt.savefig("Exact_vs._Approx.pdf")
plt.show()