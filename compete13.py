import math

L = int(input())
for l in range(L):
    F, P, K = input().split(' ')
    F = int(F); P = int(P); K = float(K)
    if P >= F:
        print(0)
        continue
    N = math.ceil(math.log(F/P, 1+K/100))
    print(N)