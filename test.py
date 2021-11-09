import numpy as np

def p(E):
    return((1/Z)*np.exp(-E))

Z = 12 + 2*np.exp(8) + np.exp(-8)

ez = [-8,-8,8]
E = np.array(ez)
sum = 0

for i in range(len(ez)):
    sum+= E[i]*p(E[i])

print(sum)