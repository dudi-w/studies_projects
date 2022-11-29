import pygame
import game_seting as gs

def unit_pygame_groups(group1 ,gruop2):
	new_group= pygame.sprite.Group
	new_group.add(*group1.sprits(), *group2.sprits())
	return new_group
	
width, height = 1536, 864
beck_ground_image ="images/WallpaperDog-20353652.jpg"
ship_speed= 4
