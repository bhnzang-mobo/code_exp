#ifndef __SORT__
#define __SORT__
#include <stdio.h>
typedef int data;
typedef int(*Comparitor)(data, data);//0 for left, 1 for right one is bigger

void bubble_sort(data[], Comparitor comp);
void selection_sort(data[],Comparitor comp);
void insertion_sort(data[],Comparitor comp);

void heap_sort(data[],Comparitor comp);
void merge_sort(data[],int left,int right,Comparitor comp);
void quick_sort(data[],int left,int right,Comparitor comp);
#endif