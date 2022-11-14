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
		for i in range(self.dim):
			MainArray[i]= [0]*self.steps
		return MainArray
	
	def get_dim_to_go(self):
		num_dim=(random.randint(0 , self.dim-1))
		return num_dim

	def get_step(self):
		dise=random.random()
		if dise>0.5:
			direction=1
		else:
			direction=-1
		return direction


	def stepsForward(self):
		for i in range(self.steps):
			self.matrix[self.get_dim_to_go()][i]=self.get_step()
		for i in range(1 , self.steps):
			for j in range(self.dim):
				self.matrix[j][i]+=self.matrix[j][i-1]
		return self.matrix


	def print1D(self):
		plt.plot(self.matrix[0],[0]*len(self.matrix[0]))
		plt.show()
	
	def print2D(self):
		plt.plot(self.matrix[0],self.matrix[1])
		plt.show()

	def print3D(self):
		fig = plt.figure()
		ax = fig.add_subplot(projection='3d')    
		ax.plot3D(self.matrix[0],self.matrix[1],self.matrix[2])
		plt.show()

	def printnD(self):
		if self.dim == 1:
			self.print1D()
		elif self.dim == 2:
			self.print2D()
		elif self.dim == 3:
			self.print3D()
		else:
			print(self.matrix)
	

def main():
	dimation=22
	steps =50000
	##### check if the input is velid
	if dimation<=0 or steps <=0 or dimation!=int(dimation) or steps!=int(steps):
		print ("error")
		return
		
	drunk_steps = Drunk_steps(dimation , steps)
	drunk_steps.stepsForward()
	drunk_steps.printnD()
	
	
if __name__ == "__main__":
    main()

