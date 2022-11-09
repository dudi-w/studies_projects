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
	
	
def estimate_coef(selected_date):
	# number of observations/points
	selected_date[0]= np.array(selected_date[0])
	selected_date[1]= np.array(selected_date[1])
	n = np.size(selected_date[0])
	print (n)
	# mean of x and y vector
	m_x = np.mean(selected_date[0])
	m_y = np.mean(selected_date[1])
	print (np.mean(selected_date[1]))
	# calculating cross-deviation and deviation about x
	SS_xy = np.sum(selected_date[0]*selected_date[1]) - n*m_y*m_x
	SS_xx = np.sum(selected_date[0]*selected_date[0]) - n*m_x*m_x
	print (SS_xx)
	# calculating regression coefficients
	linear_equation=[]
	linear_equation.append(m_y - (SS_xy / SS_xx)*m_x)
	linear_equation.append(SS_xy / SS_xx)
	print(linear_equation[1])
	print(linear_equation[0]) 
	
	#Score of the model
	score_model = ((np.sum((selected_date[0]-m_x)*(selected_date[1]-m_y)) / np.sum((((selected_date[0]-m_x)**2)*((selected_date[1]-m_y)**2))**0.5))**2)
	print (score_model)
	return linear_equation
	
	
def mix_date(array_2D):
	array_2D[0] , array_2D[1] = shuffle(array_2D[0], array_2D[1] , random_state=0)
	return array_2D
	
	
	
	
def displays_graph (date_x_y , name_key1 , name_key2 , linear_equation):
	# plotting the actual points as scatter plot
	plt.scatter(date_x_y[0], date_x_y[1])
	
	# predicted response vector
	y_pred = linear_equation[0] + linear_equation[1]*date_x_y[0]

	# plotting the regression line
	plt.plot(date_x_y[0], y_pred, c='r')
	
	# putting labels
	plt.xlabel(name_key1)
	plt.ylabel(name_key2)

	# function to show plot
	plt.show()
	
def main():
	date_key1 =[]
	date_key2 =[]
	date_matrix=[date_key1, date_key2]
	language= "python"
	how_many_repositores = 35
	coun1 = int(how_many_repositores/100)
	coun2 = (how_many_repositores%100)
	i = 0
	for i in range(coun1):
		date_repositores_json = get_repositores_prom_Github( language , 100 , i+1 )
		get_date_according_2_keys( date_repositores_json , "stargazers_count" , "forks_count" , date_matrix)
		i+=1
		print(len(date_matrix[0]))
	date_repositores_json = get_repositores_prom_Github( language , coun2 , i+1 )
	#get_date_according_2_keys( date_repositores_json , "stargazers_count" , "forks_count" , date_matrix)
	
	selected_date = get_date_according_2_keys( date_repositores_json , "stargazers_count" , "forks_count" , date_matrix)
	#
	selected_mix_date = mix_date(selected_date)
	print(selected_mix_date)
	trean_date=[selected_mix_date[0][:int(how_many_repositores*0.7)] , selected_mix_date[1][:int(how_many_repositores*0.7)]]
	test_date=[selected_mix_date[0][-(how_many_repositores-int(how_many_repositores*0.7)):] , selected_mix_date[1][-(how_many_repositores-int(how_many_repositores*0.7)):]]
	print (len(trean_date))
	
	
	print(len(date_matrix[1]))
	
	linear_equation = estimate_coef(trean_date)
	displays_graph ( trean_date , "stargazers_count" , "forks_count" , linear_equation)
	
	
if __name__ == "__main__":
    main()

