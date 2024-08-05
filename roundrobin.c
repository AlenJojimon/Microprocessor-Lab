#include<stdio.h>
void main(){
int lim,tq,time=0,completed=0,tot_wt=0,tot_tat=0;
float avg_wt,avg_tat;
printf("Enter the no. of processes:");
scanf("%d",&lim);
int pro[lim],bt[lim],wt[lim],rem[lim],tat[lim];
printf("Enter the time quantum:");
scanf("%d",&tq);
printf("Enter the burst time of processes:");
for(int i=0;i<lim;i++){
	pro[i]=i+1;
	scanf("%d",&bt[i]);
	rem[i]=bt[i];
	}
int ar[50],k=1;
ar[0]=0;
printf("GANTT CHART\n|");
while(completed<lim){
	for(int i=0;i<lim;i++){
		if(rem[i]>0){
			if(rem[i]>tq){
				printf("P%d |",pro[i]);
				time+=tq;
				rem[i]-=tq;
				}
			else{
				printf("P%d |",pro[i]);
				time+=rem[i];
				rem[i]=0;
				wt[i]=time-bt[i];
				completed++;
				tat[i]=time;
				}
			ar[k]=time;
			k++;
			}
			}}printf("\n");
for(int j=0;j<k;j++){
printf("%d   ",ar[j]);
}
printf("\n\n");
for(int i=0;i<lim;i++){
tot_wt+=wt[i];
tot_tat+=tat[i];
}
	avg_wt=tot_wt/(float)lim;
    avg_tat=tot_tat/(float)lim;
    printf("Process   BT   WT   TAT\n");
    for (int i=0;i<lim;i++)
       {
        printf("  %d       %d    %d    %d\n",pro[i],bt[i],wt[i],tat[i]);
       }
    printf("\nTotal waiting time = %d\n",tot_wt);
    printf("Total turn around time = %d\n\n",tot_tat);
    
    printf("Average WT = %f\n",avg_wt);
    printf("Average TAT = %f\n",avg_tat);
   }
