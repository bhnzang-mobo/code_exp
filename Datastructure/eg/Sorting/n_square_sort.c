#include "sort.h"

void bubble_sort(int a[],Comparitor comp){
    int arr_len =20;
    while(arr_len--)
    for(int i = 0 ; i < arr_len ; i ++){
        int  tmp = a[i];
        if(!comp(a[i],a[i+1])){
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }
}

void selection_sort(int arr [],Comparitor comp){
    int arr_len = 20;
    for(int i = 0 ; i < arr_len ; i ++){
        int min =i;
        int tmp=arr[i];
        for(int j = i+1 ; j < arr_len ; j ++){
            if(comp(arr[j],arr[min])){//selection of minimum
                min=j;
            }
        }
        arr[i]=arr[min];//swap
        arr[min]=tmp;
    }
}


void insertion_sort(int arr[], Comparitor comp){
    int arr_len=20;
    int idx= 1;
    while(idx<arr_len){
        int idx2 = idx; 
        data data = arr[idx];
        while(idx2--){
            if(comp(data,arr[idx2])){//comp idx with left one, idx2
                arr[idx2+1]=arr[idx2];//shift idx2 to right
            }
            else{
                break;//idx2 is smaller than idx
            }
        }
        arr[idx2+1]=data; //then, idx2+1 is the place where the idx should be.
        idx++;//move to the next one
    }
}