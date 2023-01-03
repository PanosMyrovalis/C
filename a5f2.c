#include <stdio.h>
#include <stdlib.h>


#define StackLimit 15


typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;


typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);


int main()
{

    StackElementType i,x , n, j, item, temp1;
    StackType Stack, temp;


    CreateStack(&Stack);

    for(i=0; i<StackLimit; i++)
    {
         Push(&Stack,i * 10);

    }

    TraverseStack(Stack);

    printf("Give nth element (n<=6) ");
    scanf("%d", &n);


    Pop(&Stack, &x);
    Pop(&Stack, &x);


    printf("\nQuestion a: x = %d", x);


    TraverseStack(Stack);


    Pop(&Stack, &temp1);
    Pop(&Stack, &x);

    Push(&Stack,x);
    Push(&Stack,temp1);

    printf("\nQuestion b: x = %d", x);

    TraverseStack(Stack);



     for(i=0; i<n; i++)
    {
        Pop(&Stack, &x);
    }

    printf("\nQuestion c: x = %d", x);


    TraverseStack(Stack);



    CreateStack(&temp);


    for(i=0; i<n; i++)
    {
        Pop(&Stack, &x);
        Push(&temp,x);

    }


    printf("\nQuestion d: x = %d", x);

    while(!EmptyStack(temp))
    {
        Pop(&temp, &item);
        Push(&Stack,item);
    }

    TraverseStack(Stack);

    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &x);
         Push(&temp,x);
    }

    while(!EmptyStack(temp))
    {
        Pop(&temp, &item);
        Push(&Stack,item);
    }


    printf("\nQuestion e: x = %d", x);

    TraverseStack(Stack);


    while(Stack.Top >= 2)
    {
        Pop(&Stack, &x);
        Push(&temp,x);
    }

     printf("\nQuestion f: x = %d", x);


     while(!EmptyStack(temp))
     {
         Pop(&temp, &x);
         Push(&Stack,x);

     }



    TraverseStack(Stack);


    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &x);
    }

    printf("\nQuestion g: x = %d", x);



    TraverseStack(temp);


    return 0;

}



void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;

}



void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}



void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}



void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}




boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}
