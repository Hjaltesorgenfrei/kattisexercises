import math
n = input()
i = 1
res = 1
if len(n) < 7:
    while(True):
        if res == int(n):
            print(i)
            exit(0)
        if i > 8:
            break
        i += 1
        res *= i

res = 0
i = 1
while(True):
    res += math.log10(i)
    if math.floor(res) + 1 > len(n):
        print(i - 1)
        break
    i += 1