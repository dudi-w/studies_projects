import sys, pygame
import spaceship
import shoot2 , alien
import game_seting as gs
pygame.init()

size = gs.width, gs.height
screen = pygame.display.set_mode(size)
spaceship= spaceship.Spaceship(size)
group1=pygame.sprite.Group()
aliens_group= alien.Aliens(size)
IMAGE1=pygame.image.load(gs.beck_ground_image)

while True:
	
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	else:
		key_input = pygame.key.get_pressed()
		if key_input[pygame.K_SPACE]:
			if not group1:
				shoot2.Shooting(spaceship, group1)
				
	spaceship.move_spaceship(key_input ,size)
	screen.blit(IMAGE1 , (0,0))
	group1.update()
	aliens_group.update()
	aliens_group.draw(screen)
	group1.draw(screen)
	screen.blit(spaceship.image, spaceship.image_rect)
	pygame.display.update()
	pygame.display.flip()
