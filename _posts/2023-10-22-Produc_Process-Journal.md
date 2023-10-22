---
layout: post
title: >
    Product Creation-Drone
tags: [Test, Image, Keystone,AI]
excerpt_separator: <!--more-->
feature-img: "assets/img/MyTello.jpg"
thumbnail: "assets/img/MyTello.jpg"
---
Deploy the model to local device and imply real-time inference with drone.
<!--more-->
# Introduction
According to the result from the [previouse](https://jeremyzxi.github.io/2023/10/17/Product-Process_Journal.html) journal, it is not possible to control the drone using the output of the inference. However, it is still possible to use the video feed from the drone as input. To do so, we need to first develop a programm using the open-source SDK of tello to control the drone on device capable with inference, then read the video feed to conduct the inference.
![drone]({{ "assets/img/MyTello.jpg" | relative_url}})
# Tello Controll Programm
> Don’t reinvent the wheel, just realign it

Since we already have the wheels [djitellopy](https://github.com/dji-sdk/Tello-Python), we can just use it by import it.

Here we also need other libraries such as [pygame](https://www.pygame.org/news) to obtain keyboard input so we can control the drone using our latop.

**KeyPressModule.py**
```python
import pygame

def init():
    pygame.init()
    win = pygame.display.set_mode((400, 400))

def getKey(keyName):
    ans = False
    for eve in pygame.event.get(): pass
    keyInput = pygame.key.get_pressed()
    myKey = getattr(pygame,'K_{}'.format(keyName))
    if keyInput[myKey]:
        ans = True
    pygame.display.update()
    return ans

if __name__ == '__main__':
    init()
```
Then, we import **KeyPressModule.py** to our main control programm **KeyboardControl.py**.

 **KeyboardControl.py**
 ```python
 import logging
import time
import cv2
from djitellopy import tello
import KeyPressModule as kp
from time import sleep

def getKeyboardInput(drone, speed, image):
    lr, fb, ud, yv = 0, 0, 0, 0
    key_pressed = 0
    if kp.getKey("e"):
        cv2.imwrite('D:/snap-{}.jpg'.format(time.strftime("%H%M%S", time.localtime())), image)
    if kp.getKey("UP"):
        Drone.takeoff()
    elif kp.getKey("DOWN"):
        Drone.land()

    if kp.getKey("j"):
        key_pressed = 1
        lr = -speed
    elif kp.getKey("l"):
        key_pressed = 1
        lr = speed

    if kp.getKey("i"):
        key_pressed = 1
        fb = speed
    elif kp.getKey("k"):
        key_pressed = 1
        fb = -speed

    if kp.getKey("w"):
        key_pressed = 1
        ud = speed
    elif kp.getKey("s"):
        key_pressed = 1
        ud = -speed

    if kp.getKey("a"):
        key_pressed = 1
        yv = -speed
    elif kp.getKey("d"):
        key_pressed = 1
        yv = speed
    InfoText = "battery : {0}% height: {1}cm   time: {2}".format(drone.get_battery(), drone.get_height(), time.strftime("%H:%M:%S",time.localtime()))
    cv2.putText(image, InfoText, (10, 20), font, fontScale, (0, 0, 255), lineThickness)
    if key_pressed == 1:
        InfoText = "Command : lr:{0}% fb:{1} ud:{2} yv:{3}".format(lr, fb, ud, yv)
        cv2.putText(image, InfoText, (10, 40), font, fontScale, (0, 0, 255), lineThickness)

    drone.send_rc_control(lr, fb, ud, yv)

# main
# camera setting
Camera_Width = 720
Camera_Height = 480
PID_Parameter = [0.5, 0.0004, 0.4]
pErrorRotate, pErrorUp = 0, 0

# font
font = cv2.FONT_HERSHEY_SIMPLEX
fontScale = 0.5
fontColor = (255, 0, 0)
lineThickness = 1

# Tello initialize 
Drone = tello.Tello()  # create object
Drone.connect()  # connect to tello
Drone.streamon()  # start video feed transmission
Drone.LOGGER.setLevel(logging.ERROR)  # error log setting
sleep(5)  #  wait for the video to initialize
kp.init()  # initialize key press module


while True:
    OriginalImage = Drone.get_frame_read().frame
    Image = cv2.resize(OriginalImage, (Camera_Width, Camera_Height))
    getKeyboardInput(drone=Drone, speed=70, image=Image)  # 按键控制
    cv2.imshow("Drone Control Centre", Image)
    cv2.waitKey(1)
 ```
# Drone ✖️ AI
By combine the drone control program with the model:

```python
import os
import cv2
import numpy as np
import pandas as pd
import mediapipe as mp
import tensorflow as tf
from tensorflow.keras import layers
from tensorflow.keras import optimizers
from tensorflow.keras import Sequential

import pygame
import logging
import time
import cv2
from djitellopy import tello
from time import sleep


CLASS_NAMES=['Left_Swipe_new','Right_Swipe_new','Stop_new','Thumbs_Down_new','Thumbs_Up_new']
output_directory ="temp_storage"
class model:
    def __init__(self,CLASS_NAMES,model_pass,model2,output_directory):
        self.CLASS_NAMES=CLASS_NAMES
        self.model=tf.keras.models.load_model(model_pass)
        self.model.summary()
        self.model2=tf.keras.models.load_model(model2)
        self.output_directory=output_directory
    def detect_landmarks(self,image_folder):
        mp_holistic = mp.solutions.holistic.Holistic()
        image_files = sorted(os.listdir(image_folder))
        num_frames = len(image_files)
        num_landmarks = 33  # Fixed number of landmarks for pose estimation
        landmarks = np.zeros((num_frames,num_landmarks, 2))
        for i, file in enumerate(image_files):
            image_path = os.path.join(image_folder, file)
            frame = cv2.imread(image_path)
            # Convert the frame to RGB
            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            # Detect landmarks
            results = mp_holistic.process(frame_rgb)
            if results.pose_landmarks:
                for j, landmark in enumerate(results.pose_landmarks.landmark):
                    landmarks[i, j,] = [landmark.x, landmark.y]
        mp_holistic.close()
        return landmarks
    def inference(self,X):
        #CLASS_NAMES=['Left_Swipe_new','Right_Swipe_new','Stop_new','Thumbs_Down_new','Thumbs_Up_new']
        y_pred=np.argmax(self.model.predict(X), axis=1)
        #print(y_pred)
        print(self.CLASS_NAMES[y_pred[0]])
        return y_pred
    def inference2(self,X):
        CLASS_NAMES=['not_move','move']
        y_pred=np.argmax(self.model2.predict(X), axis=1)
        #print(y_pred)
        print(CLASS_NAMES[y_pred[0]])
        return y_pred
    def clear_files(self,folder_path):
        # 获取文件夹中的所有文件
        files = os.listdir(folder_path)
        # 删除每个文件
        for file in files:
            file_path = os.path.join(folder_path, file)
            if os.path.isfile(file_path):
                os.remove(file_path)
        print("-"*50)
        print("ALL Frames Cleared")
    def run(self):
        #self.clear_files(self.output_directory)
        frames = []
        frame_count = 0
        cap = cv2.VideoCapture(0)
        Camera_Height = 480
        DetectRange = [6000, 11000]  # params for future improvment
        PID_Parameter = [0.5, 0.0004, 0.4] # params for future improvment(PID)
        pErrorRotate, pErrorUp = 0, 0 # params for future improvment

        # 字体设置
        font = cv2.FONT_HERSHEY_SIMPLEX
        fontScale = 0.5
        fontColor = (255, 0, 0)
        lineThickness = 1
        Drone = tello.Tello()  # Create drone object
        Drone.connect()  # Connect to drone
        Drone.streamon()  # Start video transmission
        Drone.LOGGER.setLevel(logging.ERROR)  # Only show error information
        sleep(5)  # Wait for video to initialize
        
        while True:
            frame =  Drone.get_frame_read().frame
            if True:
                frame_name = os.path.join(self.output_directory, f"frame_{frame_count}.png")
                cv2.imwrite(frame_name, frame)
                frame_count += 1

                if frame_count == 30:
                    print("="*50)
                    X_data = self.detect_landmarks(self.output_directory).reshape((1,30,66))
                    self.clear_files(self.output_directory)
                    #y_check=self.inference2(X_data)
                    frame_count = 0
                    #if y_check==1:
                    y_pred=self.inference(X_data)
                    print(f"Movement Type:{self.CLASS_NAMES[y_pred[0]]}, index:{y_pred[0]}")
                        
                cv2.imshow('Camera', frame)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        cap.release()
        cv2.destroyAllWindows
def main():  
    model(CLASS_NAMES,"231008RNNV5.h5","231012RNN_2V5.h5",output_directory).run()
if __name__ == '__main__':
    main()
```
We complete our final product.

<video src="
https://github.com/JeremyZXi/jeremyzxi.github.io/assets/144130528/78e675f3-4b70-4037-bfaf-45d34615a9e1" controls="controls">
Your browser doesn't support "video" tage
</video>

- Special Thanks: ***Songmian Jerry Li***, for show up in the video

# Reflection
Up to now, the product was officially completed, further improvement will be aplly, but maybe after completing the entire personal product. 
### Technical details
Using the video feed of a drone doesn't really make any difference if we maintain the height of the frame to our upper body. With the advent of motility, the device can now turn in more directions. However, the height of the drone must be maintained at chest level. The accuracy and percision of the inference using the video feed from the drone vary in an acceptable range—～0.001.
| Category | Precision | 
|----------|-----------|
| 1        | 0.8     |
| 2        | 0.8      |
| 3        | 0.75      |
| 4        | 0.70      |
| 5        | 0.64      |

Overall Accuracy: 0.74<br>
Based on the table above, we can see that the precision and accuracy scores are all above 0.6. However, the test was conducted in a way that was very similar to the test on a laptop. This means that in real life, this model might not work well. In addition to that, the model messes up when more than one person appears on camera. The landmark algorithm only detects the body landmark of one person. Furthermore, the model cannot identify if the person there is doing one of the movements or not.
### Possible improvement
- Multi-Person Detection: At the moment, my model struggles when more than one person appears in the camera's view. I could improve the model to detect and differentiate between multiple people.

- Height Adjustment: The drone needs to maintain a certain height level to accurately infer movements. I could develop a mechanism for the drone to automatically adjust its height based on the person's position. This can be done my train a model that detect certain body part.

- Improved Accuracy: While the model's precision and accuracy are acceptable, there's always room for improvement. I could refine my model with more training data, or consider using more advanced models or techniques. The data set for example, should include extreme condition to improve the model's generalization ability. Furthermore, adujust the framework of the RNN model or use a combination of different model might help

- Real-Life Testing: The model was tested in conditions similar to a laptop environment. To ensure it works well in real-life scenarios, I could conduct tests in various environments with different lighting conditions, distances, and angles.

- Movement Detection: The model currently struggles to identify if a person is performing one of the movements or not. I could improve this by training my model with more diverse data, including instances where no specific movement is being performed.

- Gesture Customization: I could allow users to define their own gestures and corresponding drone actions. This would make the product more versatile and user-friendly. This could be done by fit the pre-trained model with the assigned gesture
