import sys
import math
a,b = map(int,sys.stdin.readline().split())
print(int(math.ceil(a/math.sin(math.radians(b)))))