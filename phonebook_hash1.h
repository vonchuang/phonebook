#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_HASH_TABLE_SIZE 466553
#define HASH 1

typedef struct __DETAIL_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __DETAIL_ENTRY *pNext;
} detailEntry;

typedef struct __PHONE_BOOK_ENTRY{
    char lastName[MAX_LAST_NAME_SIZE];
    detailEntry *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *hashTable[MAX_HASH_TABLE_SIZE];

entry *findLastName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
unsigned int DJBHash(char *str);

#endif
