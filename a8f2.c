#include <stdio.h>
#include <stdlib.h>


#define StackLimit 80


typedef char StackElementType;

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
    boolean valid, flag;
    char ch, item;
    StackType Stack;

    valid = TRUE;
    flag = FALSE;

    CreateStack(&Stack);

    printf("Enter string: \n");
    scanf("%c", &ch); getchar();

    if(ch == '#' )
    {
        exit(0);
    }


    while(ch != '#' && valid == TRUE)
    {

        if(flag == FALSE)
        {
            if(ch == 'C')
            {
                flag = TRUE;
                scanf("%c", &ch); getchar();

            }
            else
            {
               Push(&Stack,ch);
               scanf("%c", &ch); getchar();
            }

        }

        else
        {


            if (!EmptyStack(Stack))
            {
                Pop(&Stack, &item);

                if(item != ch)
                {
                    valid = FALSE;
                }

                else
                {
                    scanf("%c", &ch); getchar();
                }
            }

            else
            {
                valid = FALSE;
            }
        }
    }


    if(valid == TRUE && EmptyStack(Stack))
    {
        printf("TRUE");
    }

    else
    {
        printf("FALSE");
    }







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
