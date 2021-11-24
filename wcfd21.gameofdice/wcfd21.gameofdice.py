l = [input().split('| |') for _ in range(5)]
k = [0, 0, 0, 0, 0]
for i in range(5):
    k[i] += l[1][i].count('o')
    k[i] += l[2][i].count('o')
    k[i] += l[3][i].count('o')

for i in range(1, 7):
    print(k.count(i) * i, end=" " if i != 6 else "\n")

of_kind = [0, 0, 0, 0, 0, 0]
for i in k:
    of_kind[i - 1] += 1

def pair():
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 2:
            return (i) * 2
    return 0

def two_pairs():
    first_pair = -1
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 2:
            first_pair = i
    if first_pair == -1:
        return 0
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 2 and i != first_pair:
            return first_pair * 2 + i * 2
    return 0


def three_of_a_kind():
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 3:
            return (i) * 3
    return 0

def four_of_a_kind():
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 4:
            return (i) * 4
    return 0

def full_house():
    first_pair = -1
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 3:
            first_pair = i
    if first_pair == -1:
        return 0
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 2 and i != first_pair:
            return first_pair * 3 + i * 2
    return 0

def small_straight():
    if of_kind[0] and of_kind[1] and of_kind[2] and of_kind[3] and of_kind[4]:
        return 15
    return 0

def large_straight():
    if of_kind[1] and of_kind[2] and of_kind[3] and of_kind[4] and of_kind[5]:
        return 20
    return 0

def yatzy():
    for i in range(6, 1, -1):
        if of_kind[i - 1] >= 5:
            return 50
    return 0

def chance():
    return sum(k)

for f in [pair, two_pairs, three_of_a_kind, four_of_a_kind, full_house, small_straight, large_straight, yatzy, chance]:
    print(f(), end=" " if f != chance else "")
print()