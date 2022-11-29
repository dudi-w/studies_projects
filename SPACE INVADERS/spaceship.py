import pygame , shoot2
import game_seting as gs



class Spaceship_and_shoot(pygame.sprite.Group):
	def __init__(self, screen_size):
		super(self.__class__ , self).__init__()
		self.add(Spaceship(screen_size))
	
	def create_shot(self):
		self.add( shoot2.Shooting(self.sprites()[0] , gs.ship_shot_image , gs.paceship_shoot_direction) )


class Spaceship(pygame.sprite.Sprite):
	def __init__(self, screen_size):
		super(self.__class__ , self) .__init__()
		self.image= pygame.image.load( gs.spaceship_image)
		self.image= pygame.transform.scale(self.image, (150,80))
		self.rect= self.image.get_rect(center=\
		(screen_size[0]/2 \
		,screen_size[1]-(self.image.get_height()/2)))

	def move_spaceship(self, key_input, screen_size):
		speed =[0, 0]
		if self.rect.right >= screen_size[0]:
				speed[0] = 0
		if self.rect.left <= 0:
				speed[0] = 0
				
		if key_input[pygame.K_RIGHT]:
			if self.rect.right >= screen_size[0]:
				speed[0] = 0
			else:
				speed[0] =gs.ship_speed

		if key_input[pygame.K_LEFT]:
			if self.rect.left <= 0:
				speed[0] = 0
			else:
				speed[0] = -gs.ship_speed
			
		self.rect = self.rect.move(speed)
