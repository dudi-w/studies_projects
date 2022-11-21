import csv
import random
import math

def extracts_file_and_converts_to_list_type(file_name):
	with open(file_name, 'r', newline='') as data:
		csvreader = csv.reader(data)
		data= list(csvreader)
	return data	
	
class Data_NB:
	def __init__(self ,name_type1, short_name_type1, name_type2 ,short_name_type2):
		self.type1= name_type1
		self.type2= name_type2
		self.sn_type1= short_name_type1
		self.sn_type2= short_name_type2
		self.dic_type1={}
		self.size_dic_type1= self.dic_type1.get(short_name_type1 ,0)
		self.dic_type2={}
		self.size_dic_type2= self.dic_type2.get(short_name_type2 ,0)
		self.results=[]

	def add_to_database(self, arr_data):
		for attribut in arr_data:
			if arr_data[0]==self.type1:
				self.dic_type1[attribut]= self.dic_type1.get(attribut,0)+1
				self.dic_type1.pop('', 0)
			else:
				self.dic_type2[attribut]= self.dic_type2.get(attribut,0)+1
				self.dic_type2.pop('', 0)
	'''
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


	'''
	def type_prediction(self, arr_data):
		real_result= arr_data[0]
		prob= self.Probabilistic_prediction(arr_data[1:])
		
		prob_name_type = self.type1 if prob>0.5 else self.type2
		print ("1111111" , prob)
		#Checks whether the result matches the real value
		if prob_name_type== self.type1 and real_result== self.sn_type1 or prob_name_type== self.type2 and real_result== self.sn_type2:
			score= True
		else:
			score= False
		self.results.append(score)
		
		return (prob_name_type ,score)
		
	def Probabilistic_prediction(self, data_arr):
		x= self.sum_prob(data_arr ,self.type1)
		y= self.sum_prob(data_arr ,self.type2)
		print ("121212" , x ,y)
		return x/(x+y)
		
	def sum_prob(self , data_to_check ,name):
		sum_p=0
		for attribut in data_to_check:
			sum_p += math.log(self.p_aIt(attribut, name))
		print("1234" ,math.exp(sum_p))
		return math.exp(sum_p)
		
	def p_aIt(self, attribut , name):
		k=0.5
		if name == self.type1:
			tIa= (self.dic_type1.get(attribut,0)+k)/(self.size_dic_type1+2*k)
		else:
			tIa= (self.dic_type2.get(attribut,0)+k)/(self.size_dic_type2+2*k)
		return tIa


def main():
	
	file_name="agaricus-lepiota.data"
	information_about_mushrooms= extracts_file_and_converts_to_list_type(file_name)
	#Shuffle the information for accuracy
	random.shuffle(information_about_mushrooms)
	mushroom_database= Data_NB('poisonous' ,"0p" ,'edible', "0e")
	_sum=0
	for mushroom in information_about_mushrooms:
		mushroom_attributes= [str(i)+mushroom[i] if mushroom[i] != '?' else '' for i in range(len(mushroom))]
		prob_name_type ,score = mushroom_database.type_prediction(mushroom_attributes)
		print(prob_name_type ,score)
		mushroom_database.add_to_database(mushroom_attributes)
	#print(mushroom_database.poisonous , "\n" , mushroom_database.edible , mushroom_database.results)
	x=array.array('i', mushroom_database.results)
	y= x.count(1)
	print(_sum ,"\t" ,_sum/len(mushroom_database.results))
			
if __name__ == '__main__':
	main()
