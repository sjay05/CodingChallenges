# Graph Implementation w/ Dijkstra Algorithm (Uni-directional graph)

import Queue as Q


class Vertex:
    def __init__(self, id):
        self.id = id
        self.cost = 1000000
        self.visited = False
        self.prev = None

    def __hash__(self):
        return hash(self.id)

    def __eq__(self, other):
        return self.id == other.id

    def __str__(self):
        return str(self.id)

    def __cmp__(self, other):
        return cmp(self.cost, other.cost)


class Edge(object):
    # Constructor with edge (src) and edge (dest)
    def __init__(self, src, dest, cost):
        # Each edge has its own src, dest, and cost.
        self.src = src
        self.dest = dest
        self.cost = cost

    def __str__(self):
        return "(" + str(self.src) + "," + str(self.dest) + ")"


class Graph:
    # Create adj_list
    def __init__(self):
        self.adj_list = {}

    # Add_edge with src object, dest obj, and cost.
    def add_edge(self, src, dest, cost):
        # Create Edge object with src, dest vertex.
        e = Edge(src, dest, cost)
        # getting list of all edges associating with a vertex obj,
        # if there are none, then it returns empty [].
        l = self.adj_list.get(src, [])
        if len(l):  # rewritten ( len(l) >= 1 )
            l.append(e)
        else:  # create a new value for vertex.
            self.adj_list[src] = [e]

    """
    Following method implements Dijkstra Algorithm
    for finding shortest path between two vertices.
    """

    def find_shortest_path(self, src, dest):
        # output is generated from maintained linked list. 
        output = []
        src.cost = 0
        pq = Q.PriorityQueue()
        pq.put(src)

        while not pq.empty():
            v = pq.get()

            if v == dest:
                output.append(v.id)
                while v.prev:
                    output.append(v.prev.id)
                    v = v.prev
                return output

            v.visited = True

            for e in self.adj_list.get(v, []):
                if e.dest.visited:
                    continue
                cost_so_far = e.src.cost + e.cost
                if cost_so_far<e.dest.cost:
                    e.dest.cost = cost_so_far
                    e.dest.prev = e.src
                    pq.put(e.dest)

        if not len(output):
            print "Path not found"

        return output


g = Graph()

v1 = Vertex(1)
v2 = Vertex(2)
v3 = Vertex(3)
v4 = Vertex(4)

g.add_edge(v1, v2, 10)
g.add_edge(v1, v3, 20)
g.add_edge(v2, v4, 5)
g.add_edge(v3, v4, 7)

path = g.find_shortest_path(v1, v4)
print path
