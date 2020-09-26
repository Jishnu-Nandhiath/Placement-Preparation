

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    count = 0
    for i in set(ar):
        count+=ar.count(i)//2
    return count


n = int(input())

ar = list(map(int, input().rstrip().split()))

result = sockMerchant(n, ar)

print(result)
