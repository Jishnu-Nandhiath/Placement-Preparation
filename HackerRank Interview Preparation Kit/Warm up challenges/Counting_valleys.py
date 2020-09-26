

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    total = 0
    c= 0
    for i in range(n):
        if(s[i] == 'U'):
            total += 1
            if(total == 0 and i!=0):
                c+=1
        else:
            total -= 1
    return c

n = int(input())

s = input()

result = countingValleys(n, s)

print(result)
