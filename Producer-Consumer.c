/*To Write a C program to simulate producer-consumer problem using semaphores.*/ 

/*Producer consumer problem is a synchronization problem.There is a fixed size buffer where the producer produces items 
and that is consumed by a consumer process.One solution to the producer-consumer  problem  uses  shared   memory.
To allow producer and consumer processes to run concurrently,there must be available a buffer of items that can be filled by the producer 
and emptied by the  consumer.This buffer will reside in a region of memory that is shared by the producer and consumer  processes.
The producer and consumer must be synchronized,so that the consumer does not try to consume an item that has not yet been produced.*/

#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch (n)
        {
        case 1:if((mutex==1)&&(empty!=0))
                producer();
               else
                printf("Buffer is full");
            break;
        case 2:if((mutex==1)&&(full!=0))
                consumer();
                else
                    printf("Buffer is empty!!");
                break;
        case 3:exit(0);
            break;
        }
    }
    return 0;
}
int wait(int s){
    return (--s);
}
int signal(int s){
    return (++s);
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}