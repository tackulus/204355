M = int(input())
N = int(input())

AdjList = [[0 for j in range(M+1)] for i in range(M+1)]
for n in range(N):
    x, y, d = list(map(int, input().split(' ')))
    AdjList[x][y] = d
    AdjList[y][x] = d

Distance = [float('inf') for i in range(M+1)]
Distance[0] = 0

queue = [[0,0]]
while len(queue) > 0:
    (dist, loc), queue = queue[0], queue[1:]
    if dist > Distance[loc]: continue
    for aoc in range(M+1):
        if AdjList[loc][aoc]:
            old = Distance[aoc]
            new = Distance[loc] + AdjList[loc][aoc]
            if new < old:
                Distance[aoc] = new
                queue.append([new, aoc])

Distance = Distance[1:]
while len(Distance):
    if Distance[-1] != float('inf'):
        print(len(Distance), Distance[-1])
        break
    Distance.pop()
if len(Distance) == 0: print("0 0")