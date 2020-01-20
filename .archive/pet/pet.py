winner, winnerscore = 0,0
for i in range(1,6):
    k = [int(x) for x in input().split()]
    s = sum(k)
    if s > winnerscore:
        winnerscore = s
        winner = i
print("{} {}".format(winner, winnerscore))