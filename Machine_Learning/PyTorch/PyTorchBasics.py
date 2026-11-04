import torch
import torch.nn
from torchtyping import TensorType

class Solution:
    def reshape(self, to_reshape: TensorType[float]) -> TensorType[float]:
        m, n = to_reshape.shape
        to_reshape = torch.reshape(to_reshape, (m*n//2, 2))
        return torch.round(to_reshape, decimals=4)

    def average(self, to_avg: TensorType[float]) -> TensorType[float]:
        to_avg = torch.mean(to_avg, dim=0)
        return torch.round(to_avg, decimals=4)

    def concatenate(self, cat_one: TensorType[float], cat_two: TensorType[float]) -> TensorType[float]:
        cat = torch.cat((cat_one, cat_two), dim=1)
        return torch.round(cat, decimals=4)

    def get_loss(self, prediction: TensorType[float], target: TensorType[float]) -> TensorType[float]:
        mse = torch.nn.functional.mse_loss(prediction, target)
        return torch.round(mse, decimals=4)