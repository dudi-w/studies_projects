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
	
def distance_check(naw_point , trean_data)
	array_dist=[]
	for i in range(len(trean_data):
		for j in range(len(trean_data[i])-1)
			sum_dis+= (trean_data[i][j]-new_point[j])**2
		array_dist.append([sum_dis**0.5 , trean_data[i][len(trean_data[i])-1]]
	array_dist.sort()
	return array_dist
	
def label_prediction(array_dist, trashold):
	count={}
	i=0
	while(i<trashold)
		for value in array_dist:
			if value[1] not in count:
				count[value[1]]=1
			else:
				count[value[1]]+=1
		i+=1
		
	most_common= max(count,key=count.get)
	cont_most_common= count.get(most_common, "Not found"))
	count.pop(most_common)
	if count.get(max(count,key=count.get)) != cont_most_common:
		return cont_most_common
	else
		return label_prediction(array_dist, trashold-1):
		
	


def main():
	trashold=5
	trean_data , test_data = mix_and_split(extract_file())[1][0]
	for point in test_data:
		vactor_dist = distance_check(point , trean_data)
		result = label_prediction( vactor_dist , trashold)
		print (result)
if __name__ == '__main__':
	main()
#(((trean_data[0][0]-new_point[0])**2)+((trean_data[0][1]-new_point[1])**2)+((trean_data[0][2]-new_point[2])**2)+((trean_data[0][3]-new_point[0])**2))**0.5
