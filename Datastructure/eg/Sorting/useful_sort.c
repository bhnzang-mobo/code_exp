#include "sort.h"
#include "heap.h"

void heap_sort(data arr[],Comparitor comp){
    int arr_len=20;
    heap hp;
    heapinit(&hp,comp);
    for(int i = 0 ; i < arr_len ; i ++){
        heapinsert(&hp,arr[i]);
    }
    for(int i = 0 ; i < arr_len ; i ++){
        arr[i]=heapDelete(&hp);
    }
}

void merge_sort(data arr[],int left,int right,Comparitor comp){
    if(left<right){
        //DIVIDE
        int mid=(left+right)/2;
        merge_sort(arr, left, mid,comp);
        merge_sort(arr, mid+1, right,comp);

        //CONQURE
        int lhand = left;
        int rhand = mid+1;
        data *tmparr=(data*)malloc(sizeof(data)*(right-left+1));
        int i = 0 ;


        while(lhand<=mid && rhand<=right){
            if(comp(arr[lhand],arr[rhand])){
                tmparr[i++]=arr[lhand++];
            }
            else{
                tmparr[i++]=arr[rhand++];
            }
        }
        while(lhand<=mid && i < right-left + 1){
            tmparr[i++]=arr[lhand++];
        }
        while(rhand<=right && i < right-left + 1){
            tmparr[i++]=arr[rhand++];
        }

        //MERGE
        for(int a = 0 ; a < right-left+1 ; a++){//from arr[left] to arr[right] 
            arr[a+left]=tmparr[a]; 
        }
        free(tmparr);
    }

}

void quick_sort(data arr[],int left,int right,Comparitor comp){
    if(left<right){
        int pivot = left;
        int low = left+1;
        int high = right;
        while(low<high){
            while(comp(arr[low],arr[pivot])&&low<=right){//low must not bigger than right
                low++;
            }
            while(comp(arr[pivot],arr[high])&&left+1<=high){//high must not smaller than left+1
                high--;
            }
            if(low<high){
                data tmp = arr[low];
                arr[low]=arr[high];
                arr[high]=tmp;
            }
        }
        //SWAP
        data tmp = arr[low-1];
        arr[low-1]=arr[pivot];
        arr[pivot]=tmp;
        //
        quick_sort(arr,left,low-2,comp);// modified from quick_sort(arr,left,low-1,comp);
        quick_sort(arr,low,right,comp);
    }
}

void radix_sort(data arr[],int num,int maxlen,Bucket buck){
    int i = 0;
    int oper=1;
    buck.bucket=(queue*)malloc(sizeof(queue)*buck.numofradix);
    //be careful on iteration : ..;j < num;.. (X) 
    for(int j = 0 ; j < buck.numofradix ; j ++){
        queueinit(&buck.bucket[j]);
    }    //arr, num of data,max len of data
    int (*buckidx)(data a ,data b);
    buckidx=buck.buckindex;
    
    while(++i <= maxlen){
        for(int j = 0 ; j < num ; j ++){
            int what = buckidx(arr[j],oper);
            enqueue(&buck.bucket[what],arr[j]);
        }
        
        int tmp=0; //be careful on iteration : ..;j < num;.. (X)
        for(int j = 0 ; j < buck.numofradix ; j ++){      
            while(!isQEmpty(&buck.bucket[j])){
                arr[tmp++] = dequeue(&buck.bucket[j]);
            }
        }
        oper*=10;
    }
}