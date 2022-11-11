n = int(input())
l = f"""{n * 45} ml gin
{n * 30} ml fresh lemon juice
{n * 10} ml simple syrup
{n * 1 } slice{'' if n == 1 else 's'} of lemon"""
print(l)