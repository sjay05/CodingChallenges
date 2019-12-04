def check_array(a):
    if len(a) > 2:
        for i in range(len(a)-2):
            if a[i] == a[i+1]:
                return False

        return True

    else:
        if a[0] == a[1]:
            return False
        return True

def latin_square(a):
    ref = True
    for i in range(len(a)):
        v_array = [a[o][i] for o in range(len(a))]
        if not check_array(v_array):
            ref = False
            break

    if not ref:
        return False
    else:
        return True

def reduced(a1, a2):
    if sorted(a1) == a1:
        if sorted(a2) == a2:
            return True
    else:
        return False

if __name__ == '__main__':
    N = input()
    array = []
    exception = False
    for i in range(N):
        inp = raw_input()
        sub_array = []
        for i in inp:
            sub_array.append(i)
        sub_array = [ord(i) for i in sub_array]
        if not check_array(sub_array):
            exception = True
            break
        array.append(sub_array)

    if exception:
        print "No"
    elif latin_square(array):
        if reduced(array[0], [array[i][0] for i in range(len(array))]):
            print "Reduced"
        else:
            print "Latin"
    else:
        print "No"

