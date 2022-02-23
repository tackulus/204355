N = int(input())
queue = []
node = []
for n in range(N):
    pair = input().split(' ')
    queue.append(pair)
    node += pair
# queue = sorted(queue)
node = sorted(node)

dsa = [0 for i in range(len(node))]
for pair in queue:
    a, b = node.index(pair[0]), node.index(pair[1])
    dsa[a] += 1
    if b < len(node)-1: dsa[b+1] -= 1

psa = [sum(dsa[:i]) for i in range(1,len(node))]
most = max(psa)
at = psa.index(most)
date = node[at]
print(date)    