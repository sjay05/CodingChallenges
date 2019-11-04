arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]


def jump_step(i, v, p):
    if i == len(arr) - 1:
        return 1

    if arr[i] == 0:
        return 0
    else:
        for x in range(v, 0, -1):
            if i+x > len(arr)-1:
                x = (len(arr)-1)-i
            can_jump = jump_step(i+x, arr[i+x], p)
            if can_jump:
                p.append(v)
                if i == 0:
                    return can_jump
                else:
                    return 1 + can_jump
            else:
                v -= 1
        return 0

path = []
print jump_step(0, arr[0], path), path[::-1]