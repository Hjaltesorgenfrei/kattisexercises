def increment(n):
    s = str(n)
    for i, c in enumerate(s):
        if c != "9":
            d = 9
            result = s[:i] + str(d) + s[i+1:]
            return int(result)
    return n

def decrement(n):
    s = str(n)
    if len(s) == 1:
        return 0
    for i, c in enumerate(s):
        if c != "0" and not (c == "1" and i == 0):
            d = 0
            if i == 0:
                d = 1
            result = s[:i] + str(d) + s[i + 1:]
            return int(result)
    return n

def ans():
    amount = int(input())
    numbers = [int(x) for x in input().split(" ")]
    for i in range(len(numbers) - 1):
        if increment(numbers[i]) > numbers[i+1]:
            numbers[i] = increment(numbers[i])
            return " ".join(map(str, numbers))
        elif numbers[i] > decrement(numbers[i+1]):
            numbers[i+1] = decrement(numbers[i+1])
            return " ".join(map(str, numbers))

    return "impossible"


print(ans())