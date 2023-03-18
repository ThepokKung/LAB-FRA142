import pygame as pg
import random 
pg.init()

win_x, win_y = 800, 480  # 1 ขนาดหน้าจอ
screen = pg.display.set_mode((win_x, win_y))  # 1 สร้างหน้าต่างเกม
posX, posY = 20, 20
r = 10
check = False

while (1):  # 2 ทำการสร้าง loop
    screen.fill((255, 255, 255))
    
    if (check==False):
        r += 1
        pg.draw.circle(screen, (0,255,0), (400, 240),r)  # ใส่คำสั่งก่อนการอัพเดทห

    elif (check == True):
        r -= 1
        pg.draw.circle(screen, (255,0,0), (400, 240),r)  # ใส่คำสั่งก่อนการอัพเดทห

    if (r > win_y):
        check = True

    if(check == True):
        if(r <= 0):
            check = False
    
    pg.time.delay(1)  # หน่วงเวลา

    pg.display.update()  # 4 ทำการอัพเดท

    for event in pg.event.get():  # ทำการ Check event ต่างๆที่เกิดขึ้น
        if event.type == pg.QUIT:
            pg.quit()
            exit()
