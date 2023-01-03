#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10

#define NilValue -1

typedef int ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);



int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    char ch;
    boolean found;
    int i;

    ListElementType AnItem;

    InitializeStoragePool(Node, &FreePtr);

    CreateList(&AList);

    printf("---------------Question C--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(AList, FreePtr, Node);

    printf("---------------Question D--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(AList, Node);

    printf("---------------Question E--------------------\n");

    do
    {
        printf("Give a number: ");
        scanf("%d", &AnItem);
        Search( FreePtr,  AList,  Node,  AnItem,  &PredPtr);
        PredPtr=NilValue;
        Insert(&AList, Node,&FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
        printf("\nContinue Y/N: ");

        do
        {
        scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    printf("---------------Question F--------------------\n");
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
    printf("---------------Search for a number--------------------\n");

    for(i=0; i<2; i++)
    {


    printf("Give a number ");
    scanf("%d", &AnItem);
    found = Search( FreePtr,  AList,  Node,  AnItem,  &PredPtr);

    if(found == TRUE)
    {
        printf("The number is in the list and its predecessor is in position %d\n", PredPtr);
    }

    else
    {
        printf("The number is not in the list\n");
    }


    }

return 0;


}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)

{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=NilValue;
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
  Node[P].Data = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
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



boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr)
{
 boolean stop = FALSE;
 boolean found = FALSE;
 ListPointer current;

 *PredPtr = NilValue;


 if (!EmptyList(List))
 {
     current = List;

     while(current != NilValue && !stop)
     {
         if(current >= Item)
        {
           stop = TRUE;
           if(current == Item)
           {
              found = TRUE;

           }
           else
           {
               found = FALSE;
           }

         }
         else
         {
             *PredPtr = current;
             current = Node[current].Next;

         }
     }
 }

 else
 {
     found = FALSE;
 }

 return found;


}



void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

