import numpy as np
import matplotlib.pyplot as plt

def extract_file(file_to_extract):
	data = np.load( file_to_extract )
	array_data=[]
	for key in data:
		array_data.append(data[key])
	return array_data
	
def calculation_partial_derivative(array_data_x , array_data_y , results_array):
	#print(array_data_y , results_array)
	gradient_for_Theta1= np.sum(results_array-array_data_y)
	#print(gradient_for_Theta1)
	gradient_for_Theta2=  np.sum((results_array-array_data_y)*array_data_x)
	
	return gradient_for_Theta1 , gradient_for_Theta2

def calculation_error_OLS(array_data , results_array):
	n = np.size(results_array)
	error = (np.sum((results_array-array_data)**2))/n
	print (error)

def results_y_hat(Theta1 , Theta2,  array_data):
	#create Array of results according to the test line
	results_array=[]
	for x_value in array_data:
		results_array.append(Theta1 + Theta2*x_value)
	return np.array(results_array)
	
def plot_regression_line(x, y, Theta2 ,Theta1):
	# plotting the actual points as scatter plot
	plt.scatter(x, y)
	# predicted response vector
	y_pred = Theta1 + Theta2*x
	#print ("y_pred")
	#print( y_pred)
	# plotting the regression line
	plt.plot(x, y_pred , color = "c")

	# function to show plot
	plt.show()
	


def main():
	#array_data = extract_file("XYdata.npz")
	array_data=[0]*2
	array_data[0]=np.array([1,2,3,4])
	array_data[1]=np.array([2,1,5,2])
	Theta1= 0		#undepnded velue in ecvition 
	Theta2= 2		#corfition to the slupe
	counter=100000		#number to iteration 
	epsilon= 0.001
	gradient_Theta1=1
	gradient_Theta2=1
	#print(array_data)
	#results_array = results_y_hat(Theta1 , Theta2,  array_data[0])
	#Theta1 , Theta2 = calculation_partial_derivative (array_data[1] , results_array)
	i=0
	while(i < counter):
		if (abs(gradient_Theta1)>epsilon or  abs(gradient_Theta2)>epsilon ):
			results_array = results_y_hat(Theta1 , Theta2,  array_data[0])		
			#plot_regression_line(array_data[0] ,array_data[1] ,Theta2 , Theta1)
			gradient_Theta1 , gradient_Theta2 = calculation_partial_derivative(array_data[0] , array_data[1] , results_array)
			#print(gradient_Theta1 , gradient_Theta2)
			#print(results_array)
			calculation_error_OLS(array_data[1] , results_array)
			Theta1= Theta1-epsilon*gradient_Theta1
			Theta2= Theta2-epsilon*gradient_Theta2
		
			#print (Theta1 , Theta2 , gradient_Theta1 , gradient_Theta2)
		else:
			print (Theta1 , Theta2 , gradient_Theta1 , gradient_Theta2)
			return
		i+=1
		print (i)
	else:
		return
	
	#print( calculation_error(  ,array_data[1] ))

if __name__ == "__main__":
    main()
