A similar program to the program used in Problem 7, except we now increase our upper limit for the range of N = 10 to 10^7 values.
We have also increased the precision of the data that is to be outputed.


prob8.cpp
--------
C++ code that uses the general algorithm for solving Av=g for a tridiagonal matrix to computes v for N = 10 to 10^7 elements.
Outputs x,v, and u(x) to a file the approriate file prob8{N}.txt where N is indicates the length of xi used.

Build command: g++ prob8.cpp -o prob8.exe

(for MacOs): g++ -std=c++11 prob8.cpp -larmadillo -o prob8.exe

Run command: ./prob8.exe


prob8.py
-------
Python script that reads the appopriate data file prob8{N}.txt for N = 10 to 10^7 and calculates and plots the log10 of the absolute error and relative error, and 
finds the maximum relative error for each choice of N. The plots are saved as logAbsError_plot.pdf, logRelError_plot.pdf, Max_Relative_Error.pdf

Run command: python3 prob8.py
