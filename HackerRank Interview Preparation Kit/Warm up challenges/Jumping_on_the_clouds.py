

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    i = 0
    count = 0
    while(i<len(c) - 1):
        if(((i+2)<len(c)) and (c[i+2] == 0)):
                count +=1
                i = i+2
        else:
            count+=1
            i+=1
    return count



n = int(input())

c = list(map(int, input().rstrip().split()))

result = jumpingOnClouds(c)

print(result)
