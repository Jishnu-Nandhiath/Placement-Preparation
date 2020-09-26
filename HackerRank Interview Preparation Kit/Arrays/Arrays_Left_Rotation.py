
import math
import os
import random
import re
import sys

# Complete the rotLeft function below.
def rotLeft(a, d):
    out = a[d:]+a[0:d]
    s=''
    return out


nd = input().split()

n = int(nd[0])

d = int(nd[1])

a = list(map(int, input().rstrip().split()))

result = rotLeft(a, d)

print(str(' '.join(map(str,result))))
