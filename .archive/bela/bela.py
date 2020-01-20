uff = input().split()
N = int(uff[0])
B = uff[1]
dom = {'A': 11, 'K': 4, 'Q': 3, 'J': 20, 'T': 10, '9':14, '8': 0, '7':0}
non = {'A': 11, 'K': 4, 'Q': 3, 'J': 2, 'T': 10, '9':0, '8': 0, '7':0}
s = 0
for i in range(N):
    for i in range(4):
        v = input()
        if v[1] == B:
            s += dom[v[0]]
        else:
            s += non[v[0]]
print(s)