import json
import  requests
from urllib.request import urlopen
import numpy as np
import matplotlib.pyplot as plt
#import random
#import sklearn
from sklearn.utils import shuffle

def get_repositores_prom_Github( language , how_many_repositores , page_num):
	all_repositores = urlopen(f"https://api.github.com/search/repositories?q=language:{language}&per_page={how_many_repositores}&page={page_num}")
	date_repositores_json =json.loads( all_repositores.read())
	return date_repositores_json

def get_date_according_2_keys(date_repositores_json , key1 , key2 , date_matrix):	
	for item in date_repositores_json.get("items"):
		date_matrix[0].append(item.get(key1))
		date_matrix[1].append(item.get(key2))
	return date_matrix
	
def mix_date(array_2D):
	array_2D[0] , array_2D[1] = shuffle(array_2D[0], array_2D[1])
	return array_2D
		
def displays_graph (date_x_y , test_date , test_y_results_array ,name_key1 , name_key2 , linear_equation):
	# plotting the actual points as scatter plot
	plt.scatter(date_x_y[0], date_x_y[1])
	plt.scatter(test_date[0], test_date[1])
	plt.scatter(test_date[0], test_y_results_array)
	
	# predicted response vector
	y_pred = linear_equation[0] + linear_equation[1]*date_x_y[0]

	# plotting the regression line
	plt.plot(date_x_y[0], y_pred, c='r')
	
	# putting labels
	plt.xlabel(name_key1)
	plt.ylabel(name_key2)

	# function to show plot
	plt.show()
	
def calculate_R_cquare(date_array , linear_equation ,test_results_array ):
	date_array[1]= np.array(date_array[1])
	test_results_array = np.array(test_results_array)
	n = np.size(date_array[0])

	# mean of y vector
	m_y = np.mean(date_array[1])
	
	#Adjusted R Square
	s_yv_cq = (np.sum(test_results_array-m_y)**2)/n
	s_e_cq = (np.sum(date_array[1]-test_results_array)**2)/n
	s_y_cq = s_yv_cq+s_e_cq
	r_cq = s_yv_cq / s_y_cq
	print (r_cq)


def estimate_coef(selected_date):
	# number of observations/points
	selected_date[0]= np.array(selected_date[0])
	selected_date[1]= np.array(selected_date[1])
	n = np.size(selected_date[0])

	# mean of x and y vector
	m_x = np.mean(selected_date[0])
	m_y = np.mean(selected_date[1])

	# calculating cross-deviation and deviation about x
	SS_xy = np.sum(selected_date[0]*selected_date[1]) - n*m_y*m_x
	SS_xx = np.sum(selected_date[0]*selected_date[0]) - n*m_x*m_x
	# calculating regression coefficients
	linear_equation=[]
	linear_equation.append(m_y - (SS_xy / SS_xx)*m_x)
	linear_equation.append(SS_xy / SS_xx)
	
	#Score of the model
	score_model = ((np.sum((selected_date[0]-m_x)*(selected_date[1]-m_y)) / np.sum((((selected_date[0]-m_x)**2)*((selected_date[1]-m_y)**2))**0.5))**2)
	print (score_model)
	return linear_equation
	
def test_results(linear_equation , date_array):
	#create Array of test results according to the regression line
	test_results_array=[]
	for x_value in date_array[0]:
		test_results_array.append(linear_equation[0] + linear_equation[1]*x_value)
	return test_results_array


def main():
	date_key1 =[]
	date_key2 =[]
	date_matrix=[date_key1, date_key2]
	language= "python"
	how_many_repositores = 950  #Limited to 1000 
	coun1 = int(how_many_repositores/100)
	coun2 = (how_many_repositores%100)
	i = 0
	for i in range(coun1):
		date_repositores_json = get_repositores_prom_Github( language , 100 , i+1 )
		get_date_according_2_keys( date_repositores_json , "stargazers_count" , "forks_count" , date_matrix)
	date_repositores_json = get_repositores_prom_Github( language , coun2 , i+1 )
	
	#Extracts the date according 2 keys and divides it for training and for testing
	selected_date = get_date_according_2_keys( date_repositores_json , "stargazers_count" , "forks_count" , date_matrix)
	selected_mix_date = mix_date(selected_date)
	trean_date=[selected_mix_date[0][:int(how_many_repositores*0.7)] , selected_mix_date[1][:int(how_many_repositores*0.7)]]
	test_date=[selected_mix_date[0][-(how_many_repositores-int(how_many_repositores*0.7)):] , selected_mix_date[1][-(how_many_repositores-int(how_many_repositores*0.7)):]]
	
	
	linear_equation = estimate_coef(trean_date)
	test_y_results_array = test_results(linear_equation , test_date)
	calculate_R_cquare( test_date , linear_equation ,test_y_results_array )
	displays_graph (trean_date , test_date ,test_y_results_array, "stargazers_count" , "forks_count" , linear_equation)
	
	
if __name__ == "__main__":
    main()

