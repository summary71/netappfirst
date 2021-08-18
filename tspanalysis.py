import sys
import numpy as np
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
