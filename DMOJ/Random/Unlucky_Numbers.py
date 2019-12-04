import sys

n = input()
psa = []
for i in range(n):
    if i == 0:
        psa.append(int(sys.stdin.readline()))
    else:
        psa.append(int(sys.stdin.readline())+psa[i-1])


del n

def find_sum(a, b):
    if a == b:
        return psa[b] - psa[b-1]
    elif a == 0:
        return psa[b]
    else:
        return psa[b] - psa[a-1]


q = input()
answers = []
for i in range(q):
    l = sys.stdin.readline().split()
    a = int(l[0])
    b = int(l[1])
    del l
    print find_sum(a, b)
