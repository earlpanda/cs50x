import csv
from sys import argv
from cs50 import SQL

if len(argv) != 2:
    print("Usage: import.py characters.csv students.db")
    exit()

if len(argv) == 2:
    # create database
    open(f"students.db", "w").close()
    db = SQL("sqlite:///students.db")

    # create table
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

    # put name list into table
    with open(argv[1], "r") as file:
        namelist = csv.DictReader(file)
        # loop to insert name into table
        for row in namelist:
            fullname = []
            # split name
            fullname.append(row["name"].split())
            splitname = fullname[0]
            # check if fullname have middle name or not
            if len(splitname) == 3:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                           splitname[0], splitname[1], splitname[2], row["house"], row["birth"])
            if len(splitname) == 2:
                db.execute("INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)",
                           splitname[0], splitname[1], row["house"], row["birth"])

else:
    print("Error: ")
    exit()