import pyarma as pa 
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

r = pa.mat()
v = pa.mat()

partikol = ["Particle 0", "Particle 1"]
kolor = ["blue","orange"]
x = [r"$x$",r"$y$",r"$z$"]
y = [r"$v_x$",r"$v_y$",r"$v_z$"]
###################
# # H-steps
# for j in range(3):
#     for i in range(2):
#         r.load(f"Rpos{i}.bin")
#         v.load(f"Vvel{i}.bin")
#         plt.plot(r[j,:],v[j,:],color=kolor[i],label=partikol[i])
#     # plt.title(titolo[j])
#     plt.xlabel(x[j])
#     plt.ylabel(y[j])
#     plt.legend(loc='upper right')
#     plt.savefig(f"plot{j-4}.pdf") # or +7 for with interaction
#     plt.show()

# # r.load("Rpos.bin")
# # plt.plot(r[0,:],r[1,:], color='blue',label='Particle 0')
# # plt.legend()
# # plt.xlabel(r'$r_x$[$\mu$m]')
# # plt.ylabel(r'$r_y$[$\mu$m]')

# # plt.title("Single particle trajectory tstep = 10.0")
# # plt.savefig("sinpar4.pdf") # or +7 for with interaction
# plt.show()
###################
# 3D Plots
# fig = plt.figure()
# ax = plt.axes(projection='3d')
# for i in range(2):
#     r.load(f"Rpos{i}.bin") 
#     ax.plot3D(r[0,:], r[1,:], r[2,:], color=kolor[i], label=partikol[i])
# #r.load("Rpos0.bin") 
# # #ax.plot3D(r[0,:],r[1,:],r[2,:])
# ax.set_xlabel(r'$r_x$[$\mu$m]')
# ax.set_ylabel(r'$r_y$[$\mu$m]')
# ax.set_zlabel(r'$r_z$[$\mu$m]')

# plt.savefig("3dtrajwithout.pdf")
# plt.show()
###################
# For Phase Space plots
#titolo = [r"Phase Space $x$",r"Phase Space $y$",r"Phase Space $z$"]
# for j in range(3):
#     for i in range(2):
#         r.load(f"Rpos{i}.bin")
#         v.load(f"Vvel{i}.bin")
#         plt.plot(r[j,:],v[j,:],color=kolor[i],label=partikol[i])
#     # plt.title(titolo[j])
#     plt.xlabel(x[j])
#     plt.ylabel(y[j])
#     plt.legend(loc='upper right')
#     # plt.savefig(f"PS_ke_{j+4}.pdf") # or +7 for with interaction
#     plt.show()
###################
# 2 Particles with and without Coloumb Interactions
r = pa.mat()
# Style_List 
style = ["-","-"]
#colz = ["green","dodgerblue"]
dotcolz = ['blue','red','yellow','pink']
# Go through all .bin files
for i in range(2):
    r.load(f"Rpos{i}.bin") # Unload Binary files
    plt.plot(r[0,:],r[1,:],style[i],label=f'Particle {i}')
    # Plot Starting and End point
    if i==1:
        dotcolz.append(dotcolz.pop(0))
    nr = np.array(r)
    plt.plot(nr[0,0],nr[1,0],'o',color=dotcolz[i],label=f'Start{i}')
    plt.plot(nr[0,-1],nr[1,-1],'o',color=dotcolz[i+1],label=f'End{i}')

plt.xlabel(r"$r_x$ [$\mu$m]")
plt.ylabel(r"$r_y$  [$\mu$m]")
# plt.title("XY-Plane with Coloumb Interaction")
plt.legend(loc='upper right')
# plt.savefig("2p_XY_plane_ke.pdf")
plt.show()
###################
# # Time vs. Z-direction
# # Initialization
# r = pa.mat()
# t = np.linspace(0,100,10000)
# # Unload binary files
# r.load("Rpos0.bin")  # RK4
# # Plot
# plt.plot(t,r[2,:])
# plt.xlabel(r"$t$ [$\mu$s]")
# plt.ylabel(r"$r_z$ [$\mu$m]")
# # plt.title(r"Time vs. Position in $z$-direction")
# plt.savefig("Time_vs_Z_direction.pdf")
# plt.show()