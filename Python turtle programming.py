# -*- coding: utf-8 -*-
"""
Created on Mon Oct 17 21:18:52 2022

@author: DHIRAJ 
"""


import turtle
colors = ['indigo', 'blue', 'green', 'yellow', 'orange', 'red'] 
t = turtle.Pen()
for x in range(360):
    t.pencolor(colors[x % 6])
    t.width(x / 5 + 1)
    t.forward(x)
    t.left(20)