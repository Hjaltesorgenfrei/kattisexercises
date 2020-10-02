import random
import string

v = [int(x) for x in input().split()]

d = {}
alphabetLength = len(string.ascii_lowercase)
n = v[1]
for i in range(n):
    printed = False
    while not printed:
        w = string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)] + string.ascii_lowercase[random.randint(0, alphabetLength - 1)]
        if w not in d:
            print(w, end="")
            printed = True
    if i != n-1:
        print(" ", end="")
    else:
        print("")
