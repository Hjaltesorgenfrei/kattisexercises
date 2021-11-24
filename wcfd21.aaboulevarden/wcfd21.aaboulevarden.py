from collections import defaultdict
from bisect import bisect

beers = defaultdict(list)
for i in range(int(input())):
    beers[input()].append(i)

for i in range(int(input())):
    x, s = input().split()
    x = int(x)
    l = bisect(beers[s], x)
    if l == 0:
        print(beers[s][l] - x)
        continue
    if l == len(beers[s]):
        print(beers[s][l - 1] - x)
        continue
    forward = beers[s][l]
    backwards = beers[s][l - 1]
    if abs(forward - x) < abs(backwards - x):
        print(forward - x)
    else:
        print(backwards - x)