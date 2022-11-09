import matplotlib.pyplot as plt
import numpy as np
import random
from mpl_toolkits import mplot3d

class Drunk_steps:
    def __init__(self, dim, steps):
        self.dim=dim
        self.steps=steps
        self.matrix=self.build()

        def build(self):
            MainArray= [0]*self.dim
            for i in range(self.dim-1):
                MainArray[i]= [0]*self.steps
                print(MainArray[i])
            return MainArray
        
        def get_dim(self):
            num_dim=(random.randint(0 , self.dim)
            return num_dim

        def get_step(self):
            dise=random.random()
                if dise>0.5:
                    direction=1
                else:
                    direction=-1
            return direction


        def stepsForward(self):
            for i in range(self.steps-1):
                self.matrix[i][self.get_dim()]=self.get_step()
                for j in range(self.dim-1):
                     self.matrix[i][j]+=MainArray[i-1][j]
            return self.matrix


        def print1D(self):
            plt.plot(slef.matrix[0])
            plt.show()
        def prin0t2D(self):
            plt.plot(slef.matrix[0],self.matrix[1])
            plt.show()

        def print3D(self):
            fig = plt.figure()
            ax = fig.add_subplot(projection='3d')    
            ax.plot3D(slef.matrix[0],self.matrix[1],slef.matrix[2])
            plt.show()

        def printnD(self):

