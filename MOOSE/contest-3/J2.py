n = input()
dict = {}

for i in range(n):
    line = raw_input().split()
    sum = 0
    for i in range(1, len(line)):
        sum += int(line[i])
    dict[line[0]] = sum


dict["temp"] = 0
top = "temp"
next = "temp"

set = True

for key in dict.keys():
    if dict[key] > dict[top]:
        top = key

for key in dict.keys():
    if key != top:
        if dict[key] > dict[next]:
            next = key



lexico = sorted([top, next])
if "temp" not in lexico:
    print lexico[0] + " " + str(dict[lexico[0]])
    print lexico[1] + " " + str(dict[lexico[1]])




