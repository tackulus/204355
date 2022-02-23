line = input().split()
M = int(line[0]) # C
K = int(line[1]) # O
U = int(line[2]) # V
A = int(line[3]) # I
T = int(line[4]) # D
W = list(map(int, input().split()))
W = sorted(W)

def gpu(x): return U + (x // 1000) * A
def lpu(n): return (n // 2) * T 
def state(q,j):
    P_sum = 0
    for i in range(q,j): P_sum += W[i]
    gain = gpu(P_sum) * P_sum
    loss = 5000 + lpu(j-q) * P_sum
    return gain - loss

S = [[0 for k in range(K+1)] for j in range(M+1)]
for j in range(1,M-K+1): S[j][0] = -float('inf')

# Iterative Step
for k in range(1,K+1):
    for j in range(k,k+M-K+1):
        Q = [S[q][k-1] + state(q,j) for q in range(k-1,j)]
        S[j][k] = max(Q)

Ans = S[M][K]
if Ans > 0: print(int(Ans))
else: print(0)