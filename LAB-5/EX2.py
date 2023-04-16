import pygame as pg
win_x = 800
win_y = 480
screen = pg.display.set_mode((win_x, win_y))
posX, posY = 200, 30

a = 1/1000
s = 0
u = 0
t = 1
v = 0

while (1):
    
    s = u*t
    u = u+(a*t)
    t =+ 1
    posY += s

    if (posY > win_y):
        pg.quit()
        exit()
    
    screen.fill((255, 255, 255))
    pg.draw.circle(screen, (100, 100, 100), (posX, posY), 20)
    pg.display.update()
    pg.time.delay(1)

    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            exit()
