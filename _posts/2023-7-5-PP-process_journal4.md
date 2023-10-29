---
layout: post
title: >
    Personal Project 3
tags: [Test, Image, Keystone,AI]
excerpt_separator: <!--more-->
---
# The Mathematics Behind Neural Networks
 <!--more-->


Neural networks are a class of models within the general machine learning literature. They are inspired by biological neural networks and are used to estimate or approximate functions that depend on a large number of inputs.

## Perceptron

The simplest kind of neural network is a single-layer perceptron, which consists of a single layer of output nodes connected to a layer of input nodes.

The sum of the products of the weights and the inputs is calculated in each node, and if the value is above some threshold (typically 0) the neuron fires and takes the activated value (typically 1).

```markdown
output = activation(weight1 * input1 + weight2 * input2 + ... + weightN * inputN + bias)
```

where the activation function is often a step function (Heaviside Step function).

## Multi-Layer Perceptron (MLP)

A Multi-Layer Perceptron has one or more hidden layers of nodes between the input and the output layer. This allows the model to learn more complex functions.

```markdown
hidden_output = activation(weight1 * input1 + weight2 * input2 + ... + weightN * inputN + bias)
output = activation(weight1 * hidden_output1 + weight2 * hidden_output2 + ... + weightN * hidden_outputN + bias)
```

where the activation function is often a non-linear function like sigmoid, tanh, or ReLU.

## Backpropagation

Backpropagation is a method used to train neural networks, involving calculating the gradient of the loss function with respect to the weights of the network.

```markdown
delta = (expected_output - actual_output) * derivative_of_activation_function
weight_update = learning_rate * delta * input
```

## Loss Functions

Loss functions measure the inconsistency between predicted value (y') and actual label (y). Common loss functions include Mean Squared Error for regression tasks, and Cross Entropy for classification tasks.

```markdown
Mean Squared Error (MSE): 1/N * Σ(y - y')²
Cross Entropy: -1/N * Σ(y * log(y') + (1 - y) * log(1 - y'))
```

## Gradient Descent

Gradient Descent is an optimization algorithm used to minimize the loss function by iteratively moving in the direction of steepest descent.

```markdown
weight = weight - learning_rate * ∂(loss)/∂(weight)
```

## Activation Functions

Activation functions decide whether a neuron should be activated or not. Common activation functions include sigmoid, tanh, ReLU and softmax.

```markdown
Sigmoid: 1 / (1 + e^(-x))
tanh: (e^(x) - e^(-x)) / (e^(x) + e^(-x))
ReLU: max(0, x)
Softmax: e^(x[i]) / Σ(e^(x[j]))
```
