# CONVERT A INTEGER NUMBER TO NUMBER OF LETTERS:
'''
i.e.

Convert 1023 to Letters:

    1023: "One thousand and twenty three' -> No. of letters =
                                            "one" = 3
                                            "thousand" = 8
                                            "and" = 3
                                            "twenty" = 6
                                            "three" = 5

    Therefore 1023 (as in number of letters) = 3 + 8 + 3 + 6 + 5
                                             = 25


Given any number, write a program that can find the number of letters that integer holds:
'''

single_int = {'1': 3, '2': 3, '3': 5, '4': 4, '5': 4, '6': 3, '7': 5, '8': 5, '9': 4}

tens_dict = {'0': 3, '1': 6, '2': 6, '3': 8, '4': 8, '5': 7, '6': 7, '7': 9, '8': 8, '9': 8}

secondary_tens = {'2': 6, '3': 6, '4': 5, '5': 5, '6': 5, '7': 7, '8': 6, '9': 6}

base_10 = {'3': 7, '4': 8}


def calc(value):
    count = 0
    i = 0
    b10 = len(value)
    if len(value) >= 3:
        if value[len(value)-2] != '0' or value[len(value)-1] != '0':
            count += 3
    while i < len(value):
        if len(value) == 1:
            count += single_int.get(value[0])
            break
        if i == len(value)-2:
            if value[i] == "0":
                if value[i+1] == "0":
                    break
                else:
                    count += single_int.get(value[i + 1])
                    break
            if value[i] == "1":
                count += tens_dict.get(value[i+1])
                break
            elif value[i+1] == "0":
                count += secondary_tens.get(value[i])
                break
            else:
                count += secondary_tens.get(value[i])
                count += single_int.get(value[i + 1])
                break

        else:
            if i == len(value)-1 and value[i] == "0":
                break
            elif i == len(value)-1 and value[i] != "0":
                count += single_int.get(value[i])
                b10 -= 1
                i += 1
                break
            elif value[i+1] == "0":
                count += single_int.get(value[i])
                count += base_10.get(str(b10))
                i += 2
                b10 -= 1
            else:
                count += single_int.get(value[i])
                count += base_10.get(str(b10))
                b10 -= 1
                i += 1

    return count


print calc(str("1000"))
