from cs50 import get_string
import math
import string

while True:
    card_number = get_string("Enter your card number: ")
    if card_number.isnumeric():
        break

cardnum = list(map(int, card_number))
sum = 0
length = len(cardnum)
parity = length % 2
for i in range(length):
    digit = cardnum[i]
    if i % 2 == parity:
        digit *= 2
    if digit > 9:
        digit -= 9
    sum += digit

if length < 13 or length > 16:
    print("INVALID")
    exit(0)

elif sum % 10 != 0:
    print("INVALID")
    exit(0)

elif cardnum[0] == 5 and cardnum[1] <= 5 and length == 16:
    print("MASTERCARD")
    exit(0)

elif cardnum[0] == 3 and (cardnum[1] == 4 or cardnum[1] == 7) and length == 15:
    print("AMEX")
    exit(0)

elif cardnum[0] == 4 and length == 16:
    print("VISA")
    exit(0)

else:
    print("INVALID")
    exit(0)