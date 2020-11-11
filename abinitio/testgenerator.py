import random

v = 2000
e = 1
q = 100

print (f"{v} {e} {q}")
for i in range(e):
    x = random.randint(0, 1999)
    y = random.randint(0, 1999)
    while x == y:
        y = random.randint(0, 1999)
    print (f"{x} {y}")

for i in range(q):
    n = random.randint(1, 6)
    x = random.randint(0, 1999)
    y = random.randint(0, 1999)
    while x == y:
        y = random.randint(0, 1999)
    if n == 1:
        print(f"{1}")
    elif n == 2:
        print(f"{2} {x} {y}")
    elif n == 3:
        print(f"{3} {x}")
    elif n == 4:
        print(f"{4} {x} {y}")
    elif n == 5:
        print(f"{5}")
    elif n == 6:
        print(f"{6}")