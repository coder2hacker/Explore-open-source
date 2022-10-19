import pygame
import random
import math
import time

pygame.init()
screen=pygame.display.set_mode((800,600))

#caption and logo
pygame.display.set_caption('ping pong')
icon=pygame.image.load('icon.png')
pygame.display.set_icon(icon)

# background image
background=pygame.image.load('bg.jpg')

line=pygame.image.load('line.png')
linex=360
liney=540
linex_change=0
liney_change=0
def lines(x,y):
    screen.blit(line,(x,y))

time.sleep(2)

ball=pygame.image.load('ball.png')
ballx=random.randint(18,750)
bally=random.randint(18,150)
ballx_change=0.9
bally_change=0.9
def balls(x,y):
    screen.blit(ball,(x,y))

flag=False
score=0
font1=pygame.font.Font('freesansbold.ttf',32)
textx=200
texty=10

def showscore(x,y):
    score1=font1.render("score :"+ str(score)+ "    for reset : press space bar ",True,(255,255,255))
    screen.blit(score1,(x,y))


remaining=True
while remaining:
    screen.blit(background,(0,0))
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            remaining=False

        if event.type==pygame.KEYDOWN:
            if event.key==pygame.K_LEFT:
                linex_change=-1.4            
            if event.key==pygame.K_RIGHT:
                linex_change=1.4
            if event.key==pygame.K_UP:
                liney_change=-1.4
            if event.key==pygame.K_DOWN:
                liney_change=1.4
            if event.key==pygame.K_SPACE:
                score=0
                ballx=random.randint(18,650)
                bally=random.randint(18,250)


        if event.type==pygame.KEYUP:
            if event.key==pygame.K_LEFT or pygame.K_RIGHT:
                linex_change=0
            if event.key==pygame.K_UP or pygame.K_DOWN:
                liney_change=0

    #all about lines
    if linex<8:
        linex=8
    elif linex>730:
        linex=730
    elif liney>560:
        liney=560

    linex +=linex_change
    liney +=liney_change
    lines(linex,liney)

    #all about a balls

    if ballx<32:
        ballx_change=1
    if ballx>770:
        ballx_change=-1
    if bally<10:
        bally_change=1

    dis=((ballx-linex)**2+(bally-liney)**2)**0.5
    if dis<40:
        bally_change=-1
        flag=True
        # time.sleep(2)
    else:
        flag=False
    
    if flag==True:
        score +=1

    ballx += ballx_change
    bally += bally_change

    balls(ballx,bally)

    showscore(textx,texty)

    pygame.display.update()
