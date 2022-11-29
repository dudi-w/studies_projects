import pygame
import game_seting as gs

class Spaceship(pygame.sprite.Sprite):
	def __init__(self, screen_size):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load("images/invaders3.jpg")
		self.image= pygame.transform.scale(self.image, (150,80))
		self.image_rect= self.image.get_rect(center=\
		(screen_size[0]/2 \
		,screen_size[1]-(self.image.get_height()/2)))

	def move_spaceship(self, key_input, screen_size):
		speed =[0, 0]
		if self.image_rect.right >= screen_size[0]:
				speed[0] = 0
		if self.image_rect.left <= 0:
				speed[0] = 0
				
		if key_input[pygame.K_RIGHT]:
			if self.image_rect.right >= screen_size[0]:
				speed[0] = 0
			else:
				speed[0] =gs.ship_speed

		if key_input[pygame.K_LEFT]:
			if self.image_rect.left <= 0:
				speed[0] = 0
			else:
				speed[0] = -gs.ship_speed
			
		self.image_rect = self.image_rect.move(speed)

		

