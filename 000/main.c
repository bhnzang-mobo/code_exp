#include <stdio.h>
#include <stdlib.h>
int time[2][3];
int rest[3];
void read_time(){
	for(int i = 0 ; i < 2 ; i ++){
		scanf("%d:%d:%d",&time[i][0],&time[i][1],&time[i][2]);
	}
}
void day_off(){
	int day=0;
	for(int i = 0 ; i < 3 ; i ++){
		if(time[0][i]==time[1][i]){
			continue;
		}
		if(time[0][i]<time[1][i]){
			break;
		}
		else{
			day=1;
		}
	}
	if(day){
		time[1][0]+=24;
	};
}
void cal_time(){
	read_time();
	day_off();
	for(int i=2; i>=0; i--){
		rest[i]=time[1][i]-time[0][i];
	}
	for(int i=2; i>=1; i--){
		if(rest[i]<0){
			rest[i-1]-=1;
			rest[i]+=60;
		}
	}
}
int main(int argc, char *argv[]) {
	int num_testcase,num;
	scanf("%d",&num_testcase);
	for(int i = 0 ; i < num_testcase;i++){
		cal_time();
		printf("#%d ",i+1);
		for(int i = 0 ; i <3 ; i ++){
		if(rest[i]<10){
			printf("0%d",rest[i]);
		}
		else{
			printf("%d",rest[i]);
		}
		if(i!=2){
			printf(":");
		}
	}
	printf("\n");
	}
	return 0;
}
