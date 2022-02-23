R = int(input())
for r in range(R):
    N = int(input())
    M, K = input().split()
    M = int(M); K = int(K)
    ans = N // M * 2 + N // K
    print(ans)