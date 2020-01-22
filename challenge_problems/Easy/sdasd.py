flowerbed = [0, 0, 0, 0, 0]
n = input()

def cpf():
  i = 0
  while i < len(flowerbed):
    if flowerbed[i] == 1:
      i += 2
    elif flowerbed[i] == 0:
      if i > 0:
        if i < len(flowerbed)-1:
          if flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
            n -= 1
        elif i == len(flowerbed)-1:
          if flowerbed[i-1] == 0:
            n -= 1
      if i == 0:
        if flowerbed[i+1] == 0:
          n -= 1 
      i += 1
    else:
      i += 1 
  
  if n == 0:
    print True
  else:
    print False 

cpf()