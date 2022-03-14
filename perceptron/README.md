# Square/Circle Classification

## Introduction
`Perceptron` explores the convergence of a neural network with no hidden layers with the Perceptron Learning Algorithm (PLA), an algorithm based on the Perceptron Convergence Theorem. This exploration follows the theory outlined [here](https://web.mit.edu/course/other/i2course/www/vision_and_learning/perceptron_notes.pdf).

## Perceptron Convergence Theorem
Given a set of linearly separable data, the weights of a perceptron will converge to a hyperplane separating the data.

## Perceptron Learning Algorithm (PLA)
1. Feed image through perceptron.
2. Update weights with $w_{n+1} = w_n + \gamma y_n X_n$
    * $w_{n+1}$ is the updated weights after the last step
    * $w_n$ is the weights of the last step
    * $\gamma$ is a learning speed constant
    * $y_n$ is the given correct classification
    * $X_n$ is the input matrix
3. If max traning steps reached or all inputs have been correctly identified, return weights.

## Impelemntation
### Neural Network Class
* Wraps 2D array where each row represents the weights of a layer.
* Shape is vector where each element represents the size of a layer in the network.

### Image Class
