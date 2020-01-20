s = "{0} bottles of {2} on the wall, {0} bottles of {2}. \nTake one down, pass it around, {1} bottles of {2} on the wall."
ssingle = "{0} bottles of {2} on the wall, {0} bottles of {2}. \nTake one down, pass it around, {1} bottle of {2} on the wall."
slat = "{0} bottle of {2} on the wall, {0} bottle of {2}. \nTake it down, pass it around, no more bottles of {2}."

n = int(input())
name = input()
for i in range(n):
    k = n - i
    last = ""
    if k - 1 == 0:
        print(slat.format(k,k-1,name), end='')
    elif k - 1 == 1:
        print(ssingle.format(k,k-1,name))
        print()
    else:
        print(s.format(k,k-1,name))
        print()