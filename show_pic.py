from PIL import Image
from numpy import asarray

def print_img(img_path):
    img = Image.open(img_path)
    w = min(os.get_terminal_size().columns,img.size[0])
    l = int(img.size[1]*(w/img.size[0])*0.5)
    img=img.resize((w, l))
    img_arr = np.array(img)
    print()
    for row in img_arr:
        print('\033[8m', end='')
        for r, g, b in row:
            print(f'\033[48;2;{r};{g};{b}mX', end='')
        print('\033[0m')
    
def main():
	print_img("/home/mefathim-tech-11/Pictures/684e7253198a94f26aa952234e584850.jpg")
	
if __name__=="__main__":
	main()
