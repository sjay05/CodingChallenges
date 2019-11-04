def coin_change(sum, coins, map):
    minimum = sum
    if sum == 0:
        return 0

    if sum in map.keys():
        return int(map[sum])

    else:
        poss = [x for x in coins if x == sum]
        for i in [c for c in coins if c <= sum]:
            if len(poss) != 0:
                num = 1 + coin_change(sum-poss[0], coins, map)
            else:
                num = 1 + coin_change(sum-i, coins, map)

            if num < minimum:
                minimum = num

    map[sum] = minimum
    return minimum


print coin_change(6, [1, 2, 3], {})
