n = int(input())

def fibonacci(n):
    if n == 0: return 0
    elif n == 1: return 1

    f0, f1 = 0, 1
    for i in range(n-1):
        ans = f0 + f1
        f0, f1 = f1, ans

    return ans

print(fibonacci(n)) 