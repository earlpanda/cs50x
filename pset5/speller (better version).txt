//Thanks u/Fuelled_By_Coffee for the advices! 

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 6000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//counter for words
int word_count = 0;

// Hash table
node *table[HASHTABLE_SIZE] = {NULL};

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //hash word to find which bucket it would be put in
    unsigned long bucket = hash(word);
    //keep track the head of linked list
    node *cursor = table[bucket];
    //Compare word in linked list with word in dictionary
    while (cursor != NULL)
    {
        //if word matches word in dictionary
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        //else, move cursor to the next linked list
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", dictionary);
        return 1;
    }

    char word[LENGTH + 1];
    //Read strings from dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        //create temporary node, insert to the bucket
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            fclose(file);
            return 1;
        }
        //copy word into this node
        strcpy(tmp -> word, word);
        //hash word
        int bucket = hash(word);
        if (table[bucket] == NULL)
        {
            table[bucket] = tmp;
            tmp -> next = NULL;
        }
        else
        {
            tmp -> next = table[bucket];
            table[bucket] = tmp;
        }
        word_count++;
    }
    //close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //word_count have kept track the number of words that added to the dictionary
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //create a loop to repeatedly free the memory
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            //create temporary node
            node *temp = cursor;
            cursor = cursor -> next;
            //free the memory which temp pointing at
            free(temp);
        }
    }
    return true;
}

// Hashes word to a number, hash function djb2 created by Dan Bernstein

unsigned long hash(const char *needs_hashing)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *needs_hashing++))
    {
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 +c */
    }
    return hash % HASHTABLE_SIZE;
}