from collections import defaultdict

#lines = input()
graph = {}
visited = defaultdict(int)
#completed = []


def add_edge(from_vertex, to_vertex):
    graph.setdefault(from_vertex, []).append(to_vertex)
    graph.setdefault(to_vertex, [])


# while lines > 0:
#     edge = [int(c) for c in raw_input().split(" ")]
#     add_edge(edge[0], edge[1])
#     lines -= 1

# for test input
add_edge(1, 2)
add_edge(2, 3)


def dfs(completed, v):
    if v in completed:
        print "cycle found"

    if not visited[v]:
        completed.append(v)
        visited[v] = 1
        for av in graph[v]:
            dfs(completed, av)
            print "Dfs next line."

    print "end of function."

    # #completed.append(v)
    # if not visited[v]:
    #     completed.append(v)
    #     for av in graph[v]:
    #         #if not visited[av]:
    #         visited[av] = 1
    #         dfs(completed, av)


start_vertex = graph.keys()[0]
dfs([], start_vertex)



