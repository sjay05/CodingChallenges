a = sorted([(45, 45), (30, 15), (25, 35), (50, 30), (40, 25), (10, 10), (20, 20)])


def nesting_dolls(l):
    first_count = False
    start_var = 0
    i = start_var
    j = 1
    count = len(l)
    while i < len(l):
        while j < len(l)-1:
            if l[i][0] < l[j][0] and l[i][1] < l[j][1]:
                count -= 1
                i = j
                j += 1
            else:
                if not first_count:
                    start_var = j
                    j += 1
                    first_count = True
                else:
                    j += 1


    print count


nesting_dolls(a)