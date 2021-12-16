from os import times
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
    ofile = open(f"data_files/data_sim_{sim}.txt", "r")
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
    plt.ylim(0.8,1.2)
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
    plt.ylim((min_dev-2.6)*1e-14,(max_dev+2)*1e-14)
    plt.savefig(f"plot_figures/sim{sim}_dev.pdf")
    plt.show()
# Choose Simulation to Plot
# sim1 = 1
# sim2 = 2
# plot_sim(sim1)
# plot_sim(sim2)



#
# For Simulation 3
#
def Matrix(Sname,k):
    # Initialize Containers
    S = np.zeros([200,200],float)
    data_strList = []
    # Unload data file
    ofile = open("data_files/" + Sname + f"_t={k}.txt", "r")
    for line in ofile: # Append list of strings column values by the rows 
        words = line.split()
        data_strList.append(words)
    for i in range(200): # Loop thru the list of strings
        for j in range(200):
            s_ij = float( data_strList[i][j] ) # make to float
            S[j,i] = s_ij # Add into np.array
    return(S)
def plot_them(k,S,name,label_name):
    time = k*0.000025+0.000025
    # Set up MeshGrid
    M = 200
    h = 0.005
    xpoints = np.arange(0,M*h,h) 
    ypoints = xpoints
    x,y = np.meshgrid(xpoints,ypoints,sparse=True)
    # Plot
    fig = plt.figure()
    ax = plt.gca()
    # Some settings
    fontsize = 12
    x_min, x_max = xpoints[0], xpoints[-1]
    y_min, y_max = ypoints[0], ypoints[-1]
    if name == 'Sprob':
        # Normalize
        norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(S))
        img = ax.imshow(S,extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"),norm=norm)
    else:
        img = ax.imshow(S,extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"))
    # Axis labels
    plt.xlabel("x", fontsize=fontsize*1.25)
    plt.ylabel("y", fontsize=fontsize*1.25)
    plt.xticks(fontsize=fontsize)
    plt.yticks(fontsize=fontsize)
    # Add a colourbar
    cbar = fig.colorbar(img, ax=ax)
    cbar.set_label(label_name, fontsize=fontsize*1.25)
    cbar.ax.tick_params(labelsize=fontsize)
    time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(time), color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)
    plt.savefig(f"plot_figures/{name}_TimeFrame={k}.pdf")
    plt.show()
def which(name,label_name):
    # Get time = 0, 0.001, 0.002 atleast
    timeslices = np.array( [0,9,19,29,39,49,59,69,79] ) # Selected Time Frames
    for k in timeslices:
        # Get the matricex
        S = Matrix(name,k)
        plot_them(k,S,name,label_name)
# name = ['Sprob','Sreal','Simag']
# label_name = [r"$p^n_{ij}$",r"Re($u_{ij}$)",r"Im($u_{ij}$)"]
# for i in range(3):
#     which( name[ i ] , label_name[ i ] )



#
# Problem 9
#
def plot_problem9(sim,slit,head):
    # Initialize Container
    data = []
    sum = 0
    # Unload data file
    ofile = open(f"data_files/Problem9_sim{sim}.txt", "r")
    for line in ofile.readlines():
        data.append( float( line ) )
    ofile.close()
    # Turn into a numpy array
    p9 = np.array(data)
    y = np.arange(0,1,0.005) # 200 points on grid
    # Normalize 1D Probability Function
    for i in range(len(p9)):
        sum += p9[i]
    p9 = p9/sum
    # Plot y points vs. p^0.002_0.8,j
    plt.plot(y,p9)
    plt.xlabel("y",fontsize=12)
    plt.ylabel(r"$p(y|x=0.8;t=0.002)$",fontsize=12)
    plt.title(head)
    plt.savefig(f"plot_figures/problem9_{slit}slit.pdf")
    plt.show()
    # # Check if normalized
    # sumsum = 0
    # for i in range(len(p9)):
    #     sumsum += p9[i]
    # print("This: ", sumsum)
# sim = [4,3,5]
# slit = 0
# head = ["Single-Slit","Double-Slit","Triple-Slit"]
# for num in sim:
#     slit += 1
#     plot_problem9(num,slit,head[slit-1])














# # Animation Attempt
# from matplotlib.animation import FuncAnimation

# # Set up MeshGrid
# M = 200
# h = 0.005
# x_points = np.arange(0,M*h,h) 
# y_points = x_points
# x,y = np.meshgrid(x_points,y_points,sparse=True)

# # Array of time points
# dt = 0.000025
# t_points = np.arange(0, 1+dt, dt)
# timeslice = np.arange(0,80,1)

# # A function for a Gaussian that is travelling 
# # in the x direction and broadening as time passes
# def z(x,y,t):
#     v = 0.5
#     x_c = 0.2
#     sigma_x = 0.025 + 0.15 * t
#     return 1. / (2 * np.pi * np.sqrt(sigma_x)) * np.exp(-0.5 * (x - x_c - v * t)**2 / sigma_x**2)

# # Fill z_data_list with f(x,y,t)
# # z_data_list = []
# # for t in t_points:
# #     z_data = z(x, y, t)
# #     z_data_list.append(z_data)

# z_data_list = Matrix('Sprob',timeslice[0])

# #
# # Now the list z_data_list contains a series of "frames" of z(x,y,t), 
# # where each frame can be plotted as a 2D image using imshow. Let's
# # animate it!
# #

# # Some settings
# fontsize = 12
# t_min = t_points[0]
# x_min, x_max = x_points[0], x_points[-1]
# y_min, y_max = y_points[0], y_points[-1]

# # Create figure
# fig = plt.figure()
# ax = plt.gca()

# # Create a colour scale normalization according to the max z value in the first frame
# norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(z_data_list[0]))

# # Plot the first frame
# img = ax.imshow(z_data_list[0], extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# # Axis labels
# plt.xlabel("x", fontsize=fontsize)
# plt.ylabel("y", fontsize=fontsize)
# plt.xticks(fontsize=fontsize)
# plt.yticks(fontsize=fontsize)

# # Add a colourbar
# cbar = fig.colorbar(img, ax=ax)
# cbar.set_label(r"$p^n_{ij}$", fontsize=fontsize)
# cbar.ax.tick_params(labelsize=fontsize)

# # Add a text element showing the time
# time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(t_min), color="white", 
#                     horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# # Function that takes care of updating the z data and other things for each frame
# def animation(i):
#     z_current = Matrix('Sprob', i)

#     # Normalize the colour scale to the current frame?
#     norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(z_current))
#     img.set_norm(norm)

#     # Update z data
#     img.set_data(z_current)

#     # Update the time label
#     current_time = t_min + i * dt
#     time_txt.set_text("t = {:.3e}".format(current_time))

#     return img

# # Use matplotlib.animation.FuncAnimation to put it all together
# anim = FuncAnimation(fig, animation, interval=1, frames=timeslice, repeat=False, blit=0) #np.arange(0, len(z_data_list), 2), repeat=False, blit=0)

# # Run the animation!
# plt.show()

# # # Save the animation
# # anim.save('./animation.mp4', writer="ffmpeg", bitrate=-1, fps=30)