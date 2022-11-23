class Constitution:
	
	def __init__(self):
		self.rules = []
		
	def __repr__(self):
		s = 'constitution of lala_land contains the followin rules: \n'
		return s + '\n'.join(self.rules)
		
	def add_rule(self, rule):
		self.rules.append(rule)
		
	def remove_rule(self, rule):
		self.rules.remove(rule)

