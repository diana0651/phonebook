#include <stdlib.h>
#include <string.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    unsigned int hashPos;
    slot_unit *slot;

    hashPos = hashFunction(stringToInt(lastname));
    slot = hashTable[hashPos];

    while (slot!=NULL) {
        if (strcasecmp(lastname, slot->data->lastName) == 0)
            return slot->data;
        slot = slot->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e->detail = NULL;
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    unsigned int hashPos;
    slot_unit *newSlot;

    hashPos = hashFunction(stringToInt(lastName));

    newSlot = (slot_unit *) malloc(sizeof(slot_unit));
    newSlot->pNext = hashTable[hashPos];
    newSlot->data = e;
    hashTable[hashPos] = newSlot;
    return e;
}

unsigned int stringToInt(char *key)
{
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}

unsigned int hashFunction(unsigned int key)
{
    return key & ((1<<TWO_POWER_NUM) - 1);
}