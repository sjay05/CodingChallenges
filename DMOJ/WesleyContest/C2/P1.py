days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
x = raw_input()
index = days.index(x)
if index == len(days)-1:
    print days[0]
else:
    print days[index+1]
