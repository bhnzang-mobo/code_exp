#include <stdio.h>
#include "In2Post.h"

int comp(char a, char b){
    int ak,bk;
    if(a=='+'||a=='-'){
        ak=0;
    }
    else{
        ak=1;
    }
    if(b=='+'||b=='-'){
        bk=0;
    }
    else{
        bk=1;
    }
    if(ak<bk){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){/*
    Stack stack;
    Stackinit(&stack);
    char eq[100];
    char ret[100];
    printf("Input equation : ");
    scanf("%s",eq);
    int i = 0;
    int j =0;
    char ch = eq[i];
    while(ch!='\0'){
        if(isdigit(ch)){
            ret[j++]=ch;
            ch=eq[++i];
        }
        else if(ch=='('){
            Push(&stack,ch);
            ch=eq[++i];
            continue;
        }
        else {
            if (ch == ')') {
                while (!isEmpty(&stack) && Peek(&stack) != '(') {
                    ret[j++] = Pop(&stack);
                }
                Pop(&stack);
                ch = eq[++i];
                continue;
            }
            while(!isEmpty(&stack)&&Peek(&stack)!='('&&!comp(Peek(&stack),ch)){
                ret[j++]=Pop(&stack);
            }
            Push(&stack, ch);
            ch = eq[++i];
        }
    }
    while(!isEmpty(&stack)){
        ret[j++]=Pop(&stack);
    }
    ret[j]='\0';
    printf("%s",ret);
    */
    char exp [200];
    scanf("%s",exp);
    In2Post(exp);
    printf("%s",exp);
    return 0;
}
