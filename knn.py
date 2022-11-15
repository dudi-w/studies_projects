import csv
import random

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
		
	


def main():
	threshold=10
	count=0
	trean_data , test_data = mix_and_split(extract_file())
	for point in test_data:
		vactor_dist = distance_check(point , trean_data)
		result = label_prediction( vactor_dist , threshold)
		if result == point[4]:
			count+=1
			print ("\033[3;32;51mtrue\033[0m")
		else:
			print ("\033[30;41;6mfalse\033[0m")
	print(f"{count}/{len(test_data)}")
	print(f"{round(count/len(test_data)*100,2)}%")
if __name__ == '__main__':
	main()
#(((trean_data[0][0]-new_point[0])**2)+((trean_data[0][1]-new_point[1])**2)+((trean_data[0][2]-new_point[2])**2)+((trean_data[0][3]-new_point[0])**2))**0.5
