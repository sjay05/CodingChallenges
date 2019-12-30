a = input()

for i in range(a):
    n = raw_input()
    brackets = []

    x = ""
    right_count = 0
    left_count = 0
    for i in n:
        if i == ")" or i == "(":
            x += i
        if i == "(":
            right_count += 1
        if i == ")":
            left_count += 1
    
    if right_count == left_count:        
        brackets_pair = {")": "(", "}": "{", "]": "["}


        def bracket_sorter(b):
            if b in brackets_pair.values():
                brackets.append(b)
            elif len(brackets) and brackets_pair[b] != brackets.pop():
                return False
            return True


        for i in range(len(x)):
            if not bracket_sorter(x[i]):
                break

        if len(brackets) == 0:
            print "YES"
        else:
            print "NO"
    else:
        print "NO"



