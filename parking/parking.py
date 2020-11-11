import sys
a, b, c = map(int, sys.stdin.readline().split())
cost = [0, a, b, c]
cars = [0] * 100
for i in range(3):
    start, end = map(int, sys.stdin.readline().split())
    for j in range(start - 1, end - 1):
        cars[j] += 1
sum = 0
for c in cars:
    sum += cost[c] * c
print(sum)