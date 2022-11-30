import pygame , time
import game_seting as gs

class Boom(pygame.sprite.Sprite):
	def __init__(self, spaceship ):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load(gs.image_boom)
		self.rect= self.image.get_rect(center=		(spaceship.rect[0]+spaceship.image.get_width()/2 , spaceship.rect[1] ))
		self.time= time.time()
		print("\033[38;2;200;25;0mbooooooooooooom\033[0m")
	
	def kill_shoot(self):
		print("\033[38;2;0;255;0mbooooooooooooom\033[0m")
		if time.time() - self.time >0.2:
			self.kill()
			
	
	def add_boom(self ,spaceship ):
		pass
	
	def update(self):
		self.kill_shoot()
