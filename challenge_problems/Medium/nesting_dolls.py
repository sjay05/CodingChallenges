a = [(45, 45), (30, 15), (25, 35), (50, 30), (40, 25), (10, 10), (20, 20)]
#a = [(2, 1), (1, 0)]

l = sorted(a)


def nesting_dolls(l, count):
    rem = 0
    storage = []
    while len(storage) <= len(l)-1:
        index = rem
        only_once = True
        for i in range(index+1, len(l)):
            if i not in storage:
                if l[index][0] < l[i][0] and l[index][1] < l[i][1]:
                    count -= 1
                    index = i
                    if index == 0:
                        storage.append(i)
                        storage.append(index)
                    else:
                        storage.append(i)

                elif only_once:
                    rem = i
                    only_once = False

    print count


nesting_dolls(l, len(l))





