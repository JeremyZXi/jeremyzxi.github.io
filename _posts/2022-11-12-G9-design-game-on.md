---
layout: post
title: >
    Design Game on
feature-img: "assets/img/pexels/gameOnIcon.png"
thumbnail: "assets/img/pexels/gameOnIcon.png"
tags: [Test, Keystone, Design]
---
![icon]({{ "assets/img/pexels/gameOnIcon.png" | relative_url}})
# **Code**
## **Timer**

```python
import time
#define
global current_time
global year
starttime = 0
year = 0
#define function
def Year(x):
    setTime = x

    starttime = time.time()
    #record current time
    while True:
        current_time = round(time.time() - starttime)
        print(current_time, " sec")
        year = round(current_time / 12)
        print(year," year")
        #stop the timer
        if current_time == setTime:
            break

#output
print("timer initialized")
```


**Name record**
```python
import tkinter as tk
window = tk.Tk()

window.title("Please name your world")
window.geometry("400x240")
textExample=tk.Text(window, height=10)

textExample.pack()
def getTextInput():
    global result
    result=textExample.get("1.0","end")    #get the inputed text
    print("This world is called " + result)
getTextInput()

btnRead = tk.Button(window, height=1, width=30, text="Click here and close this window", command=getTextInput)  # link the button
Name_des = tk.Button(window, height=2, width=30, text="You may choose to skip this step, just close this window", command=getTextInput)
    # placed button
btnRead.pack()  # display button

    # 第9步，
window.mainloop()
```


***Developing blog***
**2022/11/18/Friday**
*Graphic feedback-cloud animation*

A.Bug:

i)Transparent image option in pygame(.convert_alpha()) seems to bug the current way to move the cloud layer
ii)The layer is duplicated instead of moving(probably)

 
B.possible solution:

i)find another way
ii)cancel this part and move on
*Code
```python
class cloud():
    def __init__(self, is_alt=0):
        # load image
        self.cloud = pygame.image.load('image/Cloud_V1A.png') # Seems like transparent image can not move in this way
        self.cloud = pygame.transform.scale(self.cloud,(1050,660))
        # get rect
        self.cloud_rect = self.cloud.get_rect()
        # default position is 0
        self.cloud_rect.x = is_alt

    def update(self):
            # move the layer downward
            self.cloud_rect.x += 1
            # if the image is out of the window, set it to the upon area
            if self.cloud_rect.centery >= 1050:
                self.cloud_rect.x = -1050

    def draw(self):
            # Draw the window
            screen.blit(self.cloud, self.cloud_rect)
```
**2022/11/20～24/Friday**

**2022/12/5Monday**
*define button class*
```python
import pygame

class Button():
    def __init__(self, x, y, image, scale):
        width = image.get_width()
        height = image.get_height()
        self.image = pygame.transform.scale(image, (int(width*scale),int(height*scale)))
        self.rect = self.image.get_rect()
        self.rect.topleft = (x, y)
        self.clicked = False
    def draw(self, surface):
        action = False
        pygame.draw.rect(surface, (0,0,0), (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()))
        edge = pygame.draw.rect(surface, (18, 0, 163), (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()), 3)
        # get mouse's position
        pos = pygame.mouse.get_pos()
        #mouse clicked
        if edge.collidepoint(pos):
            if pygame.mouse.get_pressed()[0] == 1 and self.clicked == False:
                self.clicked = True
                action = True
                pygame.draw.rect(surface, (0, 0, 255),
                                 (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()))
        if pygame.mouse.get_pressed()[0] == 0:
            self.clicked = False

        #display the button
        surface.blit(self.image, (self.rect.x, self.rect.y))

        return action
```
*Call the button class and define differen button*
```python 
#font
font = pygame.font.SysFont(None,30)
#load button_text
Bfont = pygame.font.SysFont(None,30)
BuildF_img = Bfont.render("Build Factory", True, TextCol)
BuildGF_img = Bfont.render("Build Green Factory", True, TextCol)
BuildP_img = Bfont.render("Build Power plant", True, TextCol)
BuildGP_img = Bfont.render("Build Green power plant", True, TextCol)
#create button
BuildF_button = button.Button(1055, 125, BuildF_img, 1)
BuildGF_button = button.Button(1055, 150, BuildGF_img, 1)
BuildP_button = button.Button(1055, 200, BuildP_img, 1)
BuildGP_button = button.Button(1055, 225, BuildGP_img, 1)
```
*use the button & resources*
```python
#timer
import time
setTime = 1200
starttime = time.time()
#define building number
Factory = 0
G_Factory = 0
Power_plant = 0
G_Power_plant = 0
#define resources
population = 10
electricity = 5
materials = 5
global_temp = 0
while True:
    #button
    if BuildF_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity -1
            Factory = Factory + 1
    #if BuildGF_button.draw(screen):

    #if BuildP_button.draw(screen):

    #if BuildGP_button.draw(screen):
    #timer
    current_time = round(time.time() - starttime)
    print(current_time, " sec")
    year = round(current_time / 12)
    print(year, " year")
    year_dis = font.render(f"Year:{2400+year}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(year_dis,(1080,50))
    # stop the timer
    if current_time == setTime:
        break
    #resoucres calculator




    #display resources
    materials_dis = font.render(f"Materials:{materials}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(materials_dis, (1050, 300))
    electricity_dis = font.render(f"Electricity:{electricity}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(electricity_dis, (1050, 325))
    population_dis = font.render(f"Population:{population}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(population_dis, (1050, 350))
    globalTemp_dis = font.render(f"Global temperature increases:{global_temp}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(globalTemp_dis, (1050, 375))
    #building number display
    Factory_dis = font.render(f"Factory:{Factory}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(Factory_dis, (1050, 400)) 
```
**2022/12/7Wednesday**
*more button and resources*
```python 
run = True
while run:
    #button
    if BuildF_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity -1
            Factory = Factory + 1
    if BuildGF_button.draw(screen):
        if materials >= 2 and electricity >= 1:
            materials = materials - 2
            electricity = electricity - 1
            G_Factory =G_Factory + 1

    if BuildP_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity - 1
            Power_plant =Power_plant + 1

    if BuildGP_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 2
            electricity = electricity - 1
            G_Power_plant =G_Power_plant + 1
    #timer
    current_time = round(time.time() - starttime)
    print(current_time, " sec")
    year = round(current_time / 12)
    print(year, " year")
    #display Year
    year_dis = font.render(f"Year:{2400+year}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(year_dis,(1080,50))
    # stop the timer
    if current_time == setTime:
        break
    #resoucres calculator activate every year(12sec)
    if current_time % 12 == 0:
        materials = materials + Factory - 0.5 * Power_plant - 0.5 * resident
        electricity = electricity + Power_plant - 0.5 * Factory - 0.5 * resident
        population = population + resident
        global_temp = global_temp + 0.001*resident + 0.005*Power_plant + 0.006*Factory
        time.sleep(1)


    #display resources
    materials_dis = font.render(f"Materials:{materials}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(materials_dis, (1050, 300))
    electricity_dis = font.render(f"Electricity:{electricity}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(electricity_dis, (1050, 325))
    population_dis = font.render(f"Population:{population}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(population_dis, (1050, 350))
    globalTemp_dis = font.render(f"Global temperature:{global_temp}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(globalTemp_dis, (1050, 375))
    #building number display
    #factory number display
    Factory_dis = font.render(f"Factory:{Factory}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(Factory_dis, (1050, 425))
    GFactory_dis = font.render(f"Green Factory:{G_Factory}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(GFactory_dis, (1050, 450))
    #power plant number display
    power_dis = font.render(f"Power Plant:{Power_plant}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(power_dis, (1050, 475))
    Gpower_dis = font.render(f"Green Power Plant:{G_Power_plant}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(Gpower_dis, (1050, 500))
    #resident number
    resident_dis = font.render(f"Resident Building:{resident}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(resident_dis, (1050, 525))
    #Background condition
    if global_temp >= 1:
        background = pygame.image.load("image/background1.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
    if global_temp >= 2 and global_temp >= 1:
        background = pygame.image.load("image/background2.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
```
The structure of the code had been changed which the timer goes in the main loop. More resources were added and a background condition was added as well. The condition track the value of global_temp and change the "background"
**2022/12/9**
*end page*
Using Tkinter
showing a summary of the game with different data, score, and others.
```python
window_end = tk.Tk()

window_end.title(f"Your final score is{score}")
window_end.geometry("400x400")
tk.Label(window_end, text=f"Your final score is{score}").grid(row=1, column=0)
tk.Label(window_end, text="You built:").grid(row=2, column=0)
tk.Label(window_end, text=f"{Factory} Factory").grid(row=3, column=0)
tk.Label(window_end, text=f"{G_Factory} Green factory").grid(row=4, column=0)
tk.Label(window_end, text=f"{Power_plant} Power plant").grid(row=5, column=0)
tk.Label(window_end, text=f"{G_Power_plant} GreenPower plant").grid(row=6, column=0)
tk.Label(window_end, text=f"{resident} City").grid(row=7, column=0)
tk.Label(window_end, text=f"Your final \n population:{population}").grid(row=2, column=1)
tk.Label(window_end, text=f"Your development \n increased global \n temperature for:\n{global_temp}℃").grid(row=3,
                                                                                                            column=1)

tk.Label(window_end, text="ACHIEVEMENT:").grid(row=4, column=1)

G_building = G_Factory + G_Power_plant
B_building = Factory + Power_plant
if G_building > B_building:
    tk.Label(window_end, text="Environmentalists").grid(row=5, column=1)
elif B_building > G_building:
    tk.Label(window_end, text="Industry Expert").grid(row=5, column=1)
else:
    tk.Label(window_end, text="Balance（？）").grid(row=5, column=1)
if not wins:
    tk.Label(window_end, text="You loss").grid(row=6, column=1)

tk.Label(window_end, text="Contact us(me):\nxiyan.zhang@keystoneacademy.cn\nJeremyZ1012@outlook.cn").grid(row=11,
                                                                                                          column=0)

window_end.mainloop()
```
**2022/12/13**
New background and graphic logic
```python
    if 1 <= global_temp < 2:
        background = pygame.image.load("image/background1.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        event_dis = font.render("XXXX", True, (220, 220, 220), (177, 177, 177))
        screen.blit(event_dis, (1200, 75))
    if 2 <= global_temp < 3:
        background = pygame.image.load("image/background2.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
    if 3 <= global_temp < 4:
        background = pygame.image.load("image/background4.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
    if 4 <= global_temp < 5:
        background = pygame.image.load("image/background5.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
    if 5 <= global_temp < 6:
        background = pygame.image.load("image/background6.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
        resident = (3 / 4) * resident

    if 6 <= global_temp < 7:
        background = pygame.image.load("image/background7.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (1 / 3) * population
        resident = (3 / 4) * resident
        Factory = (3 / 4) * Factory
        Power_plant = (3 / 4) * Power_plant
    if 8 <= global_temp < 9:
        background = pygame.image.load("image/background8.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (1 / 5) * population
        resident = (1 / 5) * resident
        Factory = (1 / 5) * Factory
        Power_plant = (1 / 5) * Power_plant
    if 9 <= global_temp:
        wins = False
        break
```
***code of completed product***
button.py
```python
import pygame

class Button():
    def __init__(self, x, y, image, scale):
        width = image.get_width()
        height = image.get_height()
        self.image = pygame.transform.scale(image, (int(width*scale),int(height*scale)))
        self.rect = self.image.get_rect()
        self.rect.topleft = (x, y)
        self.clicked = False
    def draw(self, surface):
        action = False
        pygame.draw.rect(surface, (0,0,0), (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()))
        edge = pygame.draw.rect(surface, (18, 0, 163), (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()), 3)
        # get mouse's position
        pos = pygame.mouse.get_pos()
        #mouse clicked
        if edge.collidepoint(pos):
            if pygame.mouse.get_pressed()[0] == 1 and self.clicked == False:
                self.clicked = True
                action = True
                pygame.draw.rect(surface, (0, 0, 255),
                                 (self.rect.x, self.rect.y, self.image.get_width(), self.image.get_height()))
        if pygame.mouse.get_pressed()[0] == 0:
            self.clicked = False

        #display the button
        surface.blit(self.image, (self.rect.x, self.rect.y))

        return action
```
main.py
```python
import tkinter as tk

window = tk.Tk()

window.title("Please name your world")
window.geometry("400x240")
textExample = tk.Text(window, height=10)

textExample.pack()


def getTextInput():
    global result
    result = textExample.get("1.0", "end")  # 获取文本输入框的内容
    print("This world is called " + result)


getTextInput()

btnRead = tk.Button(window, height=1, width=30, text="Click here and close this window",
                    command=getTextInput)  # command绑定获取文本框内容的方法

# 第8步，安置按钮
btnRead.pack()  # 显示按钮

# 第9步，
window.mainloop()

import pygame
import sys
import button

print(pygame.font.get_fonts())
# 初始化pygame
pygame.init()
FPS = 120
BLUE = (114, 0, 255)
transparent = (0, 0, 0, 0)
clock = pygame.time.Clock()
# 设置窗口大小
screen = pygame.display.set_mode((1400, 660))
# 设置窗口标题
pygame.display.set_caption(result)
# color
TextCol = (255, 255, 255)
# font
font = pygame.font.SysFont(None, 30)
# load button_text
Bfont = pygame.font.SysFont(None, 30)
BuildF_img = Bfont.render("Build Factory", True, TextCol)
BuildGF_img = Bfont.render("Build Green Factory", True, TextCol)
BuildP_img = Bfont.render("Build Power plant", True, TextCol)
BuildGP_img = Bfont.render("Build Green power plant", True, TextCol)
BuildR_img = Bfont.render("Build residence", True, TextCol)
# create button
BuildF_button = button.Button(1055, 125, BuildF_img, 1)
BuildGF_button = button.Button(1055, 150, BuildGF_img, 1)
BuildP_button = button.Button(1055, 200, BuildP_img, 1)
BuildGP_button = button.Button(1055, 225, BuildGP_img, 1)
BuildR_button = button.Button(1055, 250, BuildR_img, 1)
# load background
background = pygame.image.load("image/background.png").convert()
background = pygame.transform.scale(background, (1050, 660))
screen.blit(background, (0, 0))
pygame.display.flip()
# 导入音乐
#pygame.mixer.music.load("sound/BGM.mp3")
#pygame.mixer.music.set_volume(1)


# 播放音乐
# pygame.mixer.music.play(0)


##below
# The problem about this part is that seems like transparent image can not move itself but duplicate(?)
# load cloud image
class cloud():
    def __init__(self, is_alt=0):
        # load image
        self.cloud = pygame.image.load('image/Cloud_V1A.png')  # Seems like transparent image can not move in this way
        self.cloud = pygame.transform.scale(self.cloud, (1050, 660))
        # get rect
        self.cloud_rect = self.cloud.get_rect()
        # default position is 0
        self.cloud_rect.x = is_alt

    def update(self):
        # move the layer downward
        self.cloud_rect.x += 1
        # if the image is out of the window, set it to the upon area
        if self.cloud_rect.centery >= 1050:
            self.cloud_rect.x = -1050

    def draw(self):
        # Draw the window
        screen.blit(self.cloud, self.cloud_rect)


# the above class will not be called

cloud_a = cloud()
cloud_b = cloud(-700)
# timer
import time

setTime = 1200
starttime = time.time()
# define building number
Factory = 3
G_Factory = 0
Power_plant = 2
G_Power_plant = 0
resident = 1
# define resources
population = 10
electricity = 10
materials = 10
global_temp = 0

flag = True
run = True
wins = True
while run:
    # button
    if BuildF_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity - 1
            Factory = Factory + 1
    if BuildGF_button.draw(screen):
        if materials >= 2 and electricity >= 1:
            materials = materials - 2
            electricity = electricity - 1
            G_Factory = G_Factory + 1

    if BuildP_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity - 1
            Power_plant = Power_plant + 1

    if BuildGP_button.draw(screen):
        if materials >= 2 and electricity >= 1:
            materials = materials - 2
            electricity = electricity - 1
            G_Power_plant = G_Power_plant + 1
    if BuildR_button.draw(screen):
        if materials >= 1 and electricity >= 1:
            materials = materials - 1
            electricity = electricity - 1
            resident = resident + 1
    # timer
    current_time = round(time.time() - starttime)
    print(current_time, " sec")
    year = round(current_time / 12)
    print(year, " year")
    # display Year
    year_dis = font.render(f"Year:{2400 + year}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(year_dis, (1080, 50))
    # stop the timer
    if current_time == setTime:
        break
    # resoucres calculator activate every year(12sec)
    if current_time % 12 == 0:
        materials = materials + Factory - 0.5 * Power_plant - 0.5 * resident
        electricity = electricity + Power_plant - 0.5 * Factory - 0.5 * resident
        population = population + resident
        global_temp = global_temp + 0.001 * resident + 0.005 * Power_plant + 0.006 * Factory
        time.sleep(1)

    # score
    score = (materials / population) + (electricity / population) + population - (global_temp * 10)
    score_dis = font.render(f"Score:{round(score)}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(score_dis, (1080, 75))
    # display score
    # display resources
    materials_dis = font.render(f"Materials:{materials}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(materials_dis, (1050, 300))
    electricity_dis = font.render(f"Electricity:{electricity}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(electricity_dis, (1050, 325))
    population_dis = font.render(f"Population:{population}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(population_dis, (1050, 350))
    globalTemp_dis = font.render(f"Global temperature:{global_temp}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(globalTemp_dis, (1050, 375))
    # building number display
    # factory number display
    Factory_dis = font.render(f"Factory:{Factory}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(Factory_dis, (1050, 425))
    GFactory_dis = font.render(f"Green Factory:{G_Factory}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(GFactory_dis, (1050, 450))
    # power plant number display
    power_dis = font.render(f"Power Plant:{Power_plant}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(power_dis, (1050, 475))
    Gpower_dis = font.render(f"Green Power Plant:{G_Power_plant}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(Gpower_dis, (1050, 500))
    # resident number
    resident_dis = font.render(f"Resident Building:{resident}", True, (220, 220, 220), (177, 177, 177))
    screen.blit(resident_dis, (1050, 525))
    # Background condition
    if 1 <= global_temp < 2:
        background = pygame.image.load("image/background1.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        event_dis = font.render("XXXX", True, (220, 220, 220), (177, 177, 177))
        screen.blit(event_dis, (1200, 75))
    if 2 <= global_temp < 3:
        background = pygame.image.load("image/background2.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
    if 3 <= global_temp < 4:
        background = pygame.image.load("image/background4.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
    if 4 <= global_temp < 5:
        background = pygame.image.load("image/background5.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
    if 5 <= global_temp < 6:
        background = pygame.image.load("image/background6.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (2 / 3) * population
        resident = (3 / 4) * resident

    if 6 <= global_temp < 7:
        background = pygame.image.load("image/background7.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (1 / 3) * population
        resident = (3 / 4) * resident
        Factory = (3 / 4) * Factory
        Power_plant = (3 / 4) * Power_plant
    if 8 <= global_temp < 9:
        background = pygame.image.load("image/background8.png").convert()
        background = pygame.transform.scale(background, (1050, 660))
        screen.blit(background, (0, 0))
        population = (1 / 5) * population
        resident = (1 / 5) * resident
        Factory = (1 / 5) * Factory
        Power_plant = (1 / 5) * Power_plant
    if 9 <= global_temp:
        wins = False
        break
    # quiet
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    # update
    pygame.display.update()
    clock.tick(60)

window_end = tk.Tk()

window_end.title(f"Your final score is{score}")
window_end.geometry("400x400")
tk.Label(window_end, text=f"Your final score is{score}").grid(row=1, column=0)
tk.Label(window_end, text="You built:").grid(row=2, column=0)
tk.Label(window_end, text=f"{Factory} Factory").grid(row=3, column=0)
tk.Label(window_end, text=f"{G_Factory} Green factory").grid(row=4, column=0)
tk.Label(window_end, text=f"{Power_plant} Power plant").grid(row=5, column=0)
tk.Label(window_end, text=f"{G_Power_plant} GreenPower plant").grid(row=6, column=0)
tk.Label(window_end, text=f"{resident} City").grid(row=7, column=0)
tk.Label(window_end, text=f"Your final \n population:{population}").grid(row=2, column=1)
tk.Label(window_end, text=f"Your development \n increased global \n temperature for:\n{global_temp}℃").grid(row=3,
                                                                                                            column=1)

tk.Label(window_end, text="ACHIEVEMENT:").grid(row=4, column=1)

G_building = G_Factory + G_Power_plant
B_building = Factory + Power_plant

if G_building > B_building:
    tk.Label(window_end, text="Environmentalists").grid(row=5, column=1)
elif B_building > G_building:
    tk.Label(window_end, text="Industry Expert").grid(row=5, column=1)
else:
    tk.Label(window_end, text="Balance（？）").grid(row=5, column=1)
if not wins:
    tk.Label(window_end, text="You loss").grid(row=6, column=1)

tk.Label(window_end, text="Contact us(me):\nxiyan.zhang@keystoneacademy.cn\nJeremyZ1012@outlook.cn").grid(row=11,
                                                                                                          column=0)

window_end.mainloop()
```

