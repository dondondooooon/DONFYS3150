A program that uses the general algorithm in Problem 6 in Project 1 to solve Av=g, where A is a tridiagonal matrix from Problem 4. 
The program writes out the solution v, corresponding values x, and exact solutions u(x) into a file.

prob7.cpp
--------
C++ code that uses the general algorithm for solving Av=g for a tridiagonal matrix to computes v for N = 10 to 10^5 elements.
Outputs x,v, and u(x) to a file the approriate file prob7{N}.txt where N is indicates the length of xi used.

Build command: g++ prob7.cpp -o prob7.exe
(for MacOs): g++ -std=c++11 prob7.cpp -larmadillo -o prob7.exe
Run command: ./prob7.exe


prob2.py
-------
Python script that reads the appopriate data file prob7{N}.txt for N = 10 to 10^5 and generates the plot comparing Numeric vs. 
Exact solutions for a range of N-values for Eq.1 in Project 1. Plot is saved as Num.vs.Exact_Ns.pdf.

Run command: python3 prob7.py
