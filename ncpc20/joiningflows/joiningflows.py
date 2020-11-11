k = int(input())

taps = []

for i in range(k):
    taps.append([float(x) for x in input().split()])

r = int(input())



for f in taps:
    f.append((f[2] - f[1])/2 + f[1])
    print(f)



def calculate(v):
    t = 0
    fl = 0
    for f in v:
        t += f[3] * f[0]
        fl += f[3]
    print(f"t: {t/fl}, f: {fl}")

calculate(taps)

for i in range(r):
    temp, flow = [int(x) for x in input().split()]