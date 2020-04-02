from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n < 9 and n > 0:
        break

# nested loop to create double pyramid
for i in range(n):
    j = n - i - 2
    while j >= 0:
        print(" ", end="")
        j -= 1
    k = 0
    while k <= i:
        print("#", end="")
        k += 1
    print("  ", end="")
    m = 0
    while m <= i:
        print("#", end="")
        m += 1
    print()