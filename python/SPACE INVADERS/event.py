import sys, pygame
import spaceship
import shoot2 , alien, master
import game_seting as gs

def check_events_to_plye(aliens_group, ship_group,  plye_manager):
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	else:
		key_input = pygame.key.get_pressed()
		if key_input[pygame.K_SPACE]:
			if len(ship_group)<=4:
				ship_group.create_shot()
	
	if key_input[pygame.K_KP_PLUS]:
		plye_manager.add_life()
	
	if key_input[pygame.K_w]:
		for item in aliens_group:
			item.kill()
		
	if key_input[pygame.K_l]:
		plye_manager.life=0
			
	ship_group.move_spaceship(key_input ,gs.screen_size)
	
def  check_events_to_stert(plye_manager):
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	key_input = pygame.key.get_pressed()
	if key_input[pygame.K_1]:
		return False
	return True

def  check_events_to_end(plye_manager):
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	key_input = pygame.key.get_pressed()
	if key_input[pygame.K_1]:
		pass
	if key_input[pygame.K_2]:
		sys.exit()
	
	
	
		
