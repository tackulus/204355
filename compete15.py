import math
K, N = list(map(int, input().split(' ')))
base = math.ceil(K / 2)
head = str(int(math.pow(10, base-1)) + N - 1)
other = K - base
print(head+head[:other][::-1])
