invertedMap = {
    "0": "0",
    "1": "1",
    "8": "8",
    "6": "9",
    "9": "6"
}
from functools import cmp_to_key

def cmp(x, y):
        return 1 if x<y else ( 0 if x==y else -1)

def minnum(x):
    return ''.join(sorted((str(n) for n in x), key=cmp_to_key(lambda x,y:cmp(y+x, x+y))))

def smallest(numeral):
    if '2' in num or '3' in num or '4' in num or '5' in num or '7' in num:
        return numeral
    rev = numeral[::-1]
    s = ""
    for i in range(len(rev)):
        s += invertedMap[rev[i]]
    if int(s) < int(numeral):
        return s
    else:
        return numeral

n = int(input())
numbers = []

for i in range(n):
    num = input()
    num = smallest(num)
    numbers.append(num)
    numbers = sorted(numbers)

print(minnum(numbers))