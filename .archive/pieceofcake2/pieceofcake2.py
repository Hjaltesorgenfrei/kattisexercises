n = [int(x) for x in input().split()]
h = max(n[0] - n[1], n[1])
v = max(n[0] - n[2], n[2])
print(h*v*4)