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

