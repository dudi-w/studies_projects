import matplotlib.pyplot as plt
import numpy as np
import random
from mpl_toolkits import mplot3d

fig = plt.figure()
ax = fig.add_subplot(projection='3d')
N=1000
x=[0 for i in range(N)]
y=[0 for i in range(N)]
z=[0 for i in range(N)]

for j in range(N-1):
    dise1=random.random()
    dise2=random.random()
    if dise1>0.666:
        if dise2>0.5:
            x[j+1]=x[j]+1
        else:
            x[j+1]=x[j]-1
        y[j+1]=y[j]
        z[j+1]=z[j]
    else:       
        if dise1>0.333:    
            if dise2>0.5:
                 y[j+1]=y[j]+1
            else:
                 y[j+1]=y[j]-1
            x[j+1]=x[j]
            z[j+1]=z[j]
        else:
            if dise2>0.5:
                 z[j+1]=z[j]+1
            else:
                 z[j+1]=z[j]-1
            x[j+1]=x[j]
            y[j+1]=y[j]


ax.scatter(x, y ,z )
ax.plot3D(x,y,z , c = 'r')
#plt.plot(x,y)
plt.show()

