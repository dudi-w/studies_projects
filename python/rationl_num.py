import math
class Rational:
	def __init__(self, numerator , denominator=1):
		if denominator==0:
			raise ZeroDivisionError('division by zero')
		self.numerator= int(numerator)
		self.denominator= int(denominator)
		
	def __repr__(self):
		return str(self.numerator)+'/'+str(self.denominator)

	def add(self ,other_rational):
		temp1_numerator= self.numerator*other_rational.denominator
		temp_denominator= self.denominator*other_rational.denominator
		temp2_numerator= other_rational.numerator*self.denominator
		new_rational= Rational(temp1_numerator+temp2_numerator, temp2_numerator)
		return new_rational
		
	def is_equal(self ,other_rational):
		temp1_numerator= self.numerator*other_rational.denominator
		temp2_numerator= other_rational.numerator*self.denominator
		return bool(temp1_numerator==temp2_numerator)
	
	def  shrink(self):
		x= math.gcd(self.numerator ,self.denominator)
		new_rational= Rational(self.numerator/x , self.denominator/x)
		return new_rational
		
def main():
	num1=Rational(1, 2)
	num2=Rational(3)
	num3=Rational(264,414)
	num4=Rational(5,30)
	num5= num1.add(num2)
	print (num3.is_equal(num1))
	print (num4.is_equal(num1))
	num6= num3.shrink()
	num7= num4.shrink()
	print(num6 ,num7)
	
if __name__ == '__main__':
	main()
