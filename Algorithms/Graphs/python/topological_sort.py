graph = {5: [11], 7: [11, 8], 3: [8, 10], 11: [2, 9, 10], 8: [9], 2: [], 9: [], 10: []}
topological_stack = []
visited = {}

for i in graph.keys():
    visited[i] = 0


def topological_sort(node):
    neighbours = graph[node]
    if not neighbours:
        topological_stack.append(node)
        visited[node] = 1
        return

    for i in neighbours:
        if visited[i] != 1:
            topological_sort(i)

    topological_stack.append(node)
    visited[node] = 1


def boundary_nodes(g):
    l1 = set(item for sublist in g.values() for item in sublist)
    l2 = g.keys()
    b_nodes = l1.symmetric_difference(l2)
    return b_nodes


start_nodes = boundary_nodes(graph)

for i in start_nodes:
    topological_sort(i)

print topological_stack
