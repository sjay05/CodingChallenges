max = 3
output = []

def bracket_generator(i, j, s):
    if j == max:
        s += (")" * i)
        output.append(s)
        return

    else:
        bracket_generator(i+1, j+1, s+"(")
        if i == 0:
            return
        else:
            bracket_generator(i-1, j, s+")")


bracket_generator(0, 0, "")
print output
