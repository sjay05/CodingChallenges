import math
inp = []

for i in range(3):
    temp_inp = raw_input().split()
    inp.append([int(i) for i in temp_inp])

tri1 = inp[0][0] * inp[0][1]
tri2 = inp[1][0] * inp[1][1]
tri3 = inp[2][0] * inp[2][1]

x = str(math.sqrt(tri1+tri2+tri3))

index_of_dot = x.find('.')

if x[index_of_dot+1] == "0":
    print "YES"
else:
    print "NO"