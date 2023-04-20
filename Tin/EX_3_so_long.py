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

class InputBox:
    def __init__(self, x, y, w, h, isnum ,text=''):
        self.rect = pg.Rect(x, y, w, h)
        self.color = COLOR_INACTIVE
        self.text = text
        self.txt_surface = FONT.render(text, True, self.color)
        self.active = False
        self.isnum = isnum

    def handle_event(self, event):
        
        if event.type == pg.MOUSEBUTTONDOWN:# ทำการเช็คว่ามีการคลิก Mouse หรือไม่
            if self.rect.collidepoint(event.pos): #ทำการเช็คว่าตำแหน่งของ Mouse อยู่บน InputBox นี้หรือไม่
                # Toggle the active variable.
                self.active = not self.active
            else:
                self.active = False
            self.color = COLOR_ACTIVE if self.active else COLOR_INACTIVE # เปลี่ยนสีของ InputBox
            
        if event.type == pg.KEYDOWN:
            if self.active:
                if event.key == pg.K_RETURN:
                    print(self.text)
                    self.text = ''
                elif event.key == pg.K_BACKSPACE:
                    self.text = self.text[:-1]
                else:
                    if self.isnum == True:
                        if chr(event.key).isnumeric():
                            self.text += event.unicode
                    else :
                        self.text += event.unicode
                # Re-render the text.
                self.txt_surface = FONT.render(self.text, True, self.color)

    def update(self):
        # Resize the box if the text is too long.
        width = max(200, self.txt_surface.get_width()+10)
        self.rect.w = width

    def draw(self, Screen):
        # Blit the text.
        Screen.blit(self.txt_surface, (self.rect.x+5, self.rect.y+5))
        # Blit the rect.
        pg.draw.rect(Screen, self.color, self.rect, 2)


def quit(): # เพิ่มฟังก์ชัน quit() เพื่อปิดโปรแกรมอย่างถูกต้อง
    pg.quit()
    sys.exit()

# -----------------------------------------------------------------------------------

pg.init()
win_x, win_y = 800, 480
screen = pg.display.set_mode((win_x, win_y))
btn = Button(20,20,100,100) # สร้าง Object จากคลาส Button ขึ้นมา

# text box --------------------------------------------------------------------------

COLOR_INACTIVE = pg.Color('black') # ตั้งตัวแปรให้เก็บค่าสี เพื่อนำไปใช้เติมสีให้กับกล่องข้อความตอนที่คลิกที่กล่องนั้นๆอยู่
COLOR_ACTIVE = pg.Color('blue')     # ^^^
FONT = pg.font.Font(None, 32)
input_box1 = InputBox(win_x/2, 100, 140, 32,False)
input_box2 = InputBox(win_x/2, 200, 140, 32,False) 
input_box3 = InputBox(win_x/2, 300, 140, 32,True) 
input_boxes = [input_box1, input_box2, input_box3] # เก็บ InputBox ไว้ใน list เพื่อที่จะสามารถนำไปเรียกใช้ได้ง่าย
run = True

font = pg.font.Font(None, 32)
textFirstname = font.render('Firstname : ', True,
                       pg.Color('black'), pg.Color('White'))
textFirstnameRect = textFirstname.get_rect()
textFirstnameRect.center = (int(win_x/2) - 100, 115)

textLastname = font.render('Name : ', True, pg.Color('Black'), pg.Color('White'))
textLastnameRect = textLastname.get_rect()
textLastnameRect.center = (int(win_x/2) - 100, 215)

textAge = font.render('Age : ', True, pg.Color('Black'), pg.Color('White'))
textAgeRect = textAge.get_rect()
textAgeRect.center = (int(win_x/2) - 100, 315)

textTemp = font.render('', True, pg.Color('Black'), pg.Color('White'))
textTempRect = textTemp.get_rect()
textTempRect.center = (int(win_x/2)-100, 415)

btn = Button(int(win_x/2)-50, 350, 100, 50,)

# -----------------------------------------------------------------------------------

while(run):
    screen.fill((255, 255, 255))
    for box in input_boxes: # ทำการเรียก InputBox ทุกๆตัว โดยการ Loop เข้าไปยัง list ที่เราเก็บค่า InputBox ไว้
        box.update() # เรียกใช้ฟังก์ชัน update() ของ InputBox
        box.draw(screen) # เรียกใช้ฟังก์ชัน draw() ของ InputBox เพื่อทำการสร้างรูปบน Screen
    
    screen.blit(textFirstname, textFirstnameRect)
    screen.blit(textLastname, textLastnameRect)
    screen.blit(textAge, textAgeRect)
    screen.blit(textTemp, textTempRect)

    if btn.isMouseOn():

        btn.color = pg.Color('Blue') # Mouse on
        if btn.isMousePress(): #Mouse press
            temp = "Hello {} {}! You are {} years old.".format(input_box1.text, input_box2.text, input_box3.text)
            textTemp = font.render(temp, True, pg.Color('Black'), pg.Color('White'))
            textTempRect = textTemp.get_rect()
            textTempRect.center = (int(win_x/2), 450)
    else:
        btn.color = pg.Color('red')

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



    