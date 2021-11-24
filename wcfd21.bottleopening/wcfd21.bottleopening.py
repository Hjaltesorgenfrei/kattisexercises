n = int(input())
k = int(input())
if n == k:
    print("impossible")
else:
    for i in range(1, n):
        print(f"open {i + 1} with 1")
        k -= 1
        if k == 0:
            exit()
