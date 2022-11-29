import pygame
import shoot2, random
import game_seting as gs
import time

class Aliens(pygame.sprite.Group):
	def __init__(self, screen_width):
		super(self.__class__ , self).__init__()
		self.image= pygame.image.load("images/pngegg.png")
		self.image_width, self.inage_height = self.image.get_size()
		self.screen_width= screen_width[0]
		self.only_aliens_grop= pygame.sprite.Group()
		self.last_call= 0
		for i in range(200,200+(self.image_width*15),self.image_width+10):
			for j in range(100, 100+(self.inage_height*3), self.inage_height-35):
				temp= Alien(self.image , i, j)
				temp.add(self.only_aliens_grop, self)
		#self.direction= True
	
	def create_shot(self):
		print (len(self.only_aliens_grop)-len(self))
		self.add( shoot2.Shooting(random.choice(		self.only_aliens_grop.sprites()), gs.alien_shot_image , gs.alien_shoot_direction) )
	
	def screen_collision_test(self):
		for i in self:
			#print(i.rect.left , i.rect.right , self.screen_width)
			if i.rect.left< 0 or i.rect.right > self.screen_width:
				return True
						
	def update(self):
		if time.time()- self.last_call> random.random()*2 and len(self)- len(self.only_aliens_grop) < 4:
			self.last_call=time.time()
			self.create_shot()
		if self.screen_collision_test():
		
			for i in self.only_aliens_grop:
				i.diraction[0]= -(i.diraction[0])
				i.diraction[1]= 5
		elif self.only_aliens_grop.sprites()[0].diraction[1]>  0:
				for i in self.only_aliens_grop:
					i.diraction[1]= 0
		super().update()
		
		

class Alien(pygame.sprite.Sprite):
	def __init__(self, image, pos_x, pos_y):
		super(self.__class__ , self) .__init__()
		self.image= image
		self.rect= self.image.get_rect\
		(center=(pos_x, pos_y))
		self.diraction= [1 ,0]

	def move_alien(self):
		self.rect = self.rect.move(self.diraction)
		
	def kill_alien(self):
		pass
	
	def update(self):
		self.move_alien()
		
