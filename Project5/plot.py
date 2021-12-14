import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt
import matplotlib

#
# For Simulation 1 & 2: 
#
def plot_sim(sim):
    data = []
    # Unload data file
    ofile = open(f"data_files/data_sim_{sim}.txt", r)
    for line in ofile.readlines():
        data.append( complex( line ) )
    ofile.close()
    # Turn into a numpy array
    prob = np.array(data)
    t = np.arange(0,0.008,0.000025) # From 0 to T
    # Plot p^n_total vs Time:
    plt.plot(t,prob.real) # only real part coz imaginary is 0s
    plt.xlabel("t")
    plt.ylabel(r"$p^n_{total}$")
    plt.savefig(f"plot_figures/sim{sim}_prob.pdf")
    plt.show()
    # Plot Deviation from Probability
    dev_data = (1-prob.real) # only real part coz imaginary is 0s
    min_dev = np.min(dev_data) # Smallest Deviation
    max_dev = np.max(dev_data) # Largest Deviation
    print("Maximum Deviation from 1: ", max_dev)
    print("Minimum Deviation from 1: ", min_dev)
    print("Mean of Deviation from 1: ", np.mean(dev_data))
    print("Standard Deviation from Deviation from 1: ", np.std(dev_data))
    plt.plot(t,dev_data)
    plt.xlabel("t")
    plt.ylabel(r"$1-p^n_{total}$")
    plt.ylim((min_dev-1)*1e-14,(max_dev+1)*1e-14)
    plt.savefig(f"plot_figures/sim{sim}_dev.pdf")
    plt.show()
# Choose Simulation to Plot
# sim1 = 1
# sim2 = 2
# plot_sim(sim1)
# plot_sim(sim2)


# # Initialize Containers
# Vbin = pa.cx_cube()
# # Load Cube Matrix
# Vbin.load("bin_files/Simulation3_V.bin") 
# V = np.array( Vbin )
# # Write to file
# ofile = open(f"data_files/Simulation3_V.txt", "w")
# Vmat = np.matrix( V )
# print(np.size(V))
# for line in Vmat:
#     np.savetxt(ofile, line) #, fmt='%1.3f')
# # Initialize Containers
# Vv = np.zeros([100,100],float)
# data_strList = []
# # Unload data file
# file = open("data_files/Simulation3_V.txt", "r")
# for line in file: # Append list of strings column values by the rows 
#     words = line.split()
#     data_strList.append(words)
# for i in range(100): # Loop thru the list of strings
#     for j in range(100):
#         v_ij = float( data_strList[i][j] ) # make to float
#         Vv[i,j] = v_ij # Add into np.array




#
# For Simulation 3
#
def Matrix(Sname,k):
    # Initialize Containers
    S = np.zeros([100,100],float)
    data_strList = []
    # Unload data file
    ofile = open("data_files/" + Sname + f"_t={k}.txt", "r")
    for line in ofile: # Append list of strings column values by the rows 
        words = line.split()
        data_strList.append(words)
    for i in range(100): # Loop thru the list of strings
        for j in range(100):
            s_ij = float( data_strList[i][j] ) # make to float
            S[i,j] = s_ij # Add into np.array
    return(S)
# Get time = 0, 0.001, 0.002
# timeslices = np.array( [0,1,2,3,4,5,6,7,8,9,10,39,59,69,75,78,79] ) 
timeslices = np.arange(0,80,1)
print(timeslices)
for k in timeslices:
    # Get the matrices
    Sprob = Matrix('Sprob',k)
    Sreal = Matrix('Sreal',k)
    Simag = Matrix('Simag',k)
    # Set up MeshGrid
    M = 100
    h = 0.005
    xpoints = np.arange(0,(M+1)*h,h) 
    ypoints = xpoints
    x,y = np.meshgrid(xpoints,ypoints,sparse=True)
    # Plot

    # norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(Sprob))

    plt.pcolormesh(x,y,np.sqrt(Sprob) )
    # plt.pcolormesh(x,y,Vv )
    plt.colorbar()
    plt.show()
    