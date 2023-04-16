import pygame as pg
import math
pg.init()
win_x = 800
win_y = 600
screen = pg.display.set_mode((win_x, win_y))

#color
black = (0,0,0)
white = (255,255,255)

# Setup Projectile
posX, posY = win_x*1/10,win_y*8.5/10 #postition
u = 30 #intial velocity
angle = 45 #angle = 45 degree
a = 1 # Pixel/s^2
vx = u*math.cos(math.radians(angle))
vy = -u*math.sin(math.radians(angle)) #แกน Y ใน Pygame จะสลับกัน เลยต้องใส่ -
t = 0 #จับเวลา
tx = 0
ty = 0
dt = 0.01 #time step
cloneX , cloneY = posX,posY
upordown = 1
check = 0

while (1):
    font = pg.font.Font(None, 20)
    t += dt
    tx += dt
    ty += dt
    sx = vx*tx
    posX = cloneX + sx
    sy = (vy*ty + 0.5*a*ty**2)
    posY = cloneY + sy

    if pg.mouse.get_pressed()[0] == 1: # Check mouse pressed
        cloneY -= 10

    if(posY > cloneY):
        ty = 0
    if(posX > win_x):
        tx = 0
        cloneX = 0
        

    
    screen.fill((255, 255, 255))
    textTime = font.render('Elapsed time : ' + str(t), True, black)
    textPosX = font.render('Pos X : ' + str(posX),True,black)
    textPosY = font.render('Pos Y : ' + str(posY),True,black)
    screen.blit(textTime, (10,win_y-60))
    screen.blit(textPosX,(10,win_y-40))
    screen.blit(textPosY,(10,win_y-20))
    pg.draw.line(screen,black,(cloneX-10,cloneY+10),(cloneX+win_x,cloneY+10),2)
    pg.draw.line(screen,black,(cloneX-10,cloneY+10),(cloneX-10,cloneY-win_y+10),2)
    pg.draw.circle(screen, (100, 100, 100), (posX, posY), 10)
    pg.display.update()

    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            exit()
