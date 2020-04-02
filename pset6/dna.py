import csv
from sys import argv

if len(argv) != 3:
    print("Usage: dna.py sequences.txt databases.csv")
    exit()

# open and read the dna databases get from argv[2]
with open(argv[2], 'r') as text:
    dna_read = text.read()

# open the dna databases and store it in a list
with open(argv[1], 'r') as file:
    reader = csv.reader(file, delimiter=',')
    databases = list(reader)
    # get the STR key
    sequences = (databases[0][1:])

# create a dictionary to store STRs and dna sequences about to count
dict = {}
# stores STRs in dict
for item in sequences:
    dict[item] = dict.get(item, 0) + 1

# iterate throught the dna sequence
counter = 0
max_counter = 0

for key in dict:
    length = len(key)
    for i in range(len(dna_read)):
        while counter > 0:
            counter -= 1

        # in specific dna sequence, if found the key STRs, start counting the number of repeating
        if dna_read[i: i + length] == key:
            while dna_read[i - length: i] == dna_read[i: i + length]:
                counter += 1
                i += length

            # find the max number of repeating key STRs in specific dna sequence
            if counter > max_counter:
                max_counter = counter
                # I struggled on this a long time,
                # it turns out that I shout put counter and max_counter back to 0 after finish counting one STR
            count = 0

    # stores it in dict
    dict[key] += max_counter
    max_counter = 0

# open databases again to check whose dna sequence
with open(argv[1]) as dnafile:
    people_dna = csv.DictReader(dnafile, delimiter=',')

    for person in people_dna:
        # counter for match
        match = 0
        for item in dict:
            if dict[item] == int(person[item]):
                match += 1
        if match == len(dict):
            print(person['name'])
            exit()
    print("No match")
    exit()