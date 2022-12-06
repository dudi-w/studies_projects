import random
import matplotlib.pyplot as plt

def create_arr(n):
	arr=[i for i in range(n)]
	random.shuffle(arr)
	return arr
	
def check_chain(arr):
	results=[]
	for i in range(len(arr)):
		count=0
		x=i
		while not i == arr[x]:
			count+=1
			x= arr[x]
		results.append(count)
	return results

#rendom-fanction
def check_chain2(arr):
	results=[]
	for i in range(len(arr)):
		count=0
		x=random.randint(0,len(arr))
		while not i == arr[x%len(arr)]:
			count+=1
			x+=1
		results.append(count)
	return results

def probabilistic(num_to_loop ,num_to_check ,x):
	arr=[]
	for i in range(num_to_loop):
		for results in check_chain(create_arr(num_to_check)):
			if results > num_to_check*(x/100):
				arr.append(1)
				break
	print (f"{round((1-sum(arr)/num_to_loop)*100,2)}%")
	return 1-sum(arr)/num_to_loop
	
def main():
	y_points=[]
	for i in range(1,101):
		y_points.append(probabilistic(1000, 100, i))
	x_points=[x/100 for x in range(1,101)]
	plt.plot(x_points, y_points)
	plt.show()
	
	
if __name__ == "__main__":
    main()
