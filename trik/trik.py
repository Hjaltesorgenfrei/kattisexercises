p = 0
for c in input():
    if c == "A":
        if p == 0:
            p = 1
        elif p == 1:
            p = 0
    elif c == "B":
        if p == 1:
            p = 2
        elif p == 2:
            p = 1
    elif c == "C":
        if p == 0:
            p = 2
        elif p == 2:
            p = 0
p = p + 1
print(p)
