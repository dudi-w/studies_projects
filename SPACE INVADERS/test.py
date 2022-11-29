# Importing pygame module
import pygame
from pygame.locals import *

# initiate pygame and give permission
# to use pygame's functionality.
pygame.init()

# create the display surface object
# of specific dimension.
window = pygame.display.set_mode((600, 600))

# Fill the scree with white color
window.fill((255, 255, 255))

# Using draw.rect module of
# pygame to draw the outlined rectangle
pygame.draw.rect(window, (0, 0, 255),[100, 100, 400, 100], 2)
x=pygame.draw.rect(window, (0, 0, 255),[100, 50, 400, 100], 2)
while True:
	y=x.move(1,1)
	x.update(y)
	print(x)
	pygame.draw.rect(window, (0, 0, 255),y)
	#pygame.draw.rect(window, x)
	#help (x)
	# Draws the surface object to the screen.
	pygame.display.update()

