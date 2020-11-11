n = int(input())

values = [int(x) for x in input().split()]

m = (10**9) + 7

ones = 0
combinations = 0
result = 0

for v in values:
    if v == 1:
        ones += 1
    elif v == 2:
        combinations *= 2
        combinations += ones
        
        while combinations > m:
            combinations -= m
    elif v == 3:
        result += combinations
        while result > m:
            result -= m

print(str(result % m))