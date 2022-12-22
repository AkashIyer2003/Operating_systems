#include<stdio.h>

void Wait_time(int bt[],int num,int wt[]){
        wt[0] = 0;
        for(int i = 1; i < num; i++){
                wt[i] = wt[i-1] + bt[i-1];
        }
}

void Turn_time(int bt[],int num,int wt[],int tt[]){
        for(int i = 0; i < num; i++){
                tt[i] = wt[i] + bt[i];
        }
}

void FCFS(int bt[],int num){
	int twt;
	int ttt;
	int Avgwt = 0;
	int wt[num];
	Wait_time(bt,num,wt);
	int tt[num];
	Turn_time(bt,num,wt,tt);
	for(int i=0;i < num;i++){
		printf("Process %d has burst_time : %d    wait_time : %d   turn_around_time : %d\n",i,bt[i],wt[i],tt[i]);
		twt = wt[0] + wt[1] + wt[2] + wt[3] + wt[4];
		ttt += tt[i];
	}
	Avgwt = (float)twt/(float)num;
	int Avgtt = (float)ttt/(float)num;
	printf("Avg Wait_time = %d and Avg Turn_around_time = %d",Avgwt,Avgtt);
}

int main(){
        int bt[5] = {4,2,6,1,2};
        FCFS(bt,5);
}
