import math
from cs50 import get_float

while True:
    n = get_float("Change: ")
    if n > 0:
        break
# to change the dollars into cents:
i = round(n * 100)
coin_amount = 0
# when over a quarter
while i >= 25:
    i -= 25
    coin_amount += 1
# when over a dime
while i >= 10:
    i -= 10
    coin_amount += 1
# when over a nickel
while i >= 5:
    i -= 5
    coin_amount += 1
# when over a penny
while i >= 1:
    i -= 1
    coin_amount += 1

print(coin_amount)