#ifndef __TABLE__
#define __TABLE__
#include "DLlist.h"
#define TABLE_NUM 100

typedef int (*GetHash)(Key);

typedef struct __table{
    DList table[TABLE_NUM];
    GetHash hs;
}Table;

void tableinit(Table* table, GetHash func);
void tableinsert(Table* table,Key key, Value value);
Value tabledelete(Table* table,Key key);
Value tablesearch(Table* table,Key key);
#endif