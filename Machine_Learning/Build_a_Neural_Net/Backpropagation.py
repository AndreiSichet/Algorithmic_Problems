import numpy as np
from numpy.typing import NDArray
from typing import Tuple


class Solution:
    def backward(self, x: NDArray[np.float64], w: NDArray[np.float64], b: float, y_true: float) -> Tuple[NDArray[np.float64], float]:
        # x: 1D input array
        # w: 1D weight array
        # b: scalar bias
        # y_true: true target value
        #
        # Forward: z = dot(x, w) + b, y_hat = sigmoid(z)
        # Loss: L = 0.5 * (y_hat - y_true)^2
        # Return: (dL_dw rounded to 5 decimals, dL_db rounded to 5 decimals)
        z=np.dot(x,w)+b
        sig=1.0/(1.0+np.exp(-z))
        l=0.5*np.square(sig-y_true)
        dl_dw=(sig-y_true)*sig*(1.0-sig)*x
        dl_db=(sig-y_true)*sig*(1.0-sig)
        dl_dw=np.round(dl_dw,5)
        dl_db=np.round(dl_db,5)
        return (dl_dw,dl_db)
