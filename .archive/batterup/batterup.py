n = int(input())
batterup = [int(x) for x in input().split()]
s = 0
for v in batterup:
    if v == -1:
        n -= 1
    else:
        s += v
print(s/n)