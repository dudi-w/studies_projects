import sys, pygame
import spaceship
import shoot2 , alien, collide
import game_seting as gs
pygame.init()

size = gs.width, gs.height
screen = pygame.display.set_mode(size)
IMAGE1=pygame.image.load(gs.beck_ground_image)

ship_group= spaceship.Spaceship_and_shoot(size)
clock = pygame.time.Clock()

#spaceship= spaceship.Spaceship(size, ship_group)
aliens_group= alien.Aliens(size)

s = collide.Collide_and_scor(aliens_group , ship_group)

while True:
	
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	else:
		key_input = pygame.key.get_pressed()
		if key_input[pygame.K_SPACE]:
			if len(ship_group)==1:
				ship_group.create_shot()
				
	ship_group.sprites()[0].move_spaceship(key_input ,size)
	screen.blit(IMAGE1 , (0,0))
	s.update(aliens_group , ship_group)
	ship_group.update()
	aliens_group.update()
	aliens_group.draw(screen)
	ship_group.draw(screen)
	#screen.blit(spaceship.image, spaceship.image_rect)
	pygame.display.update()
	pygame.display.flip()
	clock.tick(30)
