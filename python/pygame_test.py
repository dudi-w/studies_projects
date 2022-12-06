import sys, pygame
pygame.init()

size = width, height = 1250, 950
speed = [2, 0]
black = 0, 125, 66

screen = pygame.display.set_mode(size)

ball = pygame.image.load("gip.gif")
ballrect = ball.get_rect()
ball2 = pygame.image.load("gip.gif").convert()
cont=10000
key_p = 0
while cont>0:
	
	pygame.key.set_repeat(50,1)
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
	#pygame.event.wait(1)
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_RIGHT:
				key_p =key_p+50
				speed[0]= -speed[0]
				pygame.key.get_repeat()
			else:
				pass
	
	mous_p=pygame.mouse.get_pos()
	print (mous_p)
    	
	ballrect = ballrect.move(speed)
	print (ballrect)
	if ballrect.left < 0 or ballrect.right > width:
		speed[0] = -speed[0]
		black = 30, 125, 66
	if ballrect.top < 0 or ballrect.bottom > height:
		speed[1] = -speed[1]
		black = 200, 125, 66

	screen.fill(black)
	screen.blit(ball2 ,(key_p ,600))
	screen.blit(ball, ballrect)
	pygame.display.flip()
	cont-=1

