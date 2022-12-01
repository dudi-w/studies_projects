import shoot2 , alien , event, spaceship , pygame , boom
import game_seting as gs

class Collide_and_score:
	def __init__(self ,group_aliens ,group_spaceship ,screen):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		self.life =  gs.life
		self.score= 0
		self.screen=screen
		self.close= False
	
	def stert_plye(self):
		if not event.check_events_to_stert(self):
			return False
		return True
		
	def control_Collide(self):
		items_collided= pygame.sprite.groupcollide(self.group_spaceship ,self.group_aliens , False,  False)
		if items_collided:
			items_collided=items_collided.popitem()
			for item in items_collided[1]:
				if type(item) is boom.Boom:
					return
				else:
					self.group_aliens.add(boom.Boom(item))
					pygame.mixer.Sound('music/mixkit-falling-hit-757.wav').play()
					self.score_manager(item)
				self.life_manager(items_collided[0] , self.group_spaceship)

	def life_manager(self , item_collid, group_spaceship):
		if type(item_collid) is spaceship.Spaceship:
			self.life -=  1
			self.score -= 200
			if self.life:
				self.group_spaceship.add(spaceship.Spaceship(gs.screen_size))
		item_collid.kill()
	
	def score_manager(self , item_collid):
		if type(item_collid) is alien.Alien:
			self.score += 100
		elif type(item_collid) is shoot2.Shooting:
			self.score += 200
		item_collid.kill()
		
	def add_life(self):
		self.life +=1
		
		
	def update(self ,group_aliens, group_spaceship ):
		self.group_aliens= group_aliens
		self.group_spaceship= group_spaceship
		self.control_Collide()
	
	def end_plye(self):
		end = 1
		print("\033[38;2;100;25;200m" ,self.life , self.group_aliens, "\033[0m")
		if not self.life or not len(self.group_aliens):
			end= 0
		return end

	def stert_text_show(self):
		font_game1= pygame.font.Font(gs.FONT2, 30)
		font_game2= pygame.font.Font(gs.FONT2, 20)
		text1= font_game1.render('Welcome to space!!!', 1, (225,225,200))
		text2= font_game2.render('Defend your land from aliens trying to take it over', 1, (225,225,200))
		text3= font_game1.render('Press the 1 key to start the game', 1, (225,0,200))
		self.screen.blit(text1, (200,50 ))
		self.screen.blit(text2, (5,200 ))
		self.screen.blit(text3, (20,800 ))


	def text_show(self):
		font_game= pygame.font.Font(gs.FONT1, 30)
		text_life= font_game.render(f'life  --{self.life}--', 1, (100,0,100))
		text_score= font_game.render(f'score  --{self.score}--', 1, (0,100,100))
		self.screen.blit(text_life, (50,30))
		self.screen.blit(text_score, (50,60))
		
		
	def end_text_show(self):
		font_game1= pygame.font.Font(gs.FONT2, 80)
		font_game2= pygame.font.Font(gs.FONT2, 50)
		if self.life:
			text_end= font_game1.render('you won', 1, (225,225,200))
		else:
			text_end= font_game1.render('you lose', 1, (225,225,200))
		text_score= font_game2.render(f'your score is *{self.score}*', 1, (225,225,0))
		self.screen.blit(text_end, (100, gs.height/2 ))
		self.screen.blit(text_score, (20, (gs.height/2)+150 ))
