/*
To write a program to stimulate the CPU scheduling priority algorithm 
*/

/*Priority scheduling is a non-preemptive algorithm. 
To calculate the average waiting time in the priority algorithm,sort the burst times according to their priorities and then calculate the average waiting time of the processes. 
The waiting time of each process is obtained by summing up the burst times of all the previous processes.*/

/*
    Completion Time: Time at which process completes its execution.
    Turn Around Time: Time Difference between completion time and arrival time. 
    Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Time Difference between turn around time and burst time.
    Waiting Time = Turn Around Time – Burst Time
*/

#include<stdio.h>
int main(){
    int i,n,k,temp,bt[20],wt[20],tat[20],p[20],pri[20];
    float wtavg,tatavg;
    printf("\nEnter the number of processes--");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter the Burst Time & Priority for Process %d--",i);
        scanf("%d %d",&bt[i],&pri[i]);
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            if(pri[i]>pri[k]){
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=pri[i];
                pri[i]=pri[k];
                pri[k]=temp;
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
    printf("\n\tPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++)
        printf("\n\tp%d\t%d\t%d\t%d\t%d",p[i],pri[i],bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time--%.2f",wtavg/n);
    printf("\nAverage Turnaround Time--%.2f",tatavg/n);
}