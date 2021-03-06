#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./smaz-master/smaz.c"
#include "phonebook_smaz.h"


entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;

        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    memset(e->lastName,sizeof(lastName),'\0');
    //compress string
    smaz_compress(lastName,strlen(lastName),e->lastName,sizeof(lastName));
    e->pNext = NULL;

    return e;
}