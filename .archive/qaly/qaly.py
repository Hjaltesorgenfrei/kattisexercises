n = int(input())
k = 0.0
while n is not 0:
    q =  [float(x) for x in input().split()]
    k += q[0] * q[1]
    n -= 1

print (k)