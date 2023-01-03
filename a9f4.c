#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;


typedef char QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;



void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);




int main()
{
 StackPointer AStack;
 QueueType AQueue;
 char str[40];
 char ch1, ch2;
 boolean flag;
 int i;

 CreateStack(&AStack);
 CreateQ(&AQueue);

 printf("DWSE TO ALFARITHMITIKO: ");
  gets(str);


  for(i=0; i<strlen(str); i++)
  {
      Push(&AStack,str[i]);
      AddQ(&AQueue,str[i]);
  }

  printf("-------Stack of characters-------\n");
  TraverseStack(AStack);

  printf("-------Queue of characters-------\n");
  TraverseQ(AQueue);

  i = 0;

  flag = TRUE;

  while(flag && i<strlen(str))
  {
      Pop(&AStack, &ch1);
      RemoveQ(&AQueue, &ch2);

      if(ch1 != ch2)
      {
          flag = FALSE;
      }

      i++;
  }


  if(flag == FALSE)
  {
      printf("%s REJECTED\n", str);
  }

  else
  {
      printf("%s ACCEPTED\n", str);
  }








return 0;
}



void CreateQ(QueueType *Queue)

{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}


void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}


void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateStack(StackPointer *Stack)

{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)

{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)

{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)

{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}



