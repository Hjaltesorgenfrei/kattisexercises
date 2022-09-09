import sys, decimal
for x in [l.strip().split() for l in sys.stdin.readlines()]:
    s = f"{decimal.Decimal(x[0]) / decimal.Decimal(x[1])}"[:2+int(x[2])]
    print(s.ljust(2+int(x[2]), '0'))