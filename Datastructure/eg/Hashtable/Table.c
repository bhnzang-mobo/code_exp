#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void tableinit(Table* table, GetHash func){
    table->hs=func;
    for (int i = 0 ; i < TABLE_NUM ; i ++){
        Dinit(&(table->table[i]));
    }
}
void tableinsert(Table* table,Key key, Value value){
    DList* slot =&(table->table[table->hs(key)]);
    __slot data;
    data.key=key;
    data.value=value;
    Dinsert(slot,data);
}

Value tabledelete(Table* table,Key key){
    DList* slot = &(table->table[table->hs(key)]);
    DData data;
    if(DFirst(slot,&data)){
        while(data.key!=key && DNext(slot,&data))
        return DRemove(slot).value;
    }
}
Value tablesearch(Table* table,Key key){
    DList* slot = &(table->table[table->hs(key)]);
    DData data;
    if(DFirst(slot,&data)){
        while (data.key!=key&&DNext(slot,&data))
        return data.value;
        
    }
}