import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt

# For Simulation 1 and 2 (Before Problem 8)
# Initialize Containers
S = pa.cx_cube()
Sconj = pa.cx_cube()
sums = []
# Load Cube Matrix 
# S.load("Grid_Simulation2.bin") # Change name according to simulation
Sconj = pa.conj(S) # complex conjugate of each element in S
Sprob = S@Sconj # S element-wise multiplied by conjugate of S
# Perform Data Processing
for k in range(S.n_slices):
    sum = 0 + 0j
    for i in range(S.n_cols):
        for j in range(S.n_rows):
            sum += Sprob[i,j,k] # Sum up probability in 1 time slice
    sums.append( sum ) # append to list
# Write to file
# ofile = open("data_sim_2.txt", "w") # Change name accordingly
for line in sums:
    ofile.write(str(line))
    ofile.write("\n")
ofile.close()



# # For Simulation 3
# # Initialize Containers
# S = pa.cx_cube()
# # Load Cube Matrix
# S.load("Grid_Simulation3.bin") 
# Sconj = pa.conj(S)
# Sprob = S@Sconj
# res = np.array( pa.real(S) )
# ims = np.array( pa.imag(S) )
# prob = np.array( Sprob )
# # Write to file
# timeslice = np.array( [0, 39, 79] )
# for k in timeslice:
#     ofile = open(f"Sprob_t={k}.txt", "w")
#     ofilere = open(f"Sreal_t={k}.txt", "w")
#     ofileim = open(f"Simag_t={k}.txt", "w")
#     probmat = np.matrix( prob[k,:,:] )
#     realmat = np.matrix( res[k,:,:] )
#     imagmat = np.matrix( ims[k,:,:] )
#     for line in probmat:
#         np.savetxt(ofile, line, fmt='%.4e')
#     for line in realmat:
#         np.savetxt(ofilere, line, fmt='%.4e')
#     for line in imagmat:
#         np.savetxt(ofileim, line, fmt='%.4e')


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