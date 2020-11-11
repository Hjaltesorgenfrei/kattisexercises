import sys

for l in sys.stdin:
    i = l.split()
    r = 0
    if i[1] == '+':
        r = (int(i[0]) + int(i[2])) % 10000
    elif i[1] == '*':
        r = (int(i[0]) * int(i[2])) % 10000
    elif i[1] == '^':
        r = (int(i[0]) ** int(i[2])) % 10000
    print(str(r)[-4:])