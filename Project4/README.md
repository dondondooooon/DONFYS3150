src/isingmodel.cpp
--------
This is where the Class "Ising" is constructed along with its many class methods used for simulating the 2D Ising Model

--------------------------------------------------

main.cpp
--------
A C++ program that initializes values that are to be used in the "Ising" class that simulates a 2D Ising Model, and uses the different class methods in the Ising class to both simulate and writes the data to appropriate .txt files. This program is mainly run in series, and an attempt was made to parrallallize the code, however unknown complications in using OpenMPI made the data extracted from running the simulation in parallell, which otherwise would be correct by running it in series, wrong.

Build command for series: make allseries

Build command for parallell: make allparallell

--------------------------------------------------

python_scripts/plot.py
--------
This python script reads the temperature dependent .txt files made by running the 2D Ising model simulation and does several things: 
	
    1. Printout the values for T = 1 for different Monte Carlo cycles
	
	2. Plots the different physical quantities as a function of temperature & Plots the analytical solution for the different physical quantities

	3. Plots the mean energy and absolute magnetization per spin as a function of Monte Carlo cycles

	4. Plots the histogram approximation for the true unknown probability density function. 

Run command: python3 plot.py

--------------------------------------------------

python_scripts/rel_err.py
--------
This python script also reads the temperature dependent .txt files made by running the 2D Ising model simulation and calculates the relative error of each temperature dependent .txt files which used different Monte Carlo cycles, as well as plot them all in one graph.

Run command: python3 rel_err.py

--------------------------------------------------

python_scripts/critical.py
--------
This python script reads the temperature dependent .txt files made by running the 2D Ising model simulation for big lattice sizes, L = 40, 60, 80, 100, and plots them in the same graph. The critical temperature is also printed for the chosen physical quantity. 

Run command: python3 critical.py

--------------------------------------------------

dummy_parallellization
--------
In this folder contains a similar version of main.cpp and isingmodel.cpp. However, we attempted an unsuccessful dummy parallelization to see if it would yield the correct data at the same time as shortening the processing time for all data points. It was unsuccessful in that the data points was wrong.

dummy_parallellization/main.cpp
--------
A similar version of main.cpp except we take in arguments from the terminal window when running the program such that we can run multiple terminal windows running the program but with different values.

Compile & Linking: make allseries

Build command: 
	1st Terminal Window: ./main.exe 2.1 2.2 10 500000 part1.txt
	
	2nd Terminal Window: ./main.exe 2.2 2.3 10 500000 part2.txt

	3rd Terminal Window: ./main.exe 2.3 2.4 10 500000 part3.txt

	4th Terminal Window: ./main.exe 2.4 2.4 1 500000 part4.txt

And then combine the data files into one: cat part1.txt part2.txt part3.txt part4.txt > fulldata.txt
