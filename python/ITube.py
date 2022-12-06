from random import randint

class Clip:
	def __init__(self, name ,year):
		self.name= str(name)
		self.year= int(year)
		self.is_played= False
		
	def __repr__(self):
		return self.name +":"+str(self.year)
		
	def play(self):
		self.is_played = True
	
	def stop(self):
		self.is_played = False


class ArtClip(Clip):
	def __init__(self, name ,year, time):
		Clip.__init__(self, name ,year)
		self.time= int(time)
		
	def __repr__(self):
		return Clip.__repr__(self)+" ("+str(self.time)+")"
				
	def is_valid_for_euro(self):
		return  bool(self.time <= 3)
		
class Player:
	def __init__(self, clips):
		self.clips=clips
		for clip in clips:
			clip.stop()
		self.current=-1
	
	def __next__(self):
		if len(self.clips)==0:
			raise ValueError ('your player is empty')
		if self.current==len(self.clips)-1:
			self.current=-1
		self.clips[self.current].stop()
		self.current+=1
		self.clips[self.current].play()
		return self.clips[self.current]
	
	def __repr__(self):
		return self.clips
	
	def __iter__(self):
		return self
		
	def shuffle(self):
		self.clips = [self.clips.pop(randint(0, len(self.clips)-1)) for i in range(len(self.clips))]
		

def main():
	clip1 = Clip("gangam style" , "2012")
	print (clip1)
	print (clip1.is_played)
	
	clip2 = ArtClip("gangam style" , "2012" , 3)
	print (clip2)
	print( clip2.is_valid_for_euro()) 
	clip2.stop()
	
	clip3 = ArtClip("thenks you h'shem" , "2022" , 5)
	
	player1 = Player([clip1, clip2 , clip3])
	#print(player1)
	player1.shuffle()
	print(player1.clips)
	for i in player1:
		print(i)
	
if __name__ == '__main__':
	main()
	
