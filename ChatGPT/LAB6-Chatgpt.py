import pygame as pg
import sys

pg.init()

win_x, win_y = 800, 480
screen = pg.display.set_mode((win_x, win_y))
clock = pg.time.Clock()

btn_x = 50  # Initial x position of the button
move_speed = 5  # Speed of the button movement
is_d_key_down = False  # Flag to track if D key is currently held down

while True:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()
        if event.type == pg.KEYDOWN:
            if event.key == pg.K_d:
                print("Key D down")
                # Set the flag to True when D key is pressed
                is_d_key_down = True
            elif event.key == pg.K_w:
                print("Key W")
        if event.type == pg.KEYUP:
            if event.key == pg.K_d:
                print("Key D up")
                # Set the flag to False when D key is released
                is_d_key_down = False
            elif event.key == pg.K_a:
                print("Key A up")

    # Update button position if D key is currently held down
    if is_d_key_down:
        btn_x += move_speed

    # Other game logic here

    screen.fill((255, 255, 255))
    pg.draw.rect(screen, (0, 0, 255), pg.Rect(btn_x, 200, 50, 50))  # Draw a blue button
    pg.display.update()
    clock.tick(60)
