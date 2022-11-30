import pygame

def unit_pygame_groups(group1 ,gruop2):
	new_group= pygame.sprite.Group
	new_group.add(*group1.sprits(), *group2.sprits())
	return new_group

life=3
screen_size= width, height = 1536, 864
beck_ground_image ="images/WallpaperDog-10809602.jpg"
ship_speed= 4
image_boom="images/pngegg (8).png"
ship_shot_image= "images/pngegg (7).png"
alien_shot_image ="images/pngegg (8).png"
spaceship_image="images/spaceship.png"
paceship_shoot_direction=[0,-15]
alien_shoot_direction= [0,10]
