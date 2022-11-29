import pygame
import game_seting as gs

class Shooting(pygame.sprite.Sprite):
	def __init__(self,spaceship ,group1):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load("images/missile.png")
		self.rect= self.image.get_rect(center=		(spaceship.image_rect[0]+spaceship.image.get_width()/2 , spaceship.image_rect[1] ))
		group1.add(self)
		
	def move_shoot(self):
		speed =[0, -15]
		self.rect = self.rect.move(speed)
	
	def kill_shoot(self):
		if self.rect[1]<0 or self.rect[1]> gs.height:
			self.kill()
	
	def update(self):
		self.kill_shoot()
		self.move_shoot()
