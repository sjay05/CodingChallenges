# INPUT
comb = "23"
phone_num = {"2": "abc", "3": "def", "4": "ghi",
             "5": "jkl", "6": "mno", "7": "pqrs",
             "8": "tuv", "9": "wxyz" }

# PROBLEM:
'''
URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/  
Given a string containing digits from 2-9 inclusive, return all possible 
letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.
'''

in_def = []
for i in range(len(comb)):
    in_def.append(phone_num.get(comb[i]))


def merge(a, b):
    if len(a) > len(b) or len(a) == len(b):
        if len(a) == 1:
            list = []
            for i in range(len(a[0])):
                temp = ""
                for j in range(len(b[0])):
                    temp = a[0][i] + b[0][j]
                    list.append(temp)
            return list

        else:
            list2 = []
            for i in range(len(a)):
                temp2 = ""
                for j in range(len(b[0])):
                    temp2 = a[i] + b[0][j]
                    list2.append(temp2)
            return list2

    else:
        if len(b) == 1:
            list = []
            for i in range(len(b[0])):
                # temp = ""
                for j in range(len(a[0])):
                    temp = a[0][j] + b[0][i]
                    list.append(temp)
            return list

        else:
            list2 = []
            for i in range(len(b)):
                # temp2 = ""
                for j in range(len(a[0])):
                    temp2 = a[0][j] + b[i]
                    list2.append(temp2)
            return list2


def rec_comb(value):
    if len(value) == 1:
        return value

    left = rec_comb(value[:1])
    right = rec_comb(value[1:])
    return merge(left, right)


print rec_comb(in_def)