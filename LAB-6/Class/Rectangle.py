import pygame as pg

class Rectangle:
    def __init__(self,x=0,y=0,w=0,h=0,c=pg.Color('white')):
        self.x = x # Position X
        self.y = y # Position Y
        self.w = w # Width
        self.h = h # Height
        self.c = c #col
    def draw(self,screen):
        pg.draw.rect(screen,(200,0,0),(self.x,self.y,self.w,self.h))