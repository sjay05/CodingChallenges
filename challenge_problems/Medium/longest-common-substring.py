string_x = 'ABAB'
string_y = 'BABA'
matrix = []
for i in range(len(string_y)):
    matrix.append([0 for x in range(len(string_x))])


def lcs(string_x, string_y, matrix):
    max = 1
    max_j = 0
    for i in range(0, len(string_y)):
        for j in range(0, len(string_x)):
            if string_y[i] == string_x[j]:
                if i > 0 and j > 0:
                    if matrix[i-1][j-1] != 0:
                        matrix[i][j] = matrix[i-1][j-1] + 1
                        max = matrix[i-1][j-1] + 1
                        max_j = j
                    else:
                        matrix[i][j] = 1
                else:
                    matrix[i][j] = 1

    lcs = ''
    for x in range(0, max):
        lcs += string_x[max_j-x]

    return max, lcs


print lcs(string_x, string_y, matrix)