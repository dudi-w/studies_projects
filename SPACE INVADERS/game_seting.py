import pygame

def unit_pygame_groups(group1 ,gruop2):
	new_group= pygame.sprite.Group
	new_group.add(*group1.sprits(), *group2.sprits())
	return new_group
	
width, height = 1536, 864
beck_ground_image ="images/WallpaperDog-20353652.jpg"
ship_speed= 4
ship_shot_image= "/home/mefathim-tech-11/s06.dudivi/SPACE INVADERS/images/pngegg (7).png"
alien_shot_image ="/home/mefathim-tech-11/s06.dudivi/SPACE INVADERS/images/pngegg (8).png"
spaceship_image="images/invaders3.jpg"
paceship_shoot_direction=[0,-15]
alien_shoot_direction= [0,10]
