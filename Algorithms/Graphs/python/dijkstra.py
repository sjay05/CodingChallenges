"""
Dijkstra Implemention w/ Priority Queue
"""
import Queue

graph = {}
distance = {}
processed = []
q = Queue.PriorityQueue()

def create_edge(f, t, w):
    if f in graph.keys():
        graph[f].append((t, w))
    else:
        graph[f] = [(t, w)]
    if t in graph.keys():
        graph[t].append((f, w))
    else:
        graph[t] = [(f, w)]
    if f not in distance.keys():
        distance[f] = float('inf')
    if t not in distance.keys():
        distance[t] = float('inf')

def dijkstra(node):
    distance[node] = 0
    q.put((0, node))
    while (not q.empty()):
        a = q.get()[1]
        if a in processed: continue
        for i in graph[a]:
            b, w = i[0], i[1]
            if distance[a]+w < distance[b]:
                distance[b] = distance[a]+w
                q.put((-distance[b], b))
    
        
create_edge(1, 5, 1)
create_edge(5, 4, 2)
create_edge(4, 3, 6)
create_edge(3, 2, 2)
create_edge(2, 1, 5)
create_edge(4, 1, 9)

dijkstra(1)
print distance
