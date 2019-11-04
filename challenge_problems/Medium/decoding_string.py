
string = "ab3[c2[de2[z]]f]gh4[gh]"


def find_parts(s):
    left_bracket_ind = -1
    right_bracket_ind = -1

    if '[' in s:
        left_bracket_ind = s.index('[')
        i = left_bracket_ind + 1
        bracket_count = 1
        while i < len(s) and right_bracket_ind == -1:
            if s[i] == '[':
                bracket_count += 1
            elif s[i] == ']':
                bracket_count -= 1
                if bracket_count == 0:
                    # found matching ]
                    right_bracket_ind = i

            i += 1

    if left_bracket_ind != -1 and right_bracket_ind != -1:
        return s[:left_bracket_ind-1], \
               s[left_bracket_ind-1:left_bracket_ind], \
               s[left_bracket_ind+1:right_bracket_ind], \
               s[right_bracket_ind+1:]
    else:
        return s, -1, '', ''


def decode_string(s):
    if '[' not in s:
        return s

    prefix, k, t, suffix = find_parts(s)
    return prefix + int(k) * decode_string(t) + decode_string(suffix)


print decode_string(string)