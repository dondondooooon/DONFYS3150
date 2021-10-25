A similar program to the program used in Problem 7, except we now use our special algorithm to reduced the number of FLOPs in our code.


prob9.cpp
--------
C++ code that uses the special algorithm for solving Av=g for a tridiagonal matrix to computes v for N = 10 to 10^5 elements.
Outputs x,v, and u(x) to a file the approriate file prob9{N}.txt where N is indicates the length of xi used.

Build command: g++ prob9.cpp -o prob9.exe

(for MacOs): g++ -std=c++11 prob9.cpp -larmadillo -o prob9.exe

Run command: ./prob9.exe


prob9.py
-------
Python script that reads the appopriate data file prob9{N}.txt for N = 10 to 10^5 and generates the plot comparing Numeric vs. 
Exact solutions for the range of N-values for Eq.1 in Project 1. Plot is saved as New_Num.vs.Exact_Ns.pdf. But also did a run
where it plots only for N = 100 to get a closer look at the difference. This is saved as Num.vs.Exact_Ns.pdf

Run command: python3 prob9.py
