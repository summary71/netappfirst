from __future__ import print_function
from datetime import datetime
import time
import sys
import math
import json
import os
import random
import numpy as np
from re import sub

import copy



numofnodes = int(sys.argv[1])
width = int(sys.argv[2])
height = int(sys.argv[3])
sval = int(sys.argv[4])

random.seed(sval)

for k in range(1):
  n = numofnodes
  print(n)
  for i in range(n):
    a = random.randrange(1, width)
    b = random.randrange(1, height)
    print(a, b)
