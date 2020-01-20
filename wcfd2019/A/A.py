import random
c = ['A', 'B', 'C']

for i in range(1000):
    choice = random.choice(c)
    print(choice)
    ans = input()
    cop = ['A', 'B', 'C']
    if ans[2] == '1':
        print(ans[0])
    else:
        cop.remove(ans[0])
        cop.remove(choice)
        print(cop[0])
    input()