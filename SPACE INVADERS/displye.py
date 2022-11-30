import sys, pygame
import spaceship
import shoot2 , alien, collide , event
import game_seting as gs
pygame.init()

size = gs.width, gs.height
screen = pygame.display.set_mode(size)
IMAGE1=pygame.image.load(gs.beck_ground_image)

ship_group= spaceship.Spaceship_and_shoot(size)
clock = pygame.time.Clock()
aliens_group= alien.Aliens(size)
score_manager = collide.Collide_and_score(aliens_group , ship_group ,screen)

while score_manager.end():
	event.check_events(ship_group, score_manager)
	screen.blit(IMAGE1 , (0,0))
	score_manager.update(aliens_group , ship_group)
	ship_group.update()
	aliens_group.update()
	aliens_group.draw(screen)
	ship_group.draw(screen)
	score_manager.text_show()
	pygame.display.update()
	pygame.display.flip()
	clock.tick(30)
	
