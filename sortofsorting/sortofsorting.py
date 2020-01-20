alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet = alphabet.upper() + alphabet.lower()
n = int(input())
while True:
    names = []
    while n is not 0:
        names.append(input())
        n -= 1
    names = sorted(names, key=lambda x:[alphabet.index(c) for c in x[:2]])
    for name in names:
        print(name)
    n = int(input())
    if n == 0:
        quit()
    print()