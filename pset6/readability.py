from cs50 import get_string
import math

# get user's input
text = get_string("Text: ")

# count number of letters, words and sentences
length = len(text)
letters = 0
words = 1
sentences = 0

for i in range(length):
    if text[i].isalpha():
        letters += 1
    elif text[i].isspace():
        words += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

# build the Coleman-Liau index based on formula
L = 100 / words * letters
S = 100 / words * sentences
index = (0.0588 * L) - (0.296 * S) - 15.8

# check the index number and give the output
if round(index) < 1:
    print("Before Grade 1")
    exit(0)
elif round(index) > 16:
    print("Grade 16+")
    exit(0)
else:
    print(f"Grade {round(index)}")
    exit(0)