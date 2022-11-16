import csv
import random
import matplotlib.pyplot as plt

def extract_file():
	with open('iris.csv', 'r', newline='') as data:
		csvreader = csv.reader(data)
		#data = [row for row in csvreader]
		data= list(csvreader)
		for arr in data:
			for j in range(len(arr)-1):
				arr[j]= float(arr[j])
	return data


#mix the data, and split the data to trean VS test
def mix_and_split(data):
	random.shuffle(data)
	trean_data= data[:int(len(data)*0.8)]
	test_data= data[int(len(data)*0.8):]
	return trean_data , test_data
	
def distance_check(new_point , trean_data):
	array_dist=[]
	for i in range(len(trean_data)):
		sum_dis=0
		for j in range(len(trean_data[i])-1):
			sum_dis+= (trean_data[i][j]-new_point[j])**2
			
		array_dist.append([sum_dis**0.5 , trean_data[i][len(trean_data[i])-1]])
	array_dist.sort()
	return array_dist
	
def label_prediction(array_dist, threshold):
	count={}
	i=0
	for value in array_dist[:threshold]:
		if value[1] not in count:
			count[value[1]]=1
		else:
			count[value[1]]+=1
		i+=1
	most_common= max(count,key=count.get)
	cont_most_common= count.get(most_common, "Not found")
	count.pop(most_common)
	if len(count)==0 or count.get( max(count,key=count.get)) != cont_most_common:
		return most_common
	else:
		return label_prediction(array_dist, threshold-1)

def Checks_best_threshold():
	threshold_score_list=[]
	teh_best_threshold=[]
	for threshold in range(1,21):
		count=0
		trean_data , test_data = mix_and_split(extract_file())
		for point in test_data:
			vactor_dist = distance_check(point , trean_data)
			result = label_prediction( vactor_dist , threshold)
			#print("\033[48;2;0;225;0mtrue\033[0m" if result == point[4] else "\033[30;41;6mfalse\033[0m")
			count+=1 if result == point[4] else 0
		print(threshold , f"{round(count/len(test_data)*100,2)}%")
		threshold_score_list.append(count/len(test_data))
	print("threshold_score_list" , threshold_score_list)
	
	max_score= max(threshold_score_list)
	#for i in range(len(threshold_score_list)):
	#	if threshold_score_list[i] == max_score:
	#		teh_best_threshold.append(i+1)
	teh_best_threshold = [i+1 for i in range(len(threshold_score_list)) if threshold_score_list[i] == max_score]
	#teh_best_threshold= [i for i in threshold_score_list if i == max_score]
	#teh_best_threshold= threshold_score_list.index(max(threshold_score_list))+1
	return teh_best_threshold
	
#def ():
#	for i in range(len(threshold_score_list)):
#		for j in range(len(threshold_score_list[1])):
	
def main():
	#threshold=5
	#count=0
	#trean_data , test_data = mix_and_split(extract_file())
	itar_NUM= 100
	list_best_threshold=[Checks_best_threshold() for i in range(itar_NUM)]	
	#list_best_threshold=[Checks_best_threshold(trean_data , test_data) for i in range(3)]
	print(list_best_threshold)
	#list_best_threshold= [list_best_threshold[i][j] for i in range(len(list_best_threshold)) for j in range(len(list_best_threshold[i]))]
	list_best_threshold= [i for j in list_best_threshold for i in j]	
	print(list_best_threshold)
	plt.hist(list_best_threshold)
	plt.show() 
	#for point in test_data:
	#	vactor_dist = distance_check(point , trean_data)
	#	result = label_prediction( vactor_dist , threshold)
	#	print("\033[48;2;0;225;0mtrue\033[0m" if result == point[4] else "\033[30;41;6mfalse\033[0m")
	#	count+=1 if result == point[4] else 0
	#print(f"{round(count/len(test_data)*100,2)}%")
	
	
	
if __name__ == '__main__':
	main()
#(((trean_data[0][0]-new_point[0])**2)+((trean_data[0][1]-new_point[1])**2)+((trean_data[0][2]-new_point[2])**2)+((trean_data[0][3]-new_point[0])**2))**0.5
