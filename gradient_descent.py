import numpy as np
import matplotlib.pyplot as plt
import math



def extract_file(file_to_extract):
	data = np.load( file_to_extract )
	array_data=[]
	for key in data:
		array_data.append(data[key])
	print(array_data[0])
	return array_data
	
def calculation_partial_derivative(array_data_x ,array_data_y ,results_array ,weight=1):
	weight=weight
	gradient_for_Theta1= np.sum((results_array-array_data_y)*weight)
	gradient_for_Theta2=  np.sum(((results_array-array_data_y)*array_data_x)*weight)
	return gradient_for_Theta1 , gradient_for_Theta2

def calculation_error_OLS(array_data ,results_array):	#@@@
	weight= np.size(results_array)
	error= (np.sum(results_array-array_data)**2)/weight
	print(error)
	return error

def calculation_error_OLS(array_data ,results_array, weight):	#@@@
	error= (np.sum(((results_array-array_data)**2)/weight))
	print(error)
	return error

def results_y_hat(Theta1 , Theta2,  array_data):
	#create Array of results according to the test line
	results_array=[]
	for x_value in array_data:
		results_array.append(Theta1 + Theta2*x_value)
	return results_array				#return np.array(results_array)

def standard_deviation(array_x):
	average= np.average(array_x)
	n=np.size(array_x)
	sd= ((np.sum((array_x-average)**2)/n)**0.5)
	return sd
	
def weighted_gradient_calculation3(array_data_x):
	sd= standard_deviation(array_data_x)
	m= np.median(array_data_x)
	#weighting= x*(2.71828182845904**(-(((array_data_x-m)**2)/(2*(sd**2))))
	weighting=(np.exp((-(((array_data_x-m)**2)/(2*sd**2)))))
	print (weighting)
	weighting= weighting/np.sum(weighting)
	print (weighting)
	plt.plot(array_data_x, weighting , color = "g")
	plt.show()
	return weighting
	
	
def weighted_gradient_calculation2(array_data_x):
	n = np.size(array_data_x)      #???
	m= np.median(array_data_x)
	s=0
	weighting= (-(array_data_x-m)**2)
	while  (weighting[0] <=0.1) or (weighting[n-1] <=0.1):
		print(weighting[0] , weighting[n-1] , m , n, s)
		s+=0.1
		weighting=(-(array_data_x-m)**2)+s
	weighting= weighting/np.sum(weighting)
	#plt.plot(array_data_x, weighting , color = "g")
	#plt.show()
	return weighting

def weighted_gradient_calculation(array_data_x):
	n = np.size(array_data_x)
	m= np.median(array_data_x)
	#array_data_x=np.array(array_data_x)
	s=min(-(array_data_x[0]-m)**2 , -(array_data_x[n-1]-m)**2)
	weighting= (-(array_data_x-m)**2)-s+0.1
	#sum_array= np.sum(weighting)
	weighting= weighting/np.sum(weighting)
	#plt.plot(array_data_x, weighting , color = "c")
	#plt.show()
	return weighting	


def plot_regression_line(x, y, Theta2 ,Theta1):
	# plotting the actual points as scatter plot
	plt.scatter(x, y)
	# predicted response vector
	y_pred = Theta1 + Theta2*x
	# plotting the regression line
	plt.plot(x, y_pred , color = "c")
	# function to show plot
	plt.show()

	
def plot_error(grad1, grad2 , error):
	# plotting the actual points as scatter plot
	plt.scatter(grad1, error)
	# plotting the regression line
	plt.plot(grad1 ,error  , color = "c")
	plt.plot(grad2 , error , color = "y")
	# function to show plot
	plt.show()


def main():
	array_data = extract_file("XYdata.npz")
	Theta1= 2		#independent parameter in the equation
	Theta2= 1		#corfition to the slope	
	limit=5000		#slope coefficient
	epsilon= 0.0001
	gradient_Theta1=1
	gradient_Theta2=1
	array_gradient_Theta1=[]
	array_gradient_Theta2=[]
	array_error=[]
	weight = weighted_gradient_calculation3(array_data[0])
	while(limit > 0 ):
		if (abs(gradient_Theta1)>epsilon or  abs(gradient_Theta2)>epsilon ):
			results_array = results_y_hat(Theta1 , Theta2,  array_data[0])		
			gradient_Theta1 , gradient_Theta2 = calculation_partial_derivative(array_data[0] , array_data[1] , results_array , weight)
			error= calculation_error_OLS(array_data[1] , results_array, weight)	
			#add velue to array in order to check it
			array_gradient_Theta1.append(gradient_Theta1)
			array_gradient_Theta2.append(gradient_Theta2)
			array_error.append(error)
			#depind the new theta's	
			Theta1= Theta1-epsilon*gradient_Theta1
			Theta2= Theta2-epsilon*gradient_Theta2
		else:
			print (Theta1 , Theta2 , gradient_Theta1 , gradient_Theta2)
			plot_error(array_gradient_Theta1 ,array_gradient_Theta2, array_error)
			plot_regression_line(array_data[0] ,array_data[1] ,Theta2 , Theta1)
			return
		limit-=1
		print (limit)
	else:
		print(Theta1 , Theta2 , gradient_Theta1 , gradient_Theta2)
		plot_error(array_gradient_Theta1 ,array_gradient_Theta2, array_error)
		plot_regression_line(array_data[0] ,array_data[1] ,Theta2 , Theta1)
		return
	
if __name__ == "__main__":
    main()
