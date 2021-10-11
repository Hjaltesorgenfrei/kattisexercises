n = int(input())
l = set(int(x) for x in input().split())
k = set(int(x) for x in input().split())
print(*l.difference(k))
