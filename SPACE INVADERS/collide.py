import shoot2 , alien, collide , event, spaceship , pygame , boom
import game_seting as gs

class Collide_and_score:
	def __init__(self ,group_aliens ,group_spaceship ,screen):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		self.life =  gs.life
		self.score= 0
		self.screen=screen
	
	def control_Collide(self):
		items_collided= pygame.sprite.groupcollide(self.group_spaceship ,self.group_aliens , 1,  0)
		if items_collided:
			items_collided=items_collided.popitem()
			self.life_manager(items_collided[0] , self.group_spaceship)
			for item in items_collided[1]:
				self.group_aliens.add(boom.Boom(item))
				self.score_manager(item)

	def life_manager(self , item_collid, group_spaceship):
		if type(item_collid) is spaceship.Spaceship:
			self.life -=  1
			if self.life>0:
				self.group_spaceship.add(spaceship.Spaceship(gs.screen_size))

	
	def score_manager(self , item_collid):
		if type(item_collid) is alien.Alien:
			self.score += 100
		elif type(item_collid) is shoot2.Shooting:
			self.score += 200
		item_collid.kill()
			
	def add_life(self):
		self.life +=1
		print(self.life)
		
	def update(self ,group_aliens, group_spaceship ):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		self.control_Collide()
	
	def end(self):
		end = 1
		print("\033[38;2;100;25;200m" ,self.life , self.group_aliens, "\033[0m")
		if not self.life or not len(self.group_aliens):
			end= 0
		return end
	
	def text_show(self):
		font_game= pygame.font.Font('/home/mefathim-tech-11/s06.dudivi/SPACE INVADERS/fonts/OriginTech personal use.ttf', 30)
		text_life= font_game.render(f'life  --{self.life}--', 1, (100,0,100))
		text_score= font_game.render(f'score  --{self.score}--', 1, (0,100,100))
		self.screen.blit(text_life, (50,30))
		self.screen.blit(text_score, (50,60))
