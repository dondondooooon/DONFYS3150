import numpy as np
import matplotlib.pyplot as plt

# Figure size mod
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

for i in range(1,6): 
    N = 10**i                      # Iterate through the different N-values
    filename = f"prob9{N}.txt"     # Set name properly for text
    #print(filename) for checking purposes
    x,v,u = np.loadtxt(filename, usecols=(0,1,2), unpack=True)  # Unload correct text file
    v = np.roll(v,1)    # Shift once to the right to get end boundaries 0 
    plt.plot(x,v,'--',label=f'Numeric N={N}')    # Plot v_n(x) vs. x
    plt.plot(x,u,'-',label=f'Exact N={N}',c='black')      # Plot u_n(x) vs. x

#Plots numeric vs. exact solution with different N values in the same plot
plt.title("Numeric vs. Exact Solution", fontsize=10)
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.savefig("New_Num.vs.Exact_Ns.pdf")
plt.show()
