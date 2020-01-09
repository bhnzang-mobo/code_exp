#include <stdio.h>
void merge_sort(int * arr, int low, int high){
    if(low<high){

        int left_btm= low;
        int tmp[high-low+1];
        int mid= (high+low)/2;
        int right_btm = mid+1;
        int i = 0;

        //recursive pattern - making smallest piece
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        //generalization - from bottom to top
        while(left_btm<=mid && right_btm<=high){
            tmp[i++]=(arr[left_btm]<arr[right_btm])?arr[left_btm++]:arr[right_btm++];
        }
        while(left_btm<=mid){
            tmp[i++]=arr[left_btm++];
        }
        while (right_btm<=high){
            tmp[i++]=arr[right_btm++];
        }

        for(int a = low; a<high+1 ; a++){
            arr[a]=tmp[a-low];
        }
    }
}
int main() {
    int arr[9]={1,2,3,8,8,7,5,43,41};
    merge_sort(arr,0,8);
    return 0;
}