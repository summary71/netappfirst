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


from sys import stdin

distances = {}
for line in stdin:
  [n, seedval, dist] = line.split()
  n = int(n)
  seedval = int(seedval)
  dist = float(dist)
  if n not in distances:
    distances[n] = []
  distances[n].append(dist)

for n in sorted(distances.keys()):
  print("%d %.2f %.2f %.2f"%(n, min(distances[n]), np.average(distances[n]), max(distances[n])))
