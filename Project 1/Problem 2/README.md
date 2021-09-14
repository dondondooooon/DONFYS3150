A program that calculates and plots the exact solution for u(x) in Eq.2 in Project 1

prob2.cpp
--------
C++ code that computes u(x) in Eq.2 in Project 1 at a point xi for N = 1000 elements.
Outputs the result to a file prob2.txt.

Build command: g++ prob2.cpp -o prob2.exe

(for MacOs): g++ -std=c++11 prob2.cpp -larmadillo -o prob2.exe

Run command: ./prob2.exe


prob2.py
-------
Python script that reads the data in prob2.txt and generates the plot of x vs. u(x). Plot is saved as Exact_Solution_plot.pdf.

Run command: python3 prob2.py
