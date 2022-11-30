import sys, pygame
import spaceship
import shoot2 , alien, collide
import game_seting as gs

def check_events(ship_group,  score_manager):
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	else:
		key_input = pygame.key.get_pressed()
		if key_input[pygame.K_SPACE]:
			if len(ship_group)<=2:
				ship_group.create_shot()
	
	if key_input[pygame.K_l]:
		score_manager.add_life()
		
	ship_group.move_spaceship(key_input ,gs.screen_size)
