from Queue import PriorityQueue

MAXN = 10 # MAX NODE

adj = {i: [] for i in range(MAXN)}
dist = {i: float('INF') for i in range(MAXN)}

def edge(f, t, w):
    adj[f].append((t, w))

def Dijkstra(node):
    pq = vPriorityQueue()
    dist[node] = 0
    pq.put((0, node))
    while not pq.empty():
        v = pq.get()[1]
        for u in adj[v]:
            node, weight = u[0], u[1]
            if dist[v] + weight < dist[node]:
                dist[node] = dist[v] + weight
                pq.put((dist[node], node))


# from, to, weight
edge(1, 5, 1)
