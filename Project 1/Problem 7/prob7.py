import numpy as np
import matplotlib.pyplot as plt

a,x,y = ([] for i in range(3))  #Iniate empty lists

f = open('prob7.txt','r')   #Opens the text file
for line in f:              #Loops through the text file's lines
    line = line.strip()     #Strips the line of blank spaces
    num = line.split(",")   #Splits the line according to the ","
    a.append(num)           #Appends it into the matrix list
f.close()

#Is there a more efficient way to collect the data file? 
# Maybe edit the original code that makes the data file to make it simpler for export and importing?

for i in range(len(a)):
    x.append(float(a[i][0])) #Collects x-values
    y.append(float(a[i][1])) #Collects vt-values

plt.plot(x,y)
plt.xlabel('x')
plt.ylabel('vt')
plt.savefig('Figure_2.pdf')
plt.show()