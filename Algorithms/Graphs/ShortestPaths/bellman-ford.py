# PYTHON 2.7 - BELLMAN-FORD ALGORITHM
# TIME COMPLEXITY: O(nm)

# Edges will be stored in (v1, v2, cost)
edges = []
distance = {}
predecessor = {}

# create a edge list with v1, v2, cost and
# append to distance and predecessor if not existent


def create_edge(v1, v2, c):# c = cost
    edges.append([v1, v2, c])
    if v1 not in distance.keys():
        distance[v1] = 1000
    if v1 not in predecessor.keys():
        predecessor[v1] = 0
    if v2 not in distance.keys():
        distance[v2] = 1000
    if v2 not in predecessor.keys():
        predecessor[v2] = 0


def bellman_ford(src):
    distance[src] = 0
# run a loop each time updating shortest path to each node
    for i in range(9):
        for edge in edges:
            a, b, w = edge
            # Pick exisiting distance and new distance
            distance[b] = min(distance[b], distance[a]+w)
            if distance[a]+w < distance[b]:
                predecessor[b] = a


# Test case #1 - Graph w/ negative & positive edge w
create_edge('A', 'B', 1)
create_edge('A', 'D', 2)
create_edge('B', 'C', 2)
create_edge('C', 'D', 2)
create_edge('C', 'E', 8)
create_edge('D', 'E', 3)


bellman_ford('A')
# print distance map, and reference to certain node to obtain shortes path
print distance
