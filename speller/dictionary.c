#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int no_words = 0;
const unsigned int N = 26;
node *table[N];

bool check(const char *word)
{
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        printf("was not able to open dictionary\n");
        return false;
    }
    char buffer[45];
    while (fscanf(dict_file, "%s", buffer) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            return false;
        }
        strcpy(new_word->word, buffer);
        int hash_value = hash(buffer); // Declare and assign hash_value here
        new_word->next = table[hash_value];
        table[hash_value] = new_word;
        no_words++;
    }
    fclose(dict_file);
    return true;
}

unsigned int size(void)
{
    return no_words;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
