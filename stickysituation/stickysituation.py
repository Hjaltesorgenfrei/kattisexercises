import sys
sticks = sorted([int(x) for x in sys.stdin.readlines()[1].split(" ")])
for i in range(len(sticks) - 2):
    for j in range(i + 1, len(sticks) - 1):
        if not sticks[i] + sticks[j] <= sticks[j+1]:
            print "possible"
            quit()
        else:
            continue
print "impossible"
