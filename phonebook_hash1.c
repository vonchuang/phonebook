#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "phonebook_hash.h"

unsigned int BJDHash( char *str){
    unsigned int hash = 5381;

    while (*str)
        hash = ((hash << 5) + hash) + (*str++);

    return (hash % MAX_HASH_TABLE_SIZE);
}

entry *findLastName(char lastName[], entry *pHead)
{
    unsigned int index = BJDHash(lastName); 
    pHead = hashTable[index];
    
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    unsigned int index = BJDHash(lastName); 
    /* allocate memory for the new entry and put lastName */
    e = (entry *) malloc(sizeof(entry));
    assert(e && "malloc for e->Next error.");
    e->pNext = hashTable[index];
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    hashTable[index] = e;

    return e;
}
