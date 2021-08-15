/*
Write a C program to simulate the CPU scheduling algorithm round-robin.
*/

/*This scheduling algorithm is designed especially for time sharing systems.
It is similar to FCFS scheduling, but preemption is added to switch between processes. 

To aim is to calculate the average waiting time.There will be a time slice,each process should be executed within that time-slice 
and if not it will go to the waiting state so first check whether the burst time is less than the time-slice.
If it is less than it assign the waiting time to the sum of the total times.
If it is greater than the burst-time then subtract the time slot from the actual burst time and 
increment it by time-slot and the loop continues until all the processes are completed.*/

/*
    Completion Time: Time at which process completes its execution.
    Turn Around Time: Time Difference between completion time and arrival time. 
    Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Time Difference between turn around time and burst time.
    Waiting Time = Turn Around Time – Burst Time
*/

/* NOTE: In this we have assumed arrival time as 0 */

#include<stdio.h>
int main(){
    int i,n,ts,t=0,bt[10],wt[10],tat[10],rem_bt[10];//t-current time
    float awt,atat;
    printf("ROUND ROBIN SCHEDULING\n");
    printf("Enter the number of Processes\n");
    scanf("%d",&n);
    printf("\nEnter the Timeslice\n");
    scanf("%d",&ts);
    for(i=1;i<=n;i++){
        printf("Enter the Burst Time for the process p%d:",i);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    while(1){
        int done=1;
        for(i=1;i<=n;i++){
            if(rem_bt[i]>0){
                done=0;
                if(rem_bt[i]>ts){
                    t=t+ts;
                    rem_bt[i]=rem_bt[i]-ts;
                }
                else{
                    t=t+rem_bt[i];
                    wt[i]=t-bt[i];
                    rem_bt[i]=0;
                }
            }
        }
        if(done==1)
            break;
    }
    printf("\nROUND ROBIN SCHEDULING\n");
    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i=1;i<=n;i++){
        tat[i]=bt[i]+wt[i];
        awt=awt+wt[i];
        atat+=tat[i];
        printf("\n%d\t%d\t%d\t%d",i,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time=%.2f",awt/n);
    printf("\nAverage Turnaround Time=%.2f",atat/n);                                                                                                                                                                                                            
}