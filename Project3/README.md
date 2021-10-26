src
--------
This is where the functions for both the particle and penning trap and the different algorithms used to simulate the penning trap that are used in main.cpp are written. It is seperated as Particle.cpp and Penning.cpp, where the former holds the class Particle, its member variables, and its constructor. The later holds the class PenningTrap, its member variables, its constructor, and a bunch of class methods.

main.cpp
--------
A C++ program that initializes values to be used in a penning trap simulation and then exports the position and velocity matrix of n particles. The matrices are exported in .bin files that are found in the bin folder.

Build command: make

plot.py
--------
This python script imports the binary files which contain the matrices for the position and vector of the particle/s and produces different plots:
	
      1. z position vs. time of 1 particle
	
	2. xy-plane for 2 particles with and without coloumb interaction

	3. phase space plots (x,y,and z) for 2 particles with and without coloumb interaction.

	4. 3D plots for 2 particles with and without coloumb interaction.

	5. Trajectory of a single particle for a given h-step.

Run command: python3 plot.py



segerr
--------
In this folder is a copy of the all the necessary files for when running the simulation. When attempting to upgrade our basic setup for the penning trap (exercise 10), we ran into a segmentation fault/error, for which we could not debug or fix in time, (we were a bit low on time to figure it out). A screenshot of the error is shown in segmentation error.png in this folder. We created this folder to show that we did attempt to upgrade our penning trap simulation as suggested in exercise 10 in Project 3, however were unsuccessful due to a segmentation fault.
