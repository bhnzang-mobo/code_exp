#include <stdio.h>
#include "Table.h"

int hash(Key key){
    return key%100;
}

int main (){
    Table mytable;
    tableinit(&mytable,hash);
    tableinsert(&mytable,157,"MOB");
    tableinsert(&mytable,257,"MOBO");
    printf("%s",tabledelete(&mytable,157));
    return 0;
}