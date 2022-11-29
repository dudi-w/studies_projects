import pygame
import game_seting as gs

class Collide_and_scor:
	def __init__(self ,group_aliens ,group_spaceship ):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		 
	def control_Collide(self):
		x=pygame.sprite.groupcollide(self.group_aliens , self.group_spaceship , True, True)
		return x
	
	
	def update(self ,group_aliens, group_spaceship ):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		x= self.control_Collide()
