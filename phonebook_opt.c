#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findLastName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    assert(e->pNext && "malloc for e->Next error.");
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
