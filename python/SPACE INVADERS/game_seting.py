import pygame

def unit_pygame_groups(group1 ,gruop2):
	new_group= pygame.sprite.Group
	new_group.add(*group1.sprits(), *group2.sprits())
	return new_group

life=3
screen_size= width, height = 1536, 864
FONT1= 'fonts/OriginTech personal use.ttf'
FONT2= 'fonts/SwipeRaceDemo.ttf'
beck_ground_image ="images/WallpaperDog-10809602.jpg"
beck_ground_image2='images/WallpaperDog-20353652.jpg'
ship_speed= 6
image_boom='images/pngegg (9).png'
ship_shot_image= "images/pngegg (7).png"
alien_shot_image ="images/pngegg (8).png"
spaceship_image="images/spaceship.png"
paceship_shoot_direction=[0,-15]
alien_shoot_direction= [0,10]
