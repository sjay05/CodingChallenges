import sys
N = int(sys.stdin.readline())
values = sys.stdin.readline().split()
values = sorted([int(i) for i in values])
print values[N-1] - values[0]

