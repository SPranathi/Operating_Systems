/*
To write a c program to simulate the CPU scheduling algorithm  First Come  First Serve (FCFS)
*/

/*The  First  Come  First  Served  (FCFS)  Scheduling  Algorithm  is  the  simplest  one. 
In  this algorithm the set of ready processes is managed as FIFO (first-in-first-out) Queue.
The processesare serviced by the CPU until completion in order of their entering in the FIFO queue.
A process once allocated the CPU keeps it until releasing the CPU either by terminating or requesting  I/O. 
For  example,  interrupted  process  is  allowed  to  continue  running  after  interrupt handling is done with. 

To calculate the average waiting time using the FCFS algorithm first the waiting time  of the first process is kept zero and 
the waiting time of the second process is the burst time of the first process and 
the waiting time of the third process is the sum of the burst times of the first and the second process and so on.
After calculating all the waiting times the average waiting time is calculated as the average of all the waiting times.
FCFS mainly says first come first serve the algorithm which came first will be served first.*/

/*
    Completion Time: Time at which process completes its execution.
    Turn Around Time: Time Difference between completion time and arrival time. 
    Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Time Difference between turn around time and burst time.
    Waiting Time = Turn Around Time – Burst Time
*/

#include<stdio.h>
int main(){
    int i,n,bt[10],wt[10],tat[10];//n-processes,bt-burst time,wt-waiting time,tat-turnaround time
    float wtavg,tatavg;
    printf("Enter the number of processes---");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time for process %d:",i);
        scanf("%d",&bt[i]);
    }
    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg=wtavg+wt[i];
        tatavg+=tat[i];
    }
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("\n\tp%d\t%d\t%d\t%d",i,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time is---%.2f",wtavg/n);
    printf("\nAverage turnaround time is---%.2f",tatavg/n);
}