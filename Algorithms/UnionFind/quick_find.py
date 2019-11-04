def QuickFindUF(N):
    # Set id of each object to itself
    for i in range(N):
        id.append(i+1)


def connected(p, q):
    # Check whether p and q are same component
    return id[p] == id[q]


def union(p, q):
    # change all entries with id[p] to id[q]
    pid = id[p-1]
    qid = id[q-1]
    for i in range(len(id)):
        if id[i] == pid:
            id[i] = qid


if __name__ == '__main__':
    id = []
    QuickFindUF(6)
    union(3, 4)
    print id
