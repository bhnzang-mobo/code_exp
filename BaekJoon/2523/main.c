#include <stdio.h>

int main(){
    int count =1;
    int num;
    int C=1;
    scanf("%d",&num);
    while(count){
        for(int i = 0 ; i < count ;i++){
            printf("*");
        }
        printf("\n");
        if(count==num) C=-1;
        count+=C;
    }
}