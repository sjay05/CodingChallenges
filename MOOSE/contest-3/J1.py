line1 = raw_input().split()
x = int(line1[0])
y = int(line1[1])
degree = input()

for i in range(degree / 90) :
    if x > 0:
        if y > 0:
            x,y = -y,x
        else:
            x,y = abs(y),x
    else:
        if y > 0:
            x,y = -y,x
        else:
            x,y = abs(y),x

print x,y



