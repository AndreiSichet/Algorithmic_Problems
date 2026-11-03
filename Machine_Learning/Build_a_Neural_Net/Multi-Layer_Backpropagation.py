
import numpy as np
from typing import List


class Solution:
    def forward_and_backward(self,
                              x: List[float],
                              W1: List[List[float]], b1: List[float],
                              W2: List[List[float]], b2: List[float],
                              y_true: List[float]) -> dict:

        # Convert inputs to NumPy arrays
        x = np.array(x)
        W1 = np.array(W1)
        b1 = np.array(b1)
        W2 = np.array(W2)
        b2 = np.array(b2)
        y_true = np.array(y_true)

        # Forward propagation
        z1 = np.dot(x, W1) + b1
        r = np.maximum(0, z1)
        z2 = np.dot(r, W2) + b2

        # Mean Squared Error
        loss = np.mean(np.square(z2 - y_true))

        # Backward propagation: output layer
        delta2 = 2 * (z2 - y_true) / len(y_true)

        dW2 = np.outer(r, delta2)
        db2 = delta2

        # Backward propagation: hidden layer
        delta1 = np.dot(delta2, W2.T) * (z1 > 0)

        dW1 = np.outer(x, delta1)
        db1 = delta1

        # Return rounded gradients
        return {
            'loss': round(float(loss), 4),
            'dW1': np.round(dW1, 4).tolist(),
            'db1': np.round(db1, 4).tolist(),
            'dW2': np.round(dW2, 4).tolist(),
            'db2': np.round(db2, 4).tolist()
        }
