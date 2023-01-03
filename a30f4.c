#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define StackLimit 10
#define NilValue -1


typedef struct
{
    int am;
    //float grade;

} StackElementType;
typedef struct
{
    int am;
    float grade;

} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;


typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;



void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void TraverseStack(StackType Stack);





int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    StackElementType AnItem1;
    StackType AStack;
    ListElementType AnItem;
    int i;
    float min;


    InitializeStoragePool(Node, &FreePtr);

     CreateList(&AList);

    printf("---------------Question C--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(AList, FreePtr, Node);


    printf("---------------Question D--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(AList, Node);


     printf("---------------Question E--------------------\n");

     for(i=0; i<5; i++)
     {
         printf("DWSE AM GIA EISAGWGH STH LISTA:");
         scanf("%d", &AnItem.am);
         printf("DWSE VATHMO GIA EISAGWGH STH LISTA:");
         scanf("%f", &AnItem.grade);
         Insert(&AList, Node,&FreePtr, PredPtr, AnItem);

     }



     printf("---------------Question F--------------------\n");
      printf("--------------Storage pool------------------\n");
     printAll(AList, FreePtr, Node);


     printf("---------------Question G--------------------\n");
     printf("--------------Linked list--------------------\n");
     TraverseLinked(AList, Node);



      printf("---------------Question H--------------------\n");
    if (EmptyList(AList))
    {
        printf("Empty List\n");
    }

    else
    {
        printf("Not an Empty List\n");
    }



     printf("---------------Question I--------------------\n");
    if (FullList(FreePtr))
    {
        printf("Full List\n");
    }
    else
    {
        printf("Not a Full List\n");
    }


    printf("---------------Question J--------------------\n");

    min = FindMins(AList, Node,&AStack);

    printf("Min value=%0.1f\n", min);

    while (!EmptyStack(AStack))
    {
         Pop(&AStack, &AnItem1);
         printf("AM with min grade: ");
         printf("%d ",AnItem1);
    }


    printf("---------------Question K--------------------\n");
    TraverseStack(AStack);


    printf("---------------Question L--------------------\n");
     printf("--------------Storage pool------------------\n");
    printAll(AList, FreePtr, Node);



    printf("---------------Question M--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(AList, Node);













return 0;
}



void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)

{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am = -1;
        Node[i].Data.grade = -1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=NilValue;
    Node[NumberOfNodes-1].Data.grade=NilValue;
    *FreePtr=0;
}

void CreateList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)

{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)

{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])

{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)

{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)

{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)

{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])

{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}


void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
{
  ListPointer CurrPtr;
  float min;
  StackElementType AnItem;

  CreateStack(&Stack);

  if (!EmptyList(List))
  {
      CurrPtr = List;
      min = Node[CurrPtr].Data.grade;

      while(CurrPtr != NilValue)
      {
          if(Node[CurrPtr].Data.grade<=min)
          {
              if(Node[CurrPtr].Data.grade <min)
              {
                  while (!EmptyStack(*Stack))
                  {
                       Pop(&Stack, &AnItem);
                  }
                  Node[CurrPtr].Data.grade = CurrPtr;
              }
              Push(&Stack,AnItem);
          }
           CurrPtr = Node[CurrPtr].Next;
      }
  }
  else
  {
      printf("Empty List ...");
  }
return min;
}



void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%0.1f> ->%d) ",i,Node[i].Data.am, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


