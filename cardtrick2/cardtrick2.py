def do(ma):
    table = []
    cards = []
    for i in range(ma):
        table.append(i+1)
    for i in range(ma):
        cards.insert(0, table.pop())
        for j in range(ma - i):
            cards.insert(0, cards.pop())
    print(*cards, sep=" ")


n = int(input())





for i in range(n):
    v = int(input())
    do(v)