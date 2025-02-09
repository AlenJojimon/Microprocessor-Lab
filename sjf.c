#include<stdio.h>
void main()
   {
    int limit,tot_wt=0,tot_tat=0,temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes :");
    scanf("%d",&limit);
    int P[limit],BT[limit],WT[limit],TAT[limit];
    printf("Enter the Processes and their corresponding Burst Time \n");
    for (int i=0;i<limit;i++)
       {
        scanf("%d",&P[i]);
        scanf("%d",&BT[i]);
       }
    for (int i =0 ; i<limit; i++){
        for (int j =i+1 ; j<limit; j++){
           if (BT[i] > BT[j]){
              temp = BT[i];
              BT[i] = BT[j];
              BT[j] = temp;
              
              temp = P[i];
              P[i] = P[j];
              P[j] = temp;
           }
        }
    }
    for (int i=0;i<limit;i++)
       {
        if (i==0)
           {
            WT[i]=0;
            TAT[i]=BT[i];
            tot_tat=TAT[i];
           }
        else
           {
            WT[i]=WT[i-1]+BT[i-1];
            tot_wt+=WT[i];
            
            TAT[i]=TAT[i-1]+BT[i];  
            tot_tat+=TAT[i];
           }
       }
    avg_wt=tot_wt/(float)limit;
    avg_tat=tot_tat/(float)limit;
    
    printf("\nGantt chart\n");
     for (int i =0 ; i<limit; i++){
        printf("|  P%d  ",P[i]);
     }
     printf("|\n");
     for (int i =0 ; i<limit; i++){
        printf("%d      ",WT[i]);
     }
     printf("%d\n\n",TAT[limit -1]);
    
    printf("Process   BT   WT   TAT\n");
    for (int i=0;i<limit;i++)
       {
        printf("  %d       %d    %d    %d\n",P[i],BT[i],WT[i],TAT[i]);
       }
    printf("Total waiting time = %d\n",tot_wt);
    printf("Total turn around time = %d\n\n",tot_tat);
    
    printf("Average WT = %f\n",avg_wt);
    printf("Average TAT = %f\n",avg_tat);
   }
