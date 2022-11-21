import csv
import random
import matplotlib.pyplot as plt
import math

def extract_file_and_onverts_to_float(file_name):
	with open('iris.csv', 'r', newline='') as data:
		csvreader = csv.reader(data)
		data= list(csvreader)
		data=[[float(i) if str(i).replace('.','',1).isdigit() else i for i in arr] for arr in data]
	return data	
	
def choose_K_points(data, k):
	return random.sample(data ,k)
	
def checks_distance(point1 , point2):
	sum_dis=0
	for i in range(len(point1)-1):
			sum_dis+= (point1[i]-point2[i])**2
	return sum_dis

def chooses_short_distance(point_to_sheck , points):
	arr_dis=[]
	for point in points:
		dis=checks_distance(point_to_sheck , point)
		arr_dis.append(dis)
	index_of_short_dis= arr_dis.index(min(arr_dis))
	return index_of_short_dis

def correlating_points_to_clusters(data ,mean_points, k):
	arr_clusters=[]
	for i in range(k):
		arr_clusters.append([])
	for point in data:
		clusters= chooses_short_distance(point , mean_points)
		arr_clusters[clusters].append(point)
	return arr_clusters
	
def get_mas_center(K_clusters):
	mas_center_for_all_K_clusters=[]
	for cluster in K_clusters:
		mas_center=calculat_mas_center(cluster)
		mas_center_for_all_K_clusters.append(mas_center)
	return  mas_center_for_all_K_clusters
	
def calculat_mas_center(cluster):
	#print (cluster)
	if len(cluster)==0:
		return [0,0,0,0,"mas center for cluster"]
	mas_center=[]
	for i in range(len(cluster[0])-1):
		averag=0
		for point in cluster:
			averag+= point[i]
		mas_center.append(averag/(len(cluster)))
	mas_center.append("mas center for cluster")
	return mas_center
	
def total_square_distance(arr_clusters ,mean_points):
	total_error_score=0
	for i in range(len(arr_clusters)):
		total_error_score +=calculat_square_distance(arr_clusters[i], mean_points[i])
	return total_error_score
	
def calculat_square_distance(points , mean):
	dis=0
	for point in points:
		dis+=checks_distance(point , mean)
	return dis

def checks_cluster_stability(data1 , data2):
	return data1 != data2

def print2D(arrX ,arrY):
	plt.plot(arrX ,arrY)
	plt.show()
	
def main():
	file_name='iris.csv'
	data= extract_file_and_onverts_to_float(file_name)
	random.shuffle(data)
	the_best_K=[[],[]]
	for k in range(1, 50):
		arr_rasult_mean=[]
		for i in range(10):
			K_clusters=0
			mean_points= choose_K_points(data[:-1], k)
			indicator= True
			while indicator:
				prev_K_clusters= K_clusters
				K_clusters= correlating_points_to_clusters(data ,mean_points , k)
				#print("\033[38;2;255;25;221m" , K_clusters, "\033[0m")
				mean_points= get_mas_center(K_clusters)
				#Checks whether to continue searching for center of mass
				indicator= checks_cluster_stability(K_clusters , prev_K_clusters)
			total_error_score= total_square_distance(K_clusters , mean_points)
			arr_rasult_mean.append([total_error_score , mean_points])
		final_result= min(arr_rasult_mean)
		#print("\033[38;2;100;225;221m" , arr_rasult_mean, "\033[0m")
		print("\033[38;2;100;25;200m" ,final_result , "\033[0m")
		the_best_K[0].append(k)
		the_best_K[1].append(final_result[0])
	print2D(the_best_K[0] ,the_best_K[1])
if __name__ == '__main__':
	main()
