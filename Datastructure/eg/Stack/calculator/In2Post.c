#include "In2Post.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include "stack.h"

int pred(char a){
    switch (a)
    {
    case '+': case '-':
        return 2;
    case '*': case '/':
        return 3;
    
    case '(':
        return 1;
    
    default :
        return 0;
    }

}

void In2Post(char exp[]){
    Stack stack;
    Stackinit(&stack);

    int len = strlen(exp);
    char* ret = (char*)malloc(len*sizeof(char)+1);
    int idx_exp=0;
    int idx_ret=0;
    char oper = exp[idx_exp];
    while(idx_exp<=len){
        if(isdigit(oper)){
            ret[idx_ret++]=oper;
            oper=exp[++idx_exp];
            continue;
        }
        else{
            if(isEmpty(&stack)){
                Push(&stack,oper);
                oper=exp[++idx_exp];
                continue;
            }
            else{
                if(oper==')'){
                    while(Peek(&stack)!='('){
                        ret[idx_ret++]=Pop(&stack);
                    }
                    Pop(&stack);
                    oper=exp[++idx_exp];
                    continue;
                }
                
                //Operator occur : (, +, -, *, /
                while(!isEmpty(&stack)&&pred(Peek(&stack))>=pred(oper)){
                    ret[idx_ret++]=Pop(&stack);
                }
                Push(&stack,oper);
                oper=exp[++idx_exp];
                continue;
            }
        }
    }
    ret[idx_ret]='\0';
    strcpy(exp,ret);
}