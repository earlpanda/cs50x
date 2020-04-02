import csv
from sys import argv
from cs50 import SQL

if len(argv) != 2:
    print("Usage: roster.py characters.csv students.db")
    exit()

if len(argv) == 2:
    open("students.db", "r").close()
    db = SQL("sqlite:///students.db")

    student_house = argv[1]
    list = db.execute(
        "SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first ASC", student_house)
    for row in list:
        print(row["first"], end=' ')
        if row["middle"] != None:
            print(row["middle"], end=' ')
        print(row["last"], end=', ')
        print(f"born", row["birth"])

else:
    print("Error: ")
    exit()