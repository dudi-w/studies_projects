import csv
import random
import math
import array

def extract_file(file_name):
	with open(file_name, 'r', newline='') as data:
		csvreader = csv.reader(data)
		data= list(csvreader)
		random.shuffle(data)
	return data

class data_NB:
	def __init__(self):
		self.poisonous={}
		self.size_poisonous=self.poisonous.get("0p",0)
		self.edible={}
		self.size_edible=self.edible.get("0p",0)
		self.results=[]

	def add_to_database(self, arr_data):
		for attribut in arr_data:
			if arr_data[0]=='0p':
				self.poisonous[attribut]= self.poisonous.get(attribut,0)+1
				self.poisonous.pop('', 0)
			else:
				self.edible[attribut]= self.edible.get(attribut,0)+1
				self.edible.pop('', 0)
				
	def type_prediction(self, arr_data):
		real_result= arr_data[0]
		x=self.Probabilistic_prediction(arr_data[1:])
		r = 'poisonous' if x>0.7 else 'edible'
		t= 1 if r== 'poisonous' and real_result== '0p' or  r== 'edible' and real_result== '0e' else 0
		self.results.append(t)
		if t !=1 and r=='poisonous':
			print(r, t, x)
			return 1
		else:
			return 0
		
	
	def Probabilistic_prediction(self, data_arr):
		x= self.sum_prob(data_arr ,'poisonous')
		y= self.sum_prob(data_arr ,'edible')
		return x/(x+y)
		
	def sum_prob(self , data_to_check ,name):
		sum_p=0
		for attribut in data_to_check:
			sum_p += math.log(self.p_aIt(attribut, name))
		return math.exp(sum_p)
		
	def p_aIt(self, attribut ,name):
		if name == 'poisonous':
			tIa= (self.poisonous.get(attribut,0)+0.5)/(self.size_poisonous+1)
		else:
		 	tIa= (self.edible.get(attribut,0)+0.5)/(self.size_edible+1)
		return tIa


def main():
	
	file_name="agaricus-lepiota.data"
	i=300
	p=0
	while i>0:
		mushroom_database= data_NB()
		information_about_mushrooms= extract_file(file_name)
		_sum=0
		for mushroom in information_about_mushrooms:
			mushroom_attributes= [str(i)+mushroom[i] if mushroom[i] != '?' else '' for i in range(len(mushroom))]
			_sum += mushroom_database.type_prediction(mushroom_attributes)
			mushroom_database.add_to_database(mushroom_attributes)
		#print(mushroom_database.poisonous , "\n" , mushroom_database.edible , mushroom_database.results)
		x=array.array('i', mushroom_database.results)
		y= x.count(1)
		p+=_sum/len(mushroom_database.results)
		print(i ,'\t' ,_sum ,"\t" ,_sum/len(mushroom_database.results))
		i-=1
	print(p/300)
		
if __name__ == '__main__':
	main()
