#include <stdio.h>
#include <stdlib.h>


#define StackLimit 20


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
StackType CopyStack(StackType *s1);



int main()
{
    StackType s1;
    StackType s2;
    StackElementType AnItem;
    int i;


    CreateStack(&s1);


    for(i=0; i<StackLimit; i++)
    {
         Push(&s1,i);
    }

    printf("Stack s1");
    TraverseStack(s1);

    s2 = CopyStack(&s1);

    printf("After copying s1 to s2 \n");
    printf("Stack s1");
    TraverseStack(s1);

    printf("Stack s2");
    TraverseStack(s2);


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




StackType CopyStack(StackType *s1)
{
    StackType s2;
    StackType tempS;
    StackElementType AnItem;


    CreateStack(&s2);
    CreateStack(&tempS);


    while (!EmptyStack(*s1))
    {
        Pop(s1, &AnItem);
        Push(&tempS, AnItem);

    }


    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &AnItem);
        Push(s1,AnItem);
        Push(&s2,AnItem);

    }


    return s2;
}
