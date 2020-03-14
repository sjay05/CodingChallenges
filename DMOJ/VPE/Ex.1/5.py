from Queue import PriorityQueue
from sys import stdin

input = stdin.readline

class Graph:
    def __init__(self, MAXN):
        self.MAXN = MAXN
        self.mat = [[0] * MAXN] * MAXN

    def add_Edge(self, f, t, we):
        self.mat[f][t] = we
        self.mat[t][f] = we

    def floyd(self):
        dist = [[0] * self.MAXN] * self.MAXN
        for i in range(1, self.MAXN):
            for j in range(1, self.MAXN):
                if i == j:
                    dist[i][j] = 0
                elif self.mat[i][j] != 0:
                    dist[i][j] = self.mat[i][j]
                else:
                    dist[i][j] = float('inf')

        for k in range(1, self.MAXN):
            for i in range(1, self.MAXN):
                for j in range(1, self.MAXN):
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

        return dist

smallest = [float('inf')]

def getdist(a, b):
    return distance[a][b]

def tryAll(node, taskN, path):
    # if path > smallest[0]:
    #     return

    if taskN == D:
        #smallest[0] = path
        paths.append(path)
        return

    tryAll(tasks[taskN][0], taskN+1, path+getdist(node, tasks[taskN][1])+
           getdist(tasks[taskN][1], tasks[taskN][0]))
    tryAll(tasks[taskN][1], taskN+1, path+getdist(node, tasks[taskN][0])+
           getdist(tasks[taskN][0], tasks[taskN][1]))


if __name__ == '__main__':
    N, D = map(int, input().split())
    g = Graph(N+1)
    for _ in range(N-1):
        a, b, w = map(int, input().split())
        g.add_Edge(a, b, w)

    tasks = []
    for _ in range(D):
        a, b = map(int, input().split())
        tasks.append([a, b])

    distance = g.floyd()
    paths = []
    tryAll(1, 0, 0)
    paths = filter(lambda a: a != None, paths)
    print min(paths)
