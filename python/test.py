import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-2*np.pi, 2*np.pi, 100)

xx = x + 1j * x[:, np.newaxis] # a + ib over complex plane
print(xx)
out = np.exp(xx)
print(out)
plt.subplot(121)
plt.imshow(np.abs(out),
           extent=[-2*np.pi, 2*np.pi, -2*np.pi, 2*np.pi], cmap='gray')
plt.title('Magnitude of exp(x)')
plt.subplot(122)
plt.imshow(np.angle(out),
           extent=[-2*np.pi, 2*np.pi, -2*np.pi, 2*np.pi], cmap='hsv')
plt.title('Phase (angle) of exp(x)')
plt.show()

a={15,74,8,20,48,26,2}
check= False
cont=0
for d in a:
	cont+=d
	if d ==8:
		check=True
	print(True if cont>100 and check else "\n")	
print(True if cont>100 and check else False ,"\n", cont)

