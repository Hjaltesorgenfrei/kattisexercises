import sys
s1 = sys.stdin.readline()
s2 = sys.stdin.readline()

t1 = [int(s1[0]), int(s1[1]), int(s1[3]), int(s1[4])]
t2 = [int(s2[0]), int(s2[1]), int(s2[3]), int(s2[4])]


counter = 0

def up(tp1, tp2, maxv):
    r = []
    i = 0
    if tp1 % maxv == tp2:
        return r
    while True:
        i += 1
        r.append((tp1 + i) % maxv)
        if (tp1 + i) % maxv == tp2:
            break
    return r

def down(tp1, tp2, maxv):
    r = []
    i = 0
    if tp1 == tp2:
        return r
    while True:
        tp1 -= 1
        if tp1 < 0:
            tp1 = maxv -1
        r.append((tp1 - i))
        if tp1 == tp2:
            break
    return r

def fancyprint(t):
    print("{}{}:{}{}".format(*t))


def getsmallest(t1,t2,maxv,i):
    return up(t1[i], t2[i], maxv) if len(up(t1[i], t2[i], maxv)) < len(down(t1[i], t2[i], maxv)) else down(t1[i], t2[i], maxv)

hour1 = getsmallest(t1,t2,3,0)
hour2 = getsmallest(t1,t2,10,1)
min1 = getsmallest(t1,t2,7,2)
min2 = getsmallest(t1,t2,10,3)
counter = 1 + len(hour1) + len(hour2) +len(min1) + len(min2)

print(counter)

fancyprint(t1)

for v in hour1:
    counter+= 1
    t1[0] = v
    fancyprint(t1)
for v in hour2:
    counter+= 1
    t1[1] = v
    fancyprint(t1)
for v in min1:
    counter+= 1
    t1[2] = v
    fancyprint(t1)
for v in min2:
    counter+= 1
    t1[3] = v
    fancyprint(t1)
