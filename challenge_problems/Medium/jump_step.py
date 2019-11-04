arr = [3, 2, 2, 0, 5, 6]


def jump_step(i, v):
    if i == len(arr) - 1:
        return True

    if arr[i] == 0:
        return False

    else:
        for x in range(v, 0, -1):
            if i+x > len(arr)-1:
                x = (len(arr)-1)-i
            func = jump_step(i+x, arr[i+x])
            if func:
                return True
            else:
                v -= 1
        return False


print jump_step(0, arr[0])
