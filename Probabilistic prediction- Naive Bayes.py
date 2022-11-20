import csv
import random
import math

def extract_file(file_name):
	with open(file_name, 'r', newline='') as data:
		csvreader = csv.reader(data)
		data= list(csvreader)
	return data


#mix the data, and split the data to trean VS test
def mix_and_split(data):
	random.shuffle(data)
	trean_data= data[:int(len(data)*0.97)]
	test_data= data[int(len(data)*0.97):]
	print(test_data , len(test_data))
	return trean_data , test_data
	
def separates_and_simplifies_the_data(data):

	poisonous=[str(i)+arr[i] if arr[i] != '?' and i != 0 else '' for arr in data if arr[0]=='p' for i in range(len(arr))]
	edible= [str(i)+arr[i] if arr[i]  != '?' and i != 0 else '' for arr in data if arr[0]=='e' for i in range(len(arr))]
	print(edible ,len(edible) , len (poisonous) , len (data))
	return poisonous , edible

def cont_attribut(arr):
	count={}
	for attribut in arr:
		count[attribut]= count.get(attribut,0)+1
	count.pop('')
	print(count , len(count))
	return count

def p_aIt(attribut , count, num_type):
	
	tIa= (count1.get(attribut,0)+k)/(num_type1+2*k)
	
	#p_a= count1.get(attribut,0)+count2.get(attribut,0)
	
def sum_prob(data_to_check ,count ,num_type):
	for attribut in data_to_check:
		sum_p+= math.log(p_aIt(attribut ,count, num_type))
	return math.exp(sum_p)

def Probabilistic_prediction(data_to_check ,count1 , num_type1 ,count2 , num_type2):
	x= sum_prob(data_to_check ,count1 , num_type1)
	y=sum_prob(data_to_check ,count2 , num_type2)
	return x/(x+y)
	
def main():
	file_name="agaricus-lepiota.data"
	trean_data , test_data = mix_and_split(extract_file(file_name))
	poisonous , edible = separates_and_simplifies_the_data(trean_data)
	num_poisonous= len(poisonous)
	num_edible= len(edible)
	poisonous_count=cont_attribut(poisonous)
	edibles_count=cont_attribut(edible)
	for line in test_data:
		attributes= [str(i)+line[i] if line[i] != '?' and i != 0 else '' for i in range(len(line))]
		print(attributes)
		#Probabilistic_prediction(attributes ,count1 , num_type1 ,count2 , num_type2)
		
		
if __name__ == '__main__':
	main()
