import Queue
graph = {}

N, M = map(int, raw_input().split())
edges = []
for i in range(M):
    f,t = map(int, raw_input().split())
    edges.append([f,t])

def create_edge(f, t):
    if f not in graph.keys():
        graph[f] = [t]
    else:
        graph[f].append(t)
    if t not in graph.keys():
        graph[t] = []

for i in edges:
    f = i[0]
    t = i[1]
    create_edge(f, t)

def bfs(node):
    q = Queue.Queue()
    distance = {}
    for i in range(1, M+1):
        distance[i] = 0
    visited = []
    visited.append(node)
    q.put(node)
    while (not q.empty()):
        s = q.get()
        for n in graph[s]:
            if n in visited:
                continue
            q.put(n)
            distance[n] = distance[s] + 1
    
    if distance[N] != 0:
        print "YES"
    else:
        print "NO"

for edge in edges:
    f = edge[0]
    t = edge[1]
    graph[f].remove(t)
    bfs(1)
    graph[f].append(t)
