import Queue as Q
pq = Q.PriorityQueue()

input_1 = raw_input().split()
N = input_1[0]
M = input_1[1]

arr = []
for i in range(N):
    sub = raw_input().split()
    sub = [int(i) for i in sub]
    arr.append(sub)

def shortest(i, j, s_found, s_found, shortest):
    if i == M-1 and j == N-1:
        if shortest == 0:
            shortest = s_found
