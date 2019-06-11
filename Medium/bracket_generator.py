max = 3


def bracket_generator(i, j, s):
    if j == max:
        s += (")" * i)
        print s
        return

    else:
        bracket_generator(i+1, j+1, s+"(")
        if i == 0:
            return
        else:
            bracket_generator(i-1, j, s+")")


bracket_generator(0, 0, "")
