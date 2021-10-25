import numpy as np
import matplotlib.pyplot as plt
import sys as sys

x_0 = 0
y_0 = 1
z_0 = 1
r_0 = np.sqrt(x_0 + y_0 + z_0)
q = 1.01
B_0 = 1  #9.65 * 10**1
m = 1
V_0 =  1 #9.65 * 10**8
d =  2 #10**4 #np.sqrt( z_0**2 + (r_0**2)/2)
omega_0 = q * B_0/m
omega_z_squared = (2 * q * V_0)/(m * d**2)
omega_p = (omega_0 + np.sqrt(omega_0**2 - 2 * omega_z_squared))/2
omega_m =(omega_0 - np.sqrt(omega_0**2 - 2 * omega_z_squared))/2
A_p = (V_0 + x_0 * omega_m)/(omega_m - omega_p)
A_m = - (V_0 + x_0 * omega_p)/(omega_m - omega_p)
t_end = 20
N = 1000


t = np.linspace(0,t_end,N)
x = A_p * np.cos(omega_p * t) + A_m *np.cos(omega_m * t)
y = - A_p * np.sin(omega_p * t) - A_m *np.sin(omega_m * t)
z = z_0 * np.cos(np.sqrt(omega_0) * t)

#print(f" x is equal to: {x}")
#print(f" y is equal to: {y}")
#print(f" z is equal to: {z}")
#xy_plane =  np.concatenate((x, y))

plt.plot(x,y)
#plt.plot(t,z)
plt.show()

"""
fig = plt.figure()
ax = plt.axes(projection='3d')

# Data for a three-dimensional line
#zline = np.linspace(0, 15, 1000)
#xline = np.sin(zline)
#yline = np.cos(zline)
ax.plot3D(x, y, t, 'gray')
plt.show()
"""

#print(f"XY-plane is equal to: {xy_plane}")

"""
t = np.linspace(0,t_end,N)
x = A_p * np.cos(omega_p * t) + A_m *np.cos(omega_m * t)
y = - A_p * np.sin(omega_p * t) - A_m *np.sin(omega_m * t)
z = z_0 * np.cos(np.sqrt(\omega_0) * t)
"""
