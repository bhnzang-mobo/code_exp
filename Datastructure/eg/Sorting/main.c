#include <stdlib.h>
#include "sort.h"

int comp(data a, data b){
    if(a>=b) return 1;
    else return 0;
} 
int main(){
    data arr[20];
    for(int i = 0 ; i < 20 ; i ++){
        arr[i]=rand()%1000;
    }
    Bucket buck;
    buck.numofradix=10;
    radix_sort(arr,20,3,buck);
    
    //quick_sort(arr,0,19,comp);
    for(int i = 0 ; i < 20 ; i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}