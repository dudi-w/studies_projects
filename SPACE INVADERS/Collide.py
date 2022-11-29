import pygame
import game_seting as gs

class Collide:
	def __init__(self ,group_aliens ,group_ship_shoot ,group_aliens_shoot ,spaceship):
		self.group_aliens= group_aliens
		self.group_aliens_shoot= group_aliens
		self.aliens_and_aliens_shoot_group=\
			gs.unit_pygame_groups(group_aliens,group_aliens)
		self.spaceship_and_spaceship_shoots_group=\
			gs.unit_pygame_groups(group_aliens,group_aliens)
		self.group_ship_shoot= group_ship_shoot
		self.life = 
		self.scor =
		 
	def control_Collide(self):

		 
		for i in range(len(group_aliens_shoot.sprits))
			
		pygame.sprite.groupcollide()
