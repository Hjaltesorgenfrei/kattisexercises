s = input()
p = input()

def answer():
    if s == p:
        return True
    if s == p.swapcase():
        return True
    for i in range(10):
        if s == p + str(i) or s == str(i) + p:
            return True 
    return False

if answer() == True:
    print("Yes")
else:
    print("No")