from sys import stdin
input = stdin.readline

adj = {1:[2], 2:[3], 3:[1]}
visited = []

def cycleD(cs, n):
    if n in cs:
        print "Cycle found."
        return
    elif n in visited:
        return
    elif adj[n]:
        cs.append(n)
        visited.append(n)
        for i in adj[n]:
            cycleD(cs, i)

cycleD([], 1)

"""
graph = {1: [2], 2: [3], 3: [1]}
visited = {}


def cycle_detection(cycle_stack, node):
    neighbors = graph[node]
    if node in cycle_stack:
        print "Cycle is found."
        return
    elif visited[node] == 1:
        return
    elif neighbors:
        cycle_stack.append(node)
        visited[node] = 1
        for i in neighbors:
            cycle_detection(cycle_stack, i)


for i in graph.keys():
    visited[i] = 0

for i in graph.keys():
    cycle_detection([], i)
"""