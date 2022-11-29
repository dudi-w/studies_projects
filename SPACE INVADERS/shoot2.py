import pygame
import game_seting as gs

class Shooting(pygame.sprite.Sprite):
	def __init__(self, spaceship, image ,diraction):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load(image)
		self.diraction= diraction
		
		self.rect= self.image.get_rect(center=		(spaceship.rect[0]+spaceship.image.get_width()/2 , spaceship.rect[1] ))
		
	def move_shoot(self):
		self.rect = self.rect.move(self.diraction)
	
	def kill_shoot(self):
		if self.rect[1]<0 or self.rect[1]> gs.height:
			self.kill()
			print("123456456")
	
	def update(self):
		self.kill_shoot()
		self.move_shoot()
