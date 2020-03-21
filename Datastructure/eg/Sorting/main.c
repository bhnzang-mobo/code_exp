#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comp(data a, data b){
    if(a>=b) return 0;
    else return 1;
}
int main(){
    data arr[2000];
    for(int i = 0 ; i < 10 ; i ++){
        arr[i]=rand()%50;
    }
    quick_sort(arr,0,9,comp);
    for(int i = 0 ; i < 10 ; i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}