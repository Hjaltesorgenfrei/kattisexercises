for i in range(int(input())):
    n = [int(x) for x in input().split()]
    v = n[1] - n[2]
    if v == n[0]:
        print("does not matter")
    elif v < n[0]:
        print("do not advertise")
    elif v > n[0]:
        print("advertise")