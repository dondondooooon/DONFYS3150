import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt

#
# For Simulation 1 and 2 (Before Problem 8)
#
# # Initialize Containers
# S = pa.cx_cube()
# sums = []
# # Load Cube Matrix

# # sim = 1 
# # sim = 2

# S.load(f"bin_files/Grid_Simulation{sim}.bin") # Unload Simulation bin
# print(S)
# Sconj = pa.conj(S) # complex conjugate of each element in S
# Sprob = S@Sconj # S element-wise multiplied by conjugate of S
# # Perform Data Processing
# for k in range(S.n_slices): # For all time slices
#     sum = 0 + 0j
#     for i in range(1,S.n_cols-1,1): # Inner Matrix
#         for j in range(1,S.n_rows-1,1):
#             sum += Sprob[i,j,k] # Sum up probability in 1 time slice
#     sums.append( sum ) # append to list
# # Write to file

# # ofile = open("data_files/data_sim_1.txt", "w") # Comment out accordingly
# # ofile = open("data_files/data_sim_2.txt", "w") # Comment out accordingly

# for line in sums:
#     ofile.write(str(line))
#     ofile.write("\n")
# ofile.close()


#
# For Simulation 3
#
# Initialize Containers
S = pa.cx_cube()
# Load Cube Matrix
S.load("bin_files/Grid_Simulation3.bin") 
Sconj = pa.conj(S)
Sprob = S@Sconj
relS = np.array( pa.real(S) )
imgS = np.array( pa.imag(S) )
prob = np.array( pa.real(Sprob) ) # Since imaginary is 0s
# Write to file
# timeslice = np.array( [0, 1,2,3,4,5,6,7,8,9,10,39, 59, 69, 75, 78, 79] ) # get time = 0, 0.001, 0.002
timeslice = np.arange(0,80,1)
for k in timeslice:
    probfile = open(f"data_files/Sprob_t={k}.txt", "w")
    realfile = open(f"data_files/Sreal_t={k}.txt", "w")
    imagfile = open(f"data_files/Simag_t={k}.txt", "w")
    probmat = np.matrix( prob[k,:,:] )
    realmat = np.matrix( relS[k,:,:] )
    imagmat = np.matrix( imgS[k,:,:] )
    for line in probmat:
        np.savetxt(probfile, line) #, fmt='%1.3f')
    for line in realmat:
        np.savetxt(realfile, line) #, fmt='%1.3f')
    for line in imagmat:
        np.savetxt(imagfile, line) #, fmt='%1.3f')











# Sum of Elements in a Matrix Check in a Time Slice
# sum = 0 + 0j
# for k in range(1):
#     for i in range(S.n_cols):
#         for j in range(S.n_rows):
#             sum += Sprob[i,j,k+101]
#     a.append(sum)
# print(sum)

# Elements in a Matrix Check in a Time Slice
# for k in range(1):
#     for i in range(S.n_cols):
#         for j in range(S.n_rows):
#             print(S[i,j,k+5])

# How a 3D matrix looks in numpy
# np.array(       [ [ [1, 2, 3], 
#                     [4, 5, 6]     ], 
                
#                 [   [7, 8, 9], 
#                     [10, 11, 12]  ]       ]    )
# a[slice,row,column]