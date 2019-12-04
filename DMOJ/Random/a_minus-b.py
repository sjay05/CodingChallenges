n = input()
answers = []
for i in range(n):
    string = raw_input().split()
    answers.append(int(string[0])-int(string[1]))


for i in answers:
    print i
