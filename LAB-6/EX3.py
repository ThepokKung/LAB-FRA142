import sys
import pygame as pg

from Class.InputBox import InputBox

pg.init()
win_x, win_y = 800, 480
screen = pg.display.set_mode((win_x, win_y))

COLOR_INACTIVE = pg.Color('lightskyblue3') # ตั้งตัวแปรให้เก็บค่าสี เพื่อนำไปใช้เติมสีให้กับกล่องข้อความตอนที่คลิกที่กล่องนั้นๆอยู่
COLOR_ACTIVE = pg.Color('dodgerblue2')     # ^^^
FONT = pg.font.Font(None, 32)

input_box1 = InputBox(100, 100, 140, 32,color_inactive=COLOR_INACTIVE,color_active=COLOR_ACTIVE,font=FONT)  # สร้าง InputBox1
input_box2 = InputBox(100, 300, 140, 32)  # สร้าง InputBox2
# เก็บ InputBox ไว้ใน list เพื่อที่จะสามารถนำไปเรียกใช้ได้ง่าย
input_boxes = [input_box1, input_box2]
run = True


while run:
    screen.fill((255, 255, 255))
    for box in input_boxes:  # ทำการเรียก InputBox ทุกๆตัว โดยการ Loop เข้าไปยัง list ที่เราเก็บค่า InputBox ไว้
        box.update()  # เรียกใช้ฟังก์ชัน update() ของ InputBox
        # เรียกใช้ฟังก์ชัน draw() ของ InputBox เพื่อทำการสร้างรูปบน Screen
        box.draw(screen)

    for event in pg.event.get():
        for box in input_boxes:
            box.handle_event(event)
        if event.type == pg.QUIT:
            pg.quit()
            run = False

    pg.time.delay(1)
    pg.display.update()
