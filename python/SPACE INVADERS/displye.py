import sys, pygame
import spaceship
import shoot2 , alien, master , event
import game_seting as gs
pygame.init()

pygame.mixer.init()
pygame.mixer.music.load('music/gaming-8bit-music-hyperloop-124334.mp3')
pygame.mixer.music.play()

size = gs.width, gs.height
screen = pygame.display.set_mode(size)
IMAGE1=pygame.image.load(gs.beck_ground_image)
IMAGE2=pygame.image.load(gs.beck_ground_image2)
ship_group= spaceship.Spaceship_and_shoot(size)
clock = pygame.time.Clock()
aliens_group= alien.Aliens(size)
plye_manager = master.Collide_and_score(aliens_group , ship_group ,screen)

while plye_manager.stert_plye():
	event.check_events_to_stert(plye_manager)
	screen.blit(IMAGE2 , (0,0))
	plye_manager.stert_text_show()
	pygame.display.update()
	pygame.display.flip()
	clock.tick(30)
	
	
while plye_manager.end_plye():
	event.check_events_to_plye(aliens_group, ship_group, plye_manager)
	screen.blit(IMAGE1 , (0,0))
	plye_manager.update(aliens_group , ship_group)
	ship_group.update()
	aliens_group.update()
	aliens_group.draw(screen)
	ship_group.draw(screen)
	plye_manager.text_show()
	pygame.display.update()
	pygame.display.flip()
	clock.tick(30)
	
	
while not plye_manager.close:
	event.check_events_to_end(plye_manager)
	screen.blit(IMAGE1 , (0,0))
	aliens_group.draw(screen)
	ship_group.draw(screen)
	plye_manager.end_text_show()
	pygame.display.update()
	pygame.display.flip()
	clock.tick(30)

	
