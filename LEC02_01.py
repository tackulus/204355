from math import floor, sqrt

n = int(input())
COUNT, MAX = 1, n

while n != 1:
    if n % 2: n = n ** 3
    n = floor(sqrt(n))
    MAX = int(max([n, MAX]))
    COUNT += 1

print(MAX, end=' ')
print(COUNT)