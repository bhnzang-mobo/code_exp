#include <stdio.h>
short ret[10010]={0,};

void d(int num){
    if(ret[num]==1 || num >=10001){
        return;
    }
    ret[num]=1;
    num=num+num%10+(num%100)/10+(num%1000)/100+num/1000;
    d(num);
}

int main(){
    int num=1;
    while(num<10000){
        int num2=num+num%10+(num%100)/10+(num%1000)/100+num/1000;
        d(num2);
        num++;
    }
    num=1;
    while(num<10001){
        if(ret[num]==0) printf("%d\n",num);
        num++;
    }
}