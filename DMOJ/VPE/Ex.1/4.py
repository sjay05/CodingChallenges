from Queue import PriorityQueue
from sys import stdin

input = stdin.readline

class Graph:
    def __init__(self, MAXN):
        self.MAXN = MAXN
        self.adj = {i: [] for i in range(MAXN)}

    def add_Edge(self, f, t, we):
        self.adj[f].append((t, we))
        self.adj[t].append((f, we))

    def getAdj(self, a):
        return self.adj[a]

    def SCC(self, src, dest):
        dist = {i: float('INF') for i in range(self.MAXN)}
        dist[src] = 0
        pq = PriorityQueue()
        pq.put((0, src))
        while not pq.empty():
            v = pq.get()[1]
            for u in self.adj[v]:
                n, weight = u[0], u[1]
                if dist[v] + weight < dist[n]:
                    dist[n] = dist[v] + weight
                    pq.put((dist[n], n))

        return dist[dest]

smallest = [float('inf')]

def tryAll(node, taskN, path):
    if path > smallest[0]:
        return

    if taskN == D:
        smallest[0] = path
        paths.append(path)
        return

    tryAll(tasks[taskN][0], taskN+1, path+g.SCC(node, tasks[taskN][1])+
           g.SCC(tasks[taskN][1], tasks[taskN][0]))
    tryAll(tasks[taskN][1], taskN+1, path+g.SCC(node, tasks[taskN][0])+
           g.SCC(tasks[taskN][0], tasks[taskN][1]))


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

    paths = []
    tryAll(1, 0, 0)
    paths = filter(lambda a: a != None, paths)
    print min(paths)