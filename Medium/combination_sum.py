def combination_sum(candidates, target):
    r_sum(candidates, target, 0, [])


def r_sum(candidates, target, index, sub_list):
    if target == 0:
        print sub_list
        return
    if target < 0:
        return
    for i in range(index, len(candidates)):
        sub_list.append(candidates[i])
        r_sum(candidates, target - candidates[i], i, sub_list)
        sub_list.remove(sub_list[len(sub_list) - 1])


combination_sum([list], int)




