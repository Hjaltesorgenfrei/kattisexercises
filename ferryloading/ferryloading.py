import sys
port = 0
starboard = 0

lines = [int(x) for x in sys.stdin.readlines()]
boat = int(lines.pop(0))*100
port = boat
starboard = boat
p = []
p.append("")

for c in lines:
    if c == 0: 
        break
    if port - c < 0 and starboard - c < 0:
        break
    if port > starboard:
        p.append("port")
        port -= c
    else:
        p.append("starboard")
        starboard -= c
p[0] = len(p) - 1
for v in p:
    print(v)