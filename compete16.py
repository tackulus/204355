x = int(input())
y = int(input())

maze = [[0 for j in range(10)] for i in range(10)]
for i in range(10):
    line = input().split(' ')
    for j in range(10):
        maze[i][j] = int(line[j])

def enloc(i,j): return 10 * i + j
def deloc(num): return [num//10,num%10]

AdjList = [[0 for j in range(100)] for i in range(100)]
for i in range(10):
    for j in range(10):
        if not maze[i][j]: continue
        if i != 9: 
            if maze[i+1][j]: 
                AdjList[enloc(i,j)][enloc(i+1,j)] = 1
                AdjList[enloc(i+1,j)][enloc(i,j)] = 1
        if j != 9: 
            if maze[i][j+1]: 
                AdjList[enloc(i,j)][enloc(i,j+1)] = 1
                AdjList[enloc(i,j+1)][enloc(i,j)] = 1

if maze[0][0] == 0: print(-1)
else:
    maze = [[float('inf') for j in range(10)] for i in range(10)]
    maze[0][0] = 0

    queue = [[0,0]]
    while len(queue) > 0:
        (dist, loc), queue = queue[0], queue[1:]
        i, j = deloc(loc)
        if dist > maze[i][j]: continue
        for aoc in range(100):
            if AdjList[loc][aoc]:
                u, v = deloc(aoc)
                old = maze[u][v]
                new = maze[i][j] + 1
                if new < old:
                    maze[u][v] = new
                    queue.append([new, aoc])
    if maze[x][y] == float('inf') : print(-1)
    else: print(maze[x][y])