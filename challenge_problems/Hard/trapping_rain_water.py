# INPUT:
heights = [3, 0, 2, 1, 0, 7]


def trap_rain_water(height):
    count = 0
    for i in range(1, len(height)-1):
        left_max = max(height[:i])
        right_max = max(height[i+1:])
        if left_max < right_max:
            main_max = left_max
        else:
            main_max = right_max

        if main_max > height[i]:
            count += (main_max - height[i])

    return count


print trap_rain_water(heights)
