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
u = 20 #intial velocity
angle = 45 #angle = 45 degree
a = 1 # Pixel/s^2
vx = u*math.cos((angle/180)*math.pi)
vy = -u*math.sin((angle/180)*math.pi) #แกน Y ใน Pygame จะสลับกัน เลยต้องใส่ -
t = 0 #จับเวลา
dt = 0.01 #time step
cloneX , cloneY = posX,posY

while (1):
    font = pg.font.Font(None, 20)
    
    t += dt
    posX += vx*dt
    posY += vy*dt + 0.5*a*dt**2
    vy += a*dt

    if (posY > win_y):
        pg.quit()
        exit()
    
    screen.fill((255, 255, 255))
    textTime = font.render('Elapsed time : ' + str(t), True, black)
    textPosX = font.render('Pos X : ' + str(posX),True,black)
    textPosY = font.render('Pos Y : ' + str(posY),True,black)
    screen.blit(textTime, (10,win_y-60))
    screen.blit(textPosX,(10,win_y-40))
    screen.blit(textPosY,(10,win_y-20))
    pg.draw.line(screen,black,(cloneX,cloneY),(cloneX+win_x,cloneY),2)
    pg.draw.line(screen,black,(cloneX,cloneY),(cloneX,cloneY-win_y),2)
    pg.draw.circle(screen, (100, 100, 100), (posX, posY), 10)
    pg.display.update()

    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            exit()
