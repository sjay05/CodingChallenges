num = 123456789
m = 0
while num != 0:
  m = m * 10 + (num % 10)
  num = num / 10
print m