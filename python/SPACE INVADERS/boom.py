import pygame , time
import game_seting as gs

class Boom(pygame.sprite.Sprite):
	def __init__(self, spaceship ):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load(gs.image_boom)
		print(spaceship.rect , spaceship.rect.center)
		self.rect= self.image.get_rect(center=	spaceship.rect.center)
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
