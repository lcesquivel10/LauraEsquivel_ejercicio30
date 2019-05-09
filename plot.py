import numpy as np
from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter

NX=100
Dx=1./NX
B=0.05
Vel=1.
Dt=B*Dx/Vel
Tf=0.1
NT=int(Tf/Dt)+1

fig = plt.figure()
ax = plt.axes(xlim=(0, 1), ylim=(-0.05, 0.05))
ax.set_aspect(1./0.1)

plt.xlabel('Posicion[metros]')
plt.ylabel('U')
plt.grid()
line, = ax.plot([], [])

DATOS = np.loadtxt("Archivo.dat")
MALLADO = np.reshape(DATOS, (NT, NX))
def init():
    line.set_data([], [])
    return line,

# para el gif 

def animate(i):
    
    x = np.linspace(0, 1, NX)
    y = 0.05*MALLADO[i]
    fig.suptitle('Tiempo: %f segundos' %((2/0.1)*i*Dt))
    line.set_data(x, y)
    return line,
Animator = FuncAnimation(fig, animate, init_func=init,frames=200, interval=20, blit=True,repeat=False)

Engine = PillowWriter(fps=60)
Animator.save('Movie.gif', writer=Engine)
