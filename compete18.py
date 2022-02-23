import math

def D(a,b):
    return math.sqrt(math.pow(a[0]-b[0],2)+math.pow(a[1]-b[1],2))

N = int(input())
start = list(map(int,input().split(' ')))
stop  = list(map(int, input().split(' ')))
other = []
for i in range(N-2):
    x, y = list(map(int,input().split(' ')))
    other.append([x, y])

rocks = [start] + other + [stop]
    
AdjList = [[1 for j in range(N)] for i in range(N)]
for i in range(N): AdjList[i][i] = 0

Distance = [float('inf') for i in range(N)]
Distance[0] = 0

queue = [[0,0]]
while len(queue) > 0:
    (dist, loc), queue = queue[0], queue[1:]
    for aoc in range(N):
        if AdjList[loc][aoc]:
            old = Distance[aoc]
            new = max([Distance[loc], D(rocks[loc], rocks[aoc])])
            if new < old:
                Distance[aoc] = new
                queue.append([new, aoc])

print("{:.3f}".format(round(Distance[-1],3)))
