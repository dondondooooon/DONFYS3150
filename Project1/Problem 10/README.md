A program that runs repeated timing tests on both the general and special algorithm.


prob10.cpp
--------
C++ code that runs repeated timing tests on both the general and special algorithm for a range of N = 10 to 10^6, 
and saves them on {j}_timedata.txt where j corresponds to which repeated run it was. 

Build command: g++ prob10.cpp -o prob10.exe

(for MacOs): g++ -std=c++11 prob10.cpp -larmadillo -o prob10.exe

Run command: ./prob10.exe


prob10.py
-------
Python script that reads the appopriate data files {j}_timedata.txt for N = 10 to 10^6, calculates the average 
timing test results for both general and special algorithm, and prints out the result.

Originally made a nice table plot of the raw results as well. (This has been commented out)

Run command: python3 prob10.py
