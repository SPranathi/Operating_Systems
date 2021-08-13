/*
To write a program to stimulate the CPU scheduling algorithm Shortest job first(Non-Preemption)
*/

/*The Shortest Job First Scheduling Algorithm chooses the process that has the smallest next CPU burst. 
To calculate the average waiting time in the shortest job first algorithm the sorting of the
process based on their burst time in ascending order then calculate the waiting time of each process 
as the sum of the bursting times of all the process previous or before to that process.*/

/*
    Completion Time: Time at which process completes its execution.
    Turn Around Time: Time Difference between completion time and arrival time. 
    Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Time Difference between turn around time and burst time.
    Waiting Time = Turn Around Time – Burst Time
*/

#include<stdio.h>
int main(){
    int i,n,k,temp,bt[20],wt[20],tat[20],p[20];
    float wtavg,tatavg;
    printf("\nEnter the number of processes--");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter the Burst Time for Process %d--",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            if(bt[i]>bt[k]){
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
        }
    }
    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++)
        printf("\n\tp%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time--%.2f",wtavg/n);
    printf("\nAverage Turnaround Time--%.2f",tatavg/n);
}