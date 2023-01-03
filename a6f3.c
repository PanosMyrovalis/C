#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 10

typedef int QueueElementType;


typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);


int main()
{
QueueType Queue;
QueueElementType AnItem;
int i;

CreateQ(&Queue);

printf("---a--- \n");
for(i=0; i<QueueLimit; i++)
{
     AddQ(&Queue,i);
}
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d \n", Queue.Front, Queue.Rear, Queue.count);

printf("---b--- \n");
AddQ(&Queue,30);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d \n", Queue.Front, Queue.Rear, Queue.count);

printf("---c--- \n");
RemoveQ(&Queue, &AnItem);
TraverseQ(Queue);
printf("Removed item=%d Front=%d Rear=%d Count=%d \n",AnItem, Queue.Front, Queue.Rear, Queue.count);

printf("---d--- \n");
AddQ(&Queue,25);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d \n", Queue.Front, Queue.Rear, Queue.count);

printf("---e--- \n");
AddQ(&Queue,100);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d \n", Queue.Front, Queue.Rear, Queue.count);


printf("---f--- \n");

while(!EmptyQ(Queue))
{
   RemoveQ(&Queue, &AnItem);
   TraverseQ(Queue);
   printf("Removed item=%d Front=%d Rear=%d Count=%d \n",AnItem, Queue.Front, Queue.Rear, Queue.count);

}










return 0;
}



void CreateQ(QueueType *Queue)

{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->count = 0;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.count == 0);
}

boolean FullQ(QueueType Queue)

{
	return (Queue.count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue->count --;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue->count ++;
	}
	else
		printf("Full Queue \n");
}



void TraverseQ(QueueType Queue) {
	int current,i;
	if (EmptyQ(Queue))
    {
        printf("Empty queue ");
    }

    else
    {
	current = Queue.Front;
	printf("Queue: ");
	for(i=1;i<=Queue.count;i++)
    {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
    }
	printf("\n");
}
