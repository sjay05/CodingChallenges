import math
x = []

for i in range(3):
    temp_inp = raw_input().split()
    x.append([int(i) for i in temp_inp])

tri1 = x[0][0] * x[0][1]
tri2 = x[1][0] * x[1][1]
tri3 = x[2][0] * x[2][1]

a = str(math.sqrt(tri1+tri2+tri3))

index_of_dot = a.find('.')

if a[index_of_dot+1] == "0":
    num = int(float(a))
    if num in x[0] or num in x[1] or num in x[2]:
        if num in x[0]:
            if num-x[0][1] in x[1] and num-x[0][1] in x[2]:
                print "YES"
            elif num in x[1] and num in x[2]:
                print "YES"
            else:
                print "NO"
        elif num in x[1]:
            if num in x[2] and num in x[3]:
                print "YES"
            elif num-x[1][1] in x[2] and num-x[1][1] in x[0]:
                print "YES"
            else:
                print "NO"
        elif num in x[2]:
            if num in x[0] and num in x[1]:
                print "YES"
            elif num-x[2][1] in x[1] and num-x[2][1] in x[0]:
                print "YES"
            else:
                print "NO"

        else:
            print "NO"
    else:
        print "NO"


else:
    print "NO"


