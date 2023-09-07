---
layout: post
title: >
    Product Creation
tags: [Test, Image, Keystone,AI]
excerpt_separator: <!--more-->
---
Collect data and try different appraoches
<!--more-->
- ## Data
    Data is the 'soul' of the product, as the quality of the data directly affects the accuracy of the model. For this specific task, I need labeled images containing people performing different movements. Collecting all the data by myself would be a challenging task. Fortunately, I discovered a relevant dataset online. Although I won't be able to create the dataset from scratch, it is still a helpful and wise choice.
    [link to the dataset](https://www.kaggle.com/datasets/imsparsh/gesture-recognition)

- ## Codes
    - version 1
    ```python
    import os
    import cv2
    import numpy as np
    import pandas as pd
    from tensorflow.keras.models import Sequential
    from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense
    from PIL import Image
    import matplotlib.pyplot as plt
    import seaborn as sns
    import random
    ```

    ```python
    #load data doc
    dataset_path = "/kaggle/input/gesture-recognition"
    train_csv = pd.read_csv('/kaggle/input/train-doc/train_new.csv')
    train_csv.head()
    ```

    ```python
    import matplotlib.pyplot as plt
    import matplotlib.image as mpimg

    # Load the image
    image = mpimg.imread("/kaggle/input/gesture-recognition/train/WIN_20180907_15_45_40_Pro_Left Swipe_new_Left Swipe_new/WIN_20180907_15_45_40_Pro_00045.png")

    # Display the image
    plt.imshow(image)
    plt.axis('on')

    # Show the plot
    plt.show()
    ```
    ![sample_face]({{"assets/img/sample_face.png" | relative_url}})

    ```python
    #size of the image
    pic_size = 120
    images = np.empty((19860, pic_size, pic_size,1), dtype=np.uint8)
    label = []
    text = []
    train_size = train_csv.shape
    i = 0
    for n in range(train_size[0]):
        subPath = train_csv.loc[n,'File'] #get name of the sub file from train_csv
        folder_path = '/kaggle/input/gesture-recognition/train/'+subPath #path of the subfile
        
        #read images
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                image_path = os.path.join(root, file)
                image = cv2.imread(image_path)
                image = cv2.resize(image, (pic_size, pic_size))
                image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                image = image.reshape((pic_size, pic_size, 1))
                images[i] = image
            
                label.append(train_csv.loc[n,'Inde'])
                text.append(train_csv.loc[n,'Name'])
                i+=1
    labels = np.array(label)
    print(labels.shape)
    print(images.shape)
    seed = 25
    np.random.seed(seed)
    np.random.shuffle(images)

    np.random.seed(seed)
    np.random.shuffle(labels)
    ```
    convert the image into array and save them into an array
    ```python
    from sklearn.model_selection import train_test_split

    X = images[:10000, : , : ]
    y = labels[:10000]
    seed = 43
    np.random.seed(seed)
    np.random.shuffle(X)

    np.random.seed(seed)
    np.random.shuffle(y)
    ```
    Shuffle and split the data set
    ```python
    import tensorflow as tf
    from tensorflow import keras

    # Assuming you have your data and labels loaded as X and y respectively
    num_classes = 5

    # Normalize the pixel values between 0 and 1
    X = X / 255.0

    # Split the data into training and validation sets
    train_ratio = 0.8  # 80% of the data for training, adjust as needed
    split_index = int(train_ratio * len(X))

    X_train, X_val = X[:split_index], X[split_index:]
    y_train, y_val = y[:split_index], y[split_index:]
    # Import the required libraries
    from keras.models import Sequential
    from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense

    model = Sequential()
    model.add(Conv2D(32, (3, 3), activation='relu', input_shape=(pic_size, pic_size, 1)))
    model.add(MaxPooling2D((2, 2)))
    model.add(Flatten())
    model.add(Dense(64, activation='relu'))
    model.add(Dense(5, activation='softmax'))

    # Compile the model
    model.compile(optimizer='adam',
                loss='sparse_categorical_crossentropy',
                metrics=['accuracy'])

    # Train the model
    model.fit(X_train, y_train, epochs=10, batch_size=32, validation_data = (X_val, y_val))
    ```
    train the model

    ```python
    te = int(input())
    correct = 0
    for i in range(te):   
        numToText = {0:'Left_Swipe_new',1:'Right_Swipe_new',2:'Stop_new',3:'Thumbs_Down_new',4:'Thumbs_Up_new'}
        rand = random.randint(0,19860)
        test_image = images[rand]
        test_image = test_image.reshape((1,pic_size, pic_size, 1))/255.0
        prediction = model.predict(test_image)
        print("prediction",np.argmax(prediction),numToText[np.argmax(prediction)])
        plt.imshow(images[rand])
        print("actual",labels[rand])
        if np.argmax(prediction) == labels[rand]:
            correct+=1
    print(f"out of {te} prediction, {correct} was correct. The accuracy was {100*(correct/te)}%")
    ```
    Something went wrong here:
    ![error_version1]({{"assets/img/error_version1.png" | relative_url}})
