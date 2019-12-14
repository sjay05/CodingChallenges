n = input()
lines = []
for i in range(n):
    inp = raw_input()
    lines.append(inp)

rule1 = True
rule2 = True
rule3 = True

#rule1 check
for line in lines:
    if line.find("mine") == -1:
        rule1 = False
        break
    if line.find("craft") == -1:
        rule1 = False
        break

if rule1:
    # rule2 check
    for line in lines:
        if line.find("mine") > line.find("craft"):
            rule2 = False
            break
    if rule2:
        # rule3 check
        non = 0
        pro = 0
        for line in lines:
            line = line.split()
            for i in line:
                if i == "mine":
                    pro += 1
                elif i == "craft":
                    pro += 1
                else:
                    non += 1
                # if i != "mine" or i != "craft":
                #     non += 1
                # else:
                #     pro += 1

        if pro < non:
            print "cri"
        else:
            print "PROFIT"

    else:
        print "cri"
else:
    print "cri"