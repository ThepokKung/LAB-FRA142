import sys 
import pygame as pg

#Class methods ---------------------------------------------------------------------

class Rectangle:
    def __init__(self,x=0,y=0,w=0,h=0):
        self.x = x # Position X
        self.y = y # Position Y
        self.w = w # Width
        self.h = h # Height
    def draw(self,screen):
        pg.draw.rect(screen,(120,20,220),(self.x,self.y,self.w,self.h))

class Button(Rectangle):
    def __init__(self, x=0, y=0, w=0, h=0):
        Rectangle.__init__(self, x, y, w, h)
        self.color = pg.Color('Red')  # เพิ่มตัวแปรสีของปุ่ม
        self.hover_color = pg.Color('Grey')  # เพิ่มตัวแปรสีของปุ่มเมื่อเมาส์ไปวาง
        self.press_Color = pg.Color('purple')   # เพิ่มตัวแปรสีของปุ่มเมื่อเมาส์ไปกด

    def isMouseOn(self):
        mouse_pos = pg.mouse.get_pos()  # รับตำแหน่งเม้าส์
        if self.x < mouse_pos[0] < self.x + self.w and self.y < mouse_pos[1] < self.y + self.h:
            return True
        else:
            return False
        
    def isMousePress(self):
        mouseX, mouseY = pg.mouse.get_pos() 

        if self.x <= mouseX <= self.x + self.w and self.y <= mouseY <= self.y + self.h:
            if pg.mouse.get_pressed()[0] == 1:
                return True
        return False

    def draw(self,screen):
        if self.isMouseOn():  # เมื่อเมาส์ไปวางที่ปุ่ม
            pg.draw.rect(screen,self.hover_color,(self.x,self.y,self.w,self.h))  # แสดงปุ่มสีเทา
            if self.isMousePress():
                pg.draw.rect(screen,self.press_Color,(self.x,self.y,self.w,self.h)) #แสดงปุ่มสีม่วง

        else:
            pg.draw.rect(screen,self.color,(self.x,self.y,self.w,self.h))  # แสดงปุ่มสีแดง

# เพิ่มฟังก์ชัน quit() เพื่อปิดโปรแกรมอย่างถูกต้อง
def quit():
    pg.quit()
    sys.exit()

# -----------------------------------------------------------------------------------

pg.init()
run = True
win_x, win_y = 800, 480
screen = pg.display.set_mode((win_x, win_y))
btn = Button(20,20,100,100) # สร้าง Object จากคลาส Button ขึ้นมา

# text box --------------------------------------------------------------------------

font = pg.font.Font('freesansbold.ttf', 32) # font and fontsize
text = font.render('FRA 142', True, (255,255,255) , (0,0,0)) # (text,is smooth?,letter color,background color)
textRect = text.get_rect() # text size
textRect.center = (win_x // 2, win_y // 2)

# -----------------------------------------------------------------------------------

while(run):
    screen.fill((255, 255, 255))
    if btn.isMouseOn():
        btn.w = 200
        btn.h = 300
    else:
        btn.w = 100
        btn.h = 100
# Move -----------------------------------------------------------------------------
    if pg.key.get_pressed()[pg.K_w]:
        btn.y -= 1
    if pg.key.get_pressed()[pg.K_s]:
        btn.y += 1
    if pg.key.get_pressed()[pg.K_a]:
        btn.x -= 1
    if pg.key.get_pressed()[pg.K_d]:
        btn.x += 1
        
    btn.draw(screen)
    pg.display.update()
    
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()



    