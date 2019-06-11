def swap(word, i, j):
    l = [c for c in word]
    l[j], l[i] = l[i], l[j]
    return "".join(l)


def perm(word, start, end):
    if start == end:
        print word
        return

    for i in range(start, end):
        word = swap(word, i, start)
        perm(word, start+1, end)
        word = swap(word, i, start)

perm("ABCDEFGHI", 0, 9)
