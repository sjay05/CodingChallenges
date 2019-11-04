o_board = [
    ['A', 'B', 'C', 'D'],
    ['B', 'F', 'C', 'S'],
    ['C', 'D', 'E', 'E']

]


word = "ABCCED"

board = []

a = []
for x in range(len(o_board[0])+2):
    a.append('0')
board.append(a)
for i in range(len(o_board)):
    temp_list = [0]
    for j in o_board[i]:
        temp_list.append(j)

    temp_list.append(0)
    board.append(temp_list)

b = []
for y in range(len(o_board[0])+2):
    b.append('0')
board.append(b)


def search_word(i, j, word):
    if len(word) == 1:
        raise Exception("Found")
    else:
        unfiltered_neighbour = [[i-1, j], [i+1, j], [i, j+1], [i, j-1]]
        filtered_neighbour = [o for o in unfiltered_neighbour if board[o[0]][o[1]] == word[1]]

        case = 0
        while case < len(filtered_neighbour):
            search_word(filtered_neighbour[case][0], filtered_neighbour[case][1], word[1:])
            case += 1
        return False


for i in range(1, len(board)):
    for j in range(1, len(board)):
        if board[i][j] == word[0]:
            try:
                search_word(i, j, word)
            except:
                result = True

if result:
    print "true"
else:
    print "false"
