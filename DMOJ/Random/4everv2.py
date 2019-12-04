
spelling_dict = {1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven', 8: 'eight', 9: 'nine',
                 10: 'ten', 11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen', 15: 'fifteen',
                 16: 'sixteen', 17: 'seventeen', 18: 'eighteen', 19: 'nineteen', 20: 'twenty', 30: 'thirty',
                 40: 'forty', 50: 'fifty', 60: 'sixty', 70: 'seventy', 80: 'eighty', 90: 'ninety'}


def main_iterator(n, length, total):
    i = 0
    while 0 <= i < length:
        if n[i] != '0':
            if length - i == 10:  # billion
                total += len(spelling_dict[int(n[i])])
                total += len('billion')
                i += 1

            elif length - i == 9:  # hundred million
                total += parse_3(n[i:i + 3])
                total += len('million')
                i += 3

            elif length - i == 8:  # ten million
                total += parse_2(n[i:i + 2])
                total += len('million')
                i += 2

            elif length - i == 7:  # million
                total += len(spelling_dict[int(n[i])])
                total += len('million')
                i += 1

            elif length - i == 6:  # hundred thousand
                total += parse_3(n[i:i + 3])
                total += len('thousand')
                i += 3

            elif length - i == 5:  # ten thousand
                total += parse_2(n[i:i + 2])
                total += len('thousand')
                i += 2

            elif length - i == 4:  # thousand
                total += len(spelling_dict[int(n[i])])
                total += len('thousand')
                i += 1

            elif length - i == 3:  # hundred
                total += parse_3(n[i:i+3])
                break

            elif length - i == 2:  # tens
                total += parse_2(n[i:i+2])
                break

            elif length - i == 1:  # ones
                total += len(spelling_dict[int(n[i])])
                break

        else:
            i += 1

    return total


def parse_3(n):
    total = 0
    for i in range(len(n)):
        if n[i] != '0':
            if i == 0:
                total += len(spelling_dict[int(n[i])])
                total += len('hundred')

            elif i == 1:
                if int(n[i:]) in [11, 12, 13, 14, 15, 16, 17, 18, 19]:
                    total += len(spelling_dict[int(n[i:])])
                    break
                else:
                    total += len(spelling_dict[int(n[i]) * 10])

            elif i == 2:
                total += len(spelling_dict[int(n[i])])

    return total


def parse_2(n):
    total = 0
    if int(n) in [11, 12, 13, 14, 15, 16, 17, 18, 19]:
        total += len(spelling_dict[int(n)])
    else:
        total += len(spelling_dict[int(n[0]) * 10])
        if n[1] != '0':
            total += len(spelling_dict[int(n[1])])

    return total


if __name__ == '__main__':
    N = input()
    while True:
        if N == 4:
            break
        else:
            N = main_iterator(str(N), len(str(N)), 0)
            print N
