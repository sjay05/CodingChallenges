a = int(input())
b = int(input())

squares = []
cubes = []

for i in range(int(a**(1.0/3)), int(b**(1.0/2))+1):
    if i <= int(b**(1.0/3)):
        cubes.append(i**3)
    if i >= int(a**(1.0/2)):
        squares.append(i**2)


list1 = set(squares)
list2 = set(cubes)

if a == b:
    if a**(1.0/2) == round(a**(1.0/2)) and round(a**(1.0/3))**3 == a:
        print 1
else:
    print len(list1.intersection(list2))