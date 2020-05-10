#include <stdio.h>

int main(){
    int min=2001;
    int bug;
    int j1,j2;
    for(int i = 0 ; i < 3; i ++){
        scanf("%d",&bug);
        if(bug<min) min=bug;
    }
    scanf("%d",&j1);
    scanf("%d",&j2);
    printf("%d",min+j1<min+j2 ? min+j1-50: min+j2-50 );
    return 0;
}