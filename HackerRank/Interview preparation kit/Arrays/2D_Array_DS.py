

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.
def hourglassSum(arr):
    maximum_sum = -sys.maxsize
    for i in range(4):
        for j in range(4):
            maximum_sum = max(maximum_sum,sum(arr[i][j:j+3])+arr[i+1][j+1]+sum(arr[i+2][j:j+3]))
    return maximum_sum




arr = []

for _ in range(6):
    arr.append(list(map(int, input().rstrip().split())))

result = hourglassSum(arr)

print(result)
