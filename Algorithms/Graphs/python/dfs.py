graph = {}
visited = []


def create_edge(a, b):
    if a in graph.keys():
        graph[a].append(b)
    else:
        graph[a] = [b]

    if b not in graph.keys():
        graph[b] = []


def dfs(g, node):
    if node not in visited:
        visited.append(node)
        for n in g[node]:
            dfs(g, n)


create_edge('1', '2')
create_edge('1', '4')
create_edge('2', '3')
create_edge('2', '5')
create_edge('3', '5')

dfs(graph, '1')
print(visited)
