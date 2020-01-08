
def lcs(x, y, i, j, str):
    if i < 0 or j < 0:
        return 0, str

    elif storage[i][j] != -1:
        return storage[i][j]

    elif x[i] == y[j]:
        c, s = lcs(x, y, i-1, j-1, str)
        s += x[i]
        #print c, s
        return 1 + c, s

    else:
        left, ls = lcs(x, y, i-1, j, str)
        right, rs = lcs(x, y, i, j-1, str)
        fs = rs
        if len(ls) > len(rs):
            fs = ls
        v = max(left, right)
        storage[i][j] = v, fs
        return v, fs


a = 'ABCBDAB'
b = 'BDCABA'

storage = []

for i in range(len(a)):
    temp_list = []
    for j in range(len(b)):
        temp_list.append(-1)
    storage.append(temp_list)

length, sa = lcs(a, b, len(a)-1, len(b)-1, '')
print length, sa