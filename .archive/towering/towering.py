ints = [int(n) for n in input().split()]
nums = sorted(ints[:6], reverse=True)
box1 = ints[6]
box2 = ints[7]

def findAnswer():
    for i in nums:
        for j in nums:
            if j == i:
                continue
            for k in nums:
                if k == i:
                    continue
                if k == j:
                    continue
                if i + j + k == box1:
                    maybe = [x for x in nums if x not in [i, j, k]]
                    if sum(maybe) == box2:
                        return [i, j, k], maybe

box1ans, box2ans = findAnswer()
ans = ''
for v in box1ans:
    ans += str(v) + " "

for v in box2ans:
    ans += str(v) + " "
print(ans[:-1])