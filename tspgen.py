import random
import sys
import numpy as np



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
