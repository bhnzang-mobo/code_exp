#ifndef __SORT__
#define __SORT__
#include <stdio.h>
#include <malloc.h>
#include "queue.h"

typedef qdata data;
typedef int(*Comparitor)(data, data);//0 for left, 1 for right one is bigger
typedef int(*buck_idx)(data);
typedef struct __bucket{
    int numofradix;
    queue* bucket;
}Bucket;

void bubble_sort(data[], Comparitor comp);
void selection_sort(data[],Comparitor comp);
void insertion_sort(data[],Comparitor comp);

void heap_sort(data[],Comparitor comp);
void merge_sort(data[],int left,int right,Comparitor comp);
void quick_sort(data[],int left,int right,Comparitor comp);
void radix_sort(data[],int,int,Bucket);
#endif