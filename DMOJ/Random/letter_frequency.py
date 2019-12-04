import sys
S = sys.stdin.readline().replace(" ", "")
#N = int(sys.stdin.readline())

psa = []
dict = {}
for i in range(len(S)):
    if dict.get(S[i], 0) != 0:
        dict[S[i]] = dict[S[i]] + 1
        psa.append(dict)
    else:
        dict[S[i]] = 1
        psa.append(dict)

print psa


# for i in range(N):
#      l = sys.stdin.readline().split()
#      a = int(l[0])
#      b = int(l[1])
#      char = l[2]

