import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt
import math as m

# For Simulation 1: 
# # Unload data file
# data = []
# ofile = open("data_sim_1.txt", "r")
# for line in ofile.readlines():
#     data.append( complex( line ) )
# ofile.close()
# # Turn into a numpy array
# prob = np.array(data)
# # Data Process
# t = np.arange(0,0.008,0.000025)
# # Plot p^n_ij vs Time:
# plt.plot(t,prob.real)
# plt.xlabel("t")
# plt.ylabel(r"$p^n_{ij}$")
# # plt.savefig("sim1_prob.pdf")
# plt.show()
# # Plot Deviation from Probability
# normalize_data = (1-prob.real)*10**14 # only real part coz imaginary is 0s
# min_dev = np.min(normalize_data) # Smallest Deviation
# max_dev = np.max(normalize_data) # Largest Deviation
# print("Maximum Deviation from 1: ", max_dev)
# print("Minimum Deviation from 1: ", min_dev)
# print("Mean of Deviation from 1: ", np.mean(normalize_data))
# print("Standard Deviation from Deviation from 1: ", np.std(normalize_data))
# plt.plot(t,normalize_data)
# plt.ylim(min_dev-0.12,max_dev+0.15)
# plt.xlabel("t")
# plt.ylabel(r"1-$p^n_{ij}$")
# # plt.savefig("sim1_dev.pdf")
# plt.show()



# For Simulation 2:
# Unload data file
data = []
ofile = open("data_sim_2.txt", "r")
for line in ofile.readlines():
    data.append( complex( line ) )
ofile.close()

# Removed initial probability (??)
del data[0]

# Turn into a numpy array
prob = np.array(data)
# Data Process
# t = np.arange(0,0.008,0.000025) # From 0 to T
t = np.arange(0.0000025,0.008-0.000025,0.000025) # From dt to T
# Plot p^n_ij vs Time:
plt.plot(t,prob.real)
plt.xlabel("t")
plt.ylabel(r"$p^n_{ij}$")
# plt.savefig("sim2_prob_dt_to_T.pdf")
plt.show()
# Plot Deviation from Probability
normalize_data = (1-prob.real)*10**14 # only real part coz imaginary is 0s
min_dev = np.min(normalize_data) # Smallest Deviation
max_dev = np.max(normalize_data) # Largest Deviation
print("Maximum Deviation from 1: ", max_dev)
print("Minimum Deviation from 1: ", min_dev)
print("Mean of Deviation from 1: ", np.mean(normalize_data))
print("Standard Deviation from Deviation from 1: ", np.std(normalize_data))
plt.plot(t,normalize_data)
plt.ylim(min_dev-0.12,max_dev+0.16)
plt.xlabel("t")
plt.ylabel(r"1-$p^n_{ij}$")
# plt.savefig("sim2_dev_dt_to_T.pdf")
plt.show()



# # For Simulation 3
# # Unload data file
# data = []
# ofile = open("data_sim_3.txt", "r")
# for line in ofile.readlines():
#     data.append( complex( line ) )
# ofile.close()

# # Removed initial probability
# del data[0]
# del data[-1]

# # Turn into a numpy array
# prob = np.array(data)
# # Data Process
# t = np.arange(0.000025,0.002-0.000025,0.000025)
# # Plot p^n_ij vs Time:
# plt.plot(t,prob.real)
# plt.xlabel("t")
# plt.ylabel(r"$p^n_{ij}$")
# # plt.savefig("sim3_prob.pdf")
# plt.show()
# # Plot Deviation from Probability
# normalize_data = (1-prob.real)*10**14 # only real part coz imaginary is 0s
# min_dev = np.min(normalize_data) # Smallest Deviation
# max_dev = np.max(normalize_data) # Largest Deviation
# print("Maximum Deviation from 1: ", max_dev)
# print("Minimum Deviation from 1: ", min_dev)
# print("Mean of Deviation from 1: ", np.mean(normalize_data))
# print("Standard Deviation from Deviation from 1: ", np.std(normalize_data))
# plt.plot(t,normalize_data)
# # plt.ylim(min_dev-0.12,max_dev+0.16)
# plt.xlabel("t")
# plt.ylabel(r"1-$p^n_{ij}$")
# # plt.savefig("sim3_dev_dt_to_T.pdf")
# plt.show()