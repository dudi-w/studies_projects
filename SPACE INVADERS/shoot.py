import pygame,sys

class Shooting(pygame.sprite.Sprite):
	def __init__(self,spaceship ,screen, screen_size):
		pygame.sprite.Sprite.__init__(self)
		self.shoot= pygame.draw.rect(screen, (0,255,0), pygame.Rect(spaceship.image_rect[0]+75, spaceship.image_rect[1], 5, 20))


	def move_shoot(self, screen):
		speed =[0, -3]
		self.shoot.move_ip(speed[0], speed[1])
		#pygame.draw.rect(screen, (0,255,0), self.shoot)
		#self.shoot.update()
		return self
