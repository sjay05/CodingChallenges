from sys import stdin

input = stdin.readline

MAXB = int(input())
den = []
dict = {}
k = 0

def bankNotes(t, count):
    if t == 0:
        return count
    if t < 0:
        return False

    for c in den:
        if dict[c] > 0:
            dict[c] -= 1
            if t - c >= 0:
                v = bankNotes(t-c, count+1)
                if v:
                    return v


if __name__ == '__main__':
    den = input().split()
    for i in range(len(den)): den[i] = int(den[i])

    lft = input().split()
    for i in range(len(lft)): lft[i] = int(lft[i])
    for i in range(len(lft)):
        dict[den[i]] = lft[i]

    den.sort(reverse = True)
    k = int(input())

    print bankNotes(k, 0)