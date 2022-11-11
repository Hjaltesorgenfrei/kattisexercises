n = int(input())
k = list(map(int, input().split()))
p = [k[0]]
prev = k[1]
for i in range(2, len(k)):
    if not (p[-1] == prev or prev == k[i] or p[-1] < prev < k[i] or p[-1] > prev > k[i]):
        p.append(prev)
    prev = k[i]

p.append(prev)

i = 1
best = 0
while i < len(p) - 1:
    best = max(best, min(p[i] - p[i - 1], p[i] - p[i + 1]))
    i += 1
    
print(best)