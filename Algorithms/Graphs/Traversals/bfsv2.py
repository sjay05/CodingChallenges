from Queue import Queue

MAXN = 10 # MAX NODE

graph = {i: [] for i in range(MAXN)}
dist = {i: 0 for i in range(MAXN)}

def edge(a, b):
    graph[a].append(b)

def BreadthFirstSearch(src):
    q = Queue()
    dist[src] = 0
    q.put(src)
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not dist[v]:
                dist[v] = dist[u] + 1
            q.put(v)

# from, to
edge(1, 2)