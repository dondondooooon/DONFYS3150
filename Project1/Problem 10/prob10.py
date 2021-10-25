import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

G = np.empty([1,6])
S = np.empty([1,6])

for i in range(1,11):
    # Iterate 1 to 11 and find correct .txt file  
    filename = f"{i}_timedata.txt"
    tg,ts = np.loadtxt(filename, usecols=(0,1), unpack=True) # Unload the 2 columns 
    G = np.vstack([G,np.transpose(np.log10(tg))])
    S = np.vstack([S,np.transpose(np.log10(ts))])

G = np.delete(G,(0), axis=0)
S = np.delete(S,(0), axis=0)

print("The average time taken for general algorithm from n=10 to n=10^7 respectively is: ", G.mean(axis=0))
print("The average time taken for special algorithm from n=10 to n=10^7 respectively is: ", S.mean(axis=0))

#This Plots the Table
"""
# Plot 1
fig, ax1 = plt.subplots(figsize=(14,4))
fig.patch.set_visible(False)
ax1.axis('off') 
ax1.axis('tight') 

dfg = pd.DataFrame(G, columns=np.logspace(1,6,num=6,base=10,dtype='int'))
ax1.table(cellText=dfg.values, colLabels=dfg.columns, loc='center')

ax1.set_title('General Algorithm')
fig.tight_layout()
plt.savefig('TimeTest_General.pdf')
plt.show()  

# Plot 2
fig, ax2 = plt.subplots(figsize=(14,3))
fig.patch.set_visible(False)
ax2.axis('off') 
ax2.axis('tight') 

dfs = pd.DataFrame(S, columns=np.logspace(1,6,num=6,base=10,dtype='int'))
ax2.table(cellText=dfs.values, colLabels=dfs.columns, loc='center')

ax2.set_title('Special Algorithm')
plt.savefig('TimeTest_Special.pdf')
plt.show()
"""
