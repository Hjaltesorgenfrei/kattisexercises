a, b = [int(x) for x in input().split()]

a_res = 0
b_res = 0

for i in range(a):
    k = [int(x) for x in input().split()]
    a_res += k[0] * k[1]

for i in range(b):
    k = [int(x) for x in input().split()]
    b_res += k[0] * k[1]

if a_res == b_res:
    print("same")
else:
    print("different")