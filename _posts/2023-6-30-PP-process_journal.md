---
layout: post
title: >
    Personal Project
author: JeremyZhang
tags: [Test, Image, Keystone,AI,MYP Personal Project
]
excerpt_separator: <!--more-->
---
# Personal Project Process Journal

Click [here](https://minhaskamal.github.io/DownGit/#/home?url=https://github.com/JeremyZXi/jeremyzxi.github.io/blob/master/files/LearningProcess.zip) to download the code and materials I used in the learning process.
<!--more-->

files end with **.ipynb** require special software/plugins to open it. To view or edit them online, try [Jupyter lab](https://jupyter.org/try-jupyter/lab/)


- ## Intro to Machine Learning
    Two types of Machine learning model:
        Where the first type requires labels called 
        **Supervised Learning**
         and the second type does not called **Unsupervised Learning**.<br><br>
         With in **Supervised Learning**, there are two kinds of tasks: "***Classification***" where the unknown value is a **category** and "***Regression***" where the unknown value is a **number**
        
    - ### linear Regression
        **Linear regression** employs a straightforward method to model the connection between a single output value and one or more input factors (referred to as the response and predictor variables, respectively).<br><br>
        We aim for a line that best fit the data. To do so, we want to minimize the distances from each data to the line<br>
        ![linear]({{ "assets/img/pexels/linear.png" | relative_url}})
        - Sample Code 
        ```python
            import numpy as np
            from sklearn.linear_model import LinearRegression
            from sklearn.model_selection import train_test_split
            from sklearn.metrics import mean_squared_error, r2_score
            
            # Step 1: Data Preparation
            # Load the dataset (X: features, y: target variable)
            X = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
            y = np.array([10, 20, 30])
            
            # Split the data into training and testing sets
            X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
            
            # Step 2: Model Initialization
            # Initialize the linear regression model
            model = LinearRegression()
            
            # Step 3: Model Training
            # Train the linear regression model using the training data
            model.fit(X_train, y_train)
            
            # Step 4: Model Evaluation
            # Evaluate the trained model using the testing data
            y_pred = model.predict(X_test)
            
            # Calculate performance metrics (MSE, R-squared)
            mse = mean_squared_error(y_test, y_pred)
            r2 = r2_score(y_test, y_pred)
            
            print("Mean Squared Error:", mse)
            print("R-squared:", r2)
            
            # Step 5: Prediction
            # Use the trained model to make predictions on new, unseen data
            new_data = np.array([[2, 3, 4], [5, 6, 7]])
            predictions = model.predict(new_data)
            print("Predictions:", predictions)
            
            # Step 6: Model Interpretation
            # Access the learned model coefficients and intercept
            coefficients = model.coef_
            intercept = model.intercept_
            print("Coefficients:", coefficients)
            print("Intercept:", intercept)
            ```
            Here we use a nd array as the input, noticed that in actual task:
            ```python
            import pandas as pd
            
            raw_data = pd.read_csv('path/to/csv/file.csv')
        ```
        will be an easier approach. pd.read_csv read the csv into a ***dataframe*** where data is organized in rows and columns. Than, we can use the train_test_split function from sklearn:
        ```python
            from sklearn.model_selection import train_test_split
            X_train, X_test, y_train, y_test = train_test_split(
                                        data[["feature1","feature2"]],
                                        data["target"],
                                        test_size = 0.3)
        ```
  - ## Machine Learning and Classification
      Classification task basically means to predict a category. For example, is that creature right over there a cat, a dog, a horse, or as human? <br>
      **This is the type of problem that my project aim to solve.**
      - Basic Classification Models
          - Decision Tree
          - Nearest Neighbor Classification
          - Logistic Regression (although this is called "regression" as the math behind it work like a regression, but this model is for classification)<br><br>
      **Note* model listed above may not function well in my product as they are relatively simple for image processing.<br><br>
      - Sample Code
      ```python
          import numpy as np
        from sklearn.tree import DecisionTreeClassifier
        from sklearn.model_selection import train_test_split
        from sklearn.metrics import accuracy_score
        
        # Step 1: Data Preparation
        # Load the dataset (X: features, y: target variable)
        X = np.array([[1, 2], [2, 3], [3, 1], [4, 4]])
        y = np.array([0, 0, 1, 1])
        
        # Split the data into training and testing sets
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
        
        # Step 2: Model Initialization
        # Initialize the Decision Tree classifier
        tree = DecisionTreeClassifier()
        
        # Step 3: Model Training
        # Train the Decision Tree classifier using the training data
        tree.fit(X_train, y_train)
        
        # Step 4: Model Evaluation
        # Evaluate the trained model using the testing data
        y_pred = tree.predict(X_test)
        
        # Calculate the accuracy of the model
        accuracy = accuracy_score(y_test, y_pred)
        print("Accuracy:", accuracy)
        
        # Step 5: Prediction
        # Use the trained model to make predictions on new, unseen data
        new_data = np.array([[2, 2], [3, 3]])
        predictions = tree.predict(new_data)
        print("Predictions:", predictions)
    ```
- ## Computer Vision and Neural Networks
    More complex model is needed for processing more complex data. Here is where Neural Newroks turns out to be useful. <br><br>
    - Image
    A image with color contains three channels:R, G, and B
    ![RGB_Sample]({{ "assets/img/RGB_sample.png" | relative_url}})
    Each pixel on each channel can be represented by a number between 0 to 255. We can than read these numbers into an array as the inputs. <br><br>
    - Neural Networks
    ![NN_architecture]({{ "assets/img/NN_architecture.png" | relative_url}})
    Neural network


## Introduction
Neural networks are a set of algorithms, modeled loosely after the human brain, designed to recognize patterns. They interpret sensory data through a kind of machine perception, labeling or clustering raw input.

## Convolutional Neural Networks (CNN)
CNNs are deep learning algorithms used primarily to classify images, cluster them by similarity, and perform object recognition.

### Structure of CNN
- **Input Layer:** This is where the network takes in the image data.
- **Convolutional Layer:** This layer applies a specified number of convolution filters to the image.
- **ReLU Layer:** This layer applies the rectified linear unit activation function, which adds non-linearity to the network.
- **Pooling Layer:** This layer reduces the spatial size of the convolved feature, which decreases the computational power required.
- **Fully Connected Layer:** This layer identifies and classifies the objects in the image.

## Recurrent Neural Networks (RNN)
RNNs are a type of artificial neural network designed to recognize patterns in sequences of data, such as text, genomes, handwriting, or spoken word.

### Structure of RNN
- **Input Vector:** This is the encoded form of the data point being fed into the neural network.
- **Hidden Layer:** This layer performs computations on the inputs and passes the results and the previous hidden state forward.
- **Output Layer:** This layer produces the prediction for the given input.

## Other Models
- **Long Short-Term Memory (LSTM):** A type of RNN that can learn and remember over long sequences, useful in sequence prediction problems.
- **Generative Adversarial Networks (GANs):** A class of AI algorithms used in unsupervised machine learning, implementing two neural networks contesting one another in a zero-sum game framework.
- **Autoencoders:** A type of artificial neural network used to learn efficient data codings in an unsupervised manner.

## Applications of Neural Networks in Computer Vision
- Image and Video Recognition
- Image Analysis
- Classification and Clustering
- Object Detection
- Semantic Segmentation
- Image Generation

