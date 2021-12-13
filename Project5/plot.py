import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt
import math as m

#
# For Simulation 1 & 2: 
#
# data = []
# # Unload data file

# # ofile = open("data_files/data_sim_1.txt", "r")
# # ofile = open("data_files/data_sim_2.txt", "r")

# for line in ofile.readlines():
#     data.append( complex( line ) )
# ofile.close()
# # Turn into a numpy array + normalize to 10^15
# prob = np.array(data)*1e15
# # Data Process
# t = np.arange(0,0.008,0.000025) # From 0 to T
# # Plot p^n_ij vs Time:
# plt.plot(t,prob.real) # only real part coz imaginary is 0s
# plt.xlabel("t [time]")
# plt.ylabel(r"$p^n_{ij}$ [$10^{15}$]")

# # plt.savefig("plot_figures/sim1_prob.pdf")
# # plt.savefig("plot_figures/sim2_prob.pdf")

# plt.show()
# # Plot Deviation from Probability
# dev_data = (1*1e15-prob.real) # only real part coz imaginary is 0s
# min_dev = np.min(dev_data) # Smallest Deviation
# max_dev = np.max(dev_data) # Largest Deviation
# print("Maximum Deviation from 1: ", max_dev)
# print("Minimum Deviation from 1: ", min_dev)
# print("Mean of Deviation from 1: ", np.mean(dev_data))
# print("Standard Deviation from Deviation from 1: ", np.std(dev_data))
# plt.plot(t,dev_data)
# plt.ylim(min_dev-.2,max_dev+.5)
# plt.xlabel("t [time]")
# plt.ylabel(r"1-$p^n_{ij}$ [$10^{15}$]")

# # plt.savefig("plot_figures/sim1_dev.pdf")
# # plt.savefig("plot_figures/sim2_dev.pdf")

# plt.show()

 probfile = open(f"data_files/Sprob_t={k}.txt", "w")
    realfile = open(f"data_files/Sreal_t={k}.txt", "w")
    imagfile = open(f"data_files/Simag_t={k}.txt", "w")

#
# For Simulation 3
#
# Unload data file
timeslices = np.array( [0,39,79] ) # get time = 0, 0.001, 0.002
for k in timeslices:
    data_prob = []
    data_real = []
    data_imag = []
    probfile = open(f"data_files/Sprob_t={k}.txt, "r")
    realfile = open(f"data_files/Sreal_t={k}.txt", "r")
    imagfile = open(f"data_files/Simag_t={k}.txt", "r")

    # put into lists
    for # smthing smthing from file readlines smthing...
        data_prob.append()
        data_real.append()
        data_imag.append()

    # turn lists to array (2D array=?)
    dp = np.array( data_prob )
    dr = np.array( data_real ) 
    di = np.array( data_imag ) 

    #... onwards for 2D meshgrid thing idk