def position_valid(*p):
    x, y = p[0]
    if (y == 0 or y == 4) and (x < 3 or x > 5): #Holes
        return False
    return 0 <= x < 9 and 0 <= y < 5

def get_moves(pegs):
    possible_moves = []
    for p in pegs:
        x, y = p
        moves = [((x-2, y), (x-1, y)), ((x+2, y), (x+1, y)), ((x, y-2), (x, y-1)), ((x, y+2), (x, y+1))]
        for landing, jumped in moves:
            if position_valid(landing) and jumped in pegs:
                move = list(pegs)
                move.remove((x, y))
                move.remove(jumped)
                move.append(landing)
                possible_moves.append(tuple(move))
    return possible_moves

solved = {}

def solve(pegs):
    possible = get_moves(pegs)
    if len(possible) == 0:
        return len(pegs)
    mi = 10000
    for move in possible:
        if move not in solved:
            solved[move] = solve(move)
        mi = min(solved[move], mi)
    return mi

cases = int(input())
for n in range(cases):
    pegs = []
    for y in range(5):
        line = input()
        for x, c in enumerate(line):
            if c == 'o':
                pegs.append((x, y))

    if n + 1 != cases:
        input()
    sol = solve(tuple(pegs))
    print(f"{sol} {len(pegs) - sol}")
