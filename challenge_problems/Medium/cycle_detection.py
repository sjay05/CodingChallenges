class Vertex:

    # constructor function
    def __init__(self, key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self,nbr,weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id)

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self,nbr):
        return self.connectedTo[nbr]


class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0

    def addVertex(self,key):
        self.numVertices = self.numVertices + 1
        # create new vertex object/instance
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex

    def getVertex(self,n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vertList

    def addEdge(self, srcVertId, destVertId, edgeCost=0):
        if srcVertId not in self.vertList:
            nv = self.addVertex(srcVertId)
        if destVertId not in self.vertList:
            nv = self.addVertex(destVertId)
        self.vertList[srcVertId].addNeighbor(self.vertList[destVertId], edgeCost)

    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())

    def has_cycle(self):
        unvisited = [i for i in self.getVertices()]
        visiting = []
        visited = []
        while len(unvisited) > 0:
            vertex = unvisited[0]
            if self.dfs(vertex, unvisited, visiting, visited):
                return True

        return False

    def dfs(self, vertex, unvisited, visiting, visited):
        visiting.append(vertex)
        if len(unvisited) > 1:
            unvisited.remove(unvisited[0])
        v_obj = self.vertList.get(vertex)
        if v_obj:
            for neighbor in v_obj.getConnections():
                nId = neighbor.getId()
                if nId in visited:
                    continue

                if nId in visiting:
                    return True

                if self.dfs(nId, unvisited, visiting, visited):
                    return True

        if vertex in unvisited:
            unvisited.remove(vertex)
        visited.append(vertex)
        visiting.remove(vertex)
        return False


g = Graph()

g.addVertex(1)
g.addVertex(2)
g.addVertex(4)
g.addVertex(5)
g.addVertex(6)

g.addEdge(1, 2)
g.addEdge(4, 1)
g.addEdge(4, 5)
g.addEdge(5, 6)




if g.has_cycle():
    print "Has cycle"
else:
    print "No cycle"
