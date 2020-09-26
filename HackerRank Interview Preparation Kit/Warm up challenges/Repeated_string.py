

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    remaining_a = 0
    count_a_in_s = s.count('a')
    repetition = n//len(s)
    if((len(s)%n)!=0):
        remaining_a = s[0:(n%len(s))].count('a')
    return count_a_in_s*repetition + remaining_a




s = input()

n = int(input())

result = repeatedString(s, n)

print(result)
