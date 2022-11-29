import pygame

class Aliens(pygame.sprite.Group):
	def __init__(self, screen_width):
		super(self.__class__ , self).__init__()
		self.image= pygame.image.load("images/pngegg.png")
		self.image_width, self.inage_height = self.image.get_size()
		self.screen_width=screen_width[0]
		for i in range(200,200+(self.image_width*15),self.image_width+10):
			for j in range(100, 100+(self.inage_height*3), self.inage_height-35):
				temp= Alien(self.image , i, j)
				self.add(temp)
		self.direction= True
	
	def screen_collision_test(self):
		for i in self:
			#print(i.rect.left , i.rect.right , self.screen_width)
			if i.rect.left< 0 or i.rect.right > self.screen_width:
				return True
				
				
	
	def update(self):
		if self.screen_collision_test():
			for i in self:
				i.direction[0]= -(i.direction[0])
				i.direction[1]= 5
		elif self.sprites()[0].direction[1]>  0:
				for i in self:
					i.direction[1]= 0
		super().update()
		

class Alien(pygame.sprite.Sprite):
	def __init__(self, image, pos_x, pos_y):
		super(self.__class__ , self) .__init__()
		self.image= image
		self.rect= self.image.get_rect\
		(center=(pos_x, pos_y))
		self.direction= [1 ,0]

	def move_alien(self):
		self.rect = self.rect.move(self.direction)
		
		#print("afdqwereafds	2gr2f")
	def kill_alien(self):
		pass
	
	def update(self):
		self.move_alien()
		
