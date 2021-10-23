import pyarma as pa 
import matplotlib.pyplot as plt
import numpy as np

r = pa.mat()
style = ["-","--"]
colz = ["green","orange"]
dotcolz = ['blue','red','yellow','pink']

r.load("Rpos0.bin")
plt.plot(r[:,0],r[:,1],label='Particle 1')

# for i in range(2):
#     r.load(f"Rpos{i}.bin")
#     plt.plot(r[:,0],r[:,1],style[i],color=colz[i],label=f'Particle {i}')
#     nr = np.array(r)
#     if i==1:
#         dotcolz.append(dotcolz.pop(0))
#     plt.plot(nr[0,0],nr[0,1],'o',color=dotcolz[i],label=f'Start{i}')
#     plt.plot(nr[-1,0],nr[-1,1],'o',color=dotcolz[i+1],label=f'End{i}')

plt.xlabel("X")
plt.ylabel("Y")
plt.title("XY-Plane w/o Coloumb Interaction")
plt.legend(loc='upper right')
#plt.savefig("2p_XY_plane_ke.pdf")
plt.show()

print(r)

# Time vs. Z-direction
"""
# Initialization
r = pa.mat()
v = pa.mat()
t = pa.mat()
# Unload binary files
# r.load("Rpos.bin")  # EC
# v.load("Vhas.bin")  # EC
# t.load("tid.bin")   # EC
r.load("Rpos_RK4.bin") #Runge-Kutta
v.load("Vhas_RK4.bin") #Runge-Kutta
t.load("tid_RK4.bin")  #Runge-Kutta
# Plot
plt.plot(t,r[:,2])
plt.xlabel(r"Time [$\mu$s]")
plt.ylabel(r"Z-direction [$\mu$m]")
plt.title("Time vs. Position in z-direction")
plt.savefig("Time_vs_Z_direction.pdf")
plt.show()
"""