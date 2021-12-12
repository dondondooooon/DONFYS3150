quantum.cpp
--------
This is where the Class "quantum" is constructed along with its many class methods used for simulating the two-dimentional time-dependent Schrondinger Equation and the variations of single/double/triple-slit-in-a-box setup.

--------------------------------------------------

main.cpp
--------
A C++ program that initializes values that are to be used in the "quantum" class that simulates the Schrondinger Equation, and uses the different class methods in the "quantum" class to both simulate and exports the data which is stored in a cube matrix to the appropriate .bin files. 

Build command for series: make allseries

--------------------------------------------------

extract_bins.py
--------
This python script reads the .bin files of the selected simulation and exports the necessary data for plotting into .txt files

Run command: python3 extract_bins.py

--------------------------------------------------

plot.py
--------
This python script reads the appropriate .txt files and plots the data according to the desired quantities / plots / colormap plots. 

Run command: python3 plot.py

--------------------------------------------------