x = raw_input()
y = raw_input()

count = 0
for i in range(len(x)):
    if x[i] != y[i]:
        count += 1

if count == 1:
    print "LARRY IS SAVED!"
else:
    print "LARRY IS DEAD!"