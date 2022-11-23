import constitution
class Minister:
	def __init__(self, name , party):
		self._name = name
		self.party = party
	
	def __repr__(self):
		return self.name
		
	def add_rule(self, rule, constitution):
		constitution.add_rule(rule)
		print (f"A new rule by {self.name} was acceptd")
		
	def cancel_rule(self, rule, constitution):
		constitutionre.move_rule(rule)
		print(f"rule was canceled by {self.name}")

def main():
	constitution1 = constitution.Constitution()
	gafny = Minister("moishe gafny" , "degel htore")
	gafny.add_rule('rule1: sweet drink' , constitution1)
	gafny._name = "lll"
	print(constitution1,'\n',gafny)
	
	
	
if __name__ == '__main__':
	main()
