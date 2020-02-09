# Bfs - Adjacency List
import Queue
q = Queue.Queue()
graph = {}
visited = []
distance = {}


def create_edge(a, b):
    if a in graph.keys():
        graph[a].append(b)
    else:
        graph[a] = [b]

    if b not in graph.keys():
        graph[b] = []


create_edge('1', '2')
create_edge('1', '4')
create_edge('1', '3')
create_edge('2', '5')
create_edge('2', '6')
create_edge('4', '7')
create_edge('4', '8')
create_edge('5', '9')
create_edge('5', '10')
create_edge('7', '11')
create_edge('7', '12')


def bfs(g, node):
    visited.append(node)
    q.put(node)
    while (not q.empty()):
        s = q.get()
        print(s)
        for n in graph[s]:
            if n in visited:
                continue
            q.put(n)


bfs(graph, '1')
