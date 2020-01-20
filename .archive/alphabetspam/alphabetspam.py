k = input()
w = 0
l = 0
u = 0
s = 0
for i in range(len(k)):
    if k[i] == '_':
        w += 1
    elif k[i].islower():
        l += 1
    elif k[i].isupper():
        u += 1
    else:
        s += 1
print('{:.10f}'.format(float(w)/(w+l+u+s)))
print('{:.10f}'.format(float(l)/(w+l+u+s)))
print('{:.10f}'.format(float(u)/(w+l+u+s)))
print('{:.10f}'.format(float(s)/(w+l+u+s)))