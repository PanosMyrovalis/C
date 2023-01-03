#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
ListElementType RemoveMins(ListPointer *InList);


int main()
{
ListPointer AList;
 ListElementType Item, min;
 int i,n;

 CreateList(&AList);

 printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &n);

    for(i=0; i<n;i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, NULL);
    }

    printf("Traversing list\n");
    LinkedTraverse(AList);

    printf("Removing min from list\n");
    min = RemoveMins(&AList);
    printf("Min was %d\n", min);

    printf("Traversing list with min removed\n");
    LinkedTraverse(AList);







return 0;
}

void CreateList(ListPointer *List)

{
	*List = NULL;
}

boolean EmptyList(ListPointer List)

{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)

{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)

{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)

{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}



ListElementType RemoveMins(ListPointer *InList)
{
    ListPointer CurrPtr, PredPtr;
     ListElementType min;

    CurrPtr = *InList;

    min = CurrPtr->Data;

    while(CurrPtr != NULL)
    {
        if(CurrPtr->Data < min)
        {
           min = CurrPtr->Data;

        }
         CurrPtr = CurrPtr->Next;
    }

    CurrPtr = *InList;
    PredPtr = NULL;

     while(CurrPtr != NULL)
     {
         if(CurrPtr->Data == min)
         {
            CurrPtr = CurrPtr->Next;
            LinkedDelete(InList, PredPtr);
         }

         else
         {
             PredPtr = CurrPtr;
             CurrPtr = CurrPtr->Next;

         }
     }

return min;

}

