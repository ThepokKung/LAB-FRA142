import pygame as pg
win_x = 800
win_y = 480
screen = pg.display.set_mode((win_x, win_y))
posX, posY = 200, 30

g = 1
t = 1
u = 50

sX = 0
vX = 0

sY = 0
vY = 0

spdX = 2
spdY = 2

while (1):
    screen.fill((255, 255, 255))

    pg.draw.circle(screen, (100, 100, 100), (posX, posY), 20)
    pg.display.update()

    sX = u*t  # คงที่
    sY = u*t + (1/2)*g*t**2
    u = u+(g*t)

    posX = sX
    posY = sY

    # spdX += 1
    # posX += spdX
    # posY += spdY

    pg.time.delay(1)

    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            exit()
