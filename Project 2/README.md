src/alg.cpp
--------
This is where the functions for the algorithms that are used in main.cpp are written.

main.cpp
--------
A C++ program that performs all the neccesarry tasks in Project 2, i.e. finds the eigenvalues and eigenvectors for a given matrix of size N via 3 different methods:
  1. Arma function for finding eigenvalues and eigenvectors: eig_sym

  2. Analytical method given by the formula in Project 2

  3. Jacobi Rotation method

The program then prints out all the results as well as export the analytical and jacobian eigenvectors onto "anlvec.bin" and "jarovec.bin" files respectively.

Build command: make

plot.py
--------
This python script imports the binary files which contain the matrix for the eigenvectors and plots them with x.

Run command: python3 plot.py

figures
--------
Inside this folder is where our figures for our plots for our eigenvectors v_i vs. x_i.

scaling
--------
Inside this folder is where the raw .txt files and figures are stored for when we experimented with N values and corresponding iterations or transformations needed to reach the solution via jacobi rotation method. (Problem 6). We then plot these values via a generic python script to generate a graph/s shown in this folder.
