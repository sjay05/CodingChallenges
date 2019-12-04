#  Mock CCC '18 Contest 1 J2 - A Substring Problem


S = raw_input()


def substring_eval():
    ans = True
    for i in range(len(S)):
        if ans:
            for j in range(1, len(S)-i):
                if palindrome_check(S[i:i+j+1]):
                    if len(S[i:i+j+1]) % 2 == 0:
                        ans = False
                        break
        else:
            break

    if ans:
        return "Odd"
    else:
        return "Even"


def palindrome_check(s):
    t = ""
    i = len(s)-1
    while i >= 0:
        t += s[i]
        i -= 1

    if t == s:
        return True
    else:
        return False


print substring_eval()