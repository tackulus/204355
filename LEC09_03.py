K = int(input())
S = list(map(int, input().split()))

def combs(a):
    if len(a) == 0:
        return [[]]
    cs = []
    for c in combs(a[1:]):
        cs += [c, c+[a[0]]]
    return cs

ans, entire = [], combs(S)
for c in entire:
    if len(c) == 6: ans.append(sorted(c))

ans = sorted(ans)
for c in ans:
    for i in range(6):
        print(c[i], end=' ')
    print()