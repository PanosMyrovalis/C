#include <stdio.h>
#include <stdlib.h>


#define StackLimit 80

typedef struct {

int price;
char size;
}StackElementType;


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

StackType itemsStack, tempStack;
StackElementType AnItem;
char size;
boolean found;
int number, i;



CreateStack(&itemsStack);
CreateStack(&tempStack);


printf("Give number of items ");
scanf("%d", &number);

printf("Give the items to store \n");

for(i = 0; i<number; i++)
{
    printf("Give price ");
    scanf("%d", &AnItem.price); getchar();

    printf("Give size ");
    scanf(" %c", &AnItem.size); getchar();
    Push(&itemsStack, AnItem);

}

printf("Items in the box \n");


TraverseStack(itemsStack);

printf("What size do you want? ");

scanf(" %c", &size);

found = FALSE;

while(!EmptyStack(itemsStack) && found == FALSE)
{
    Pop(&itemsStack, &AnItem);

    if(AnItem.size == size)
    {
        found = TRUE;
        break;
    }

    else
    {
      Push(&tempStack,AnItem);
    }
}


if(found == TRUE)
{
    printf("Found the size %c \n", size);
}

else
{
    printf("Not Found the size %c \n", size);
}


printf("Items in the box ");

TraverseStack(itemsStack);

printf("Items out the box ");

TraverseStack(tempStack);


while(!EmptyStack(tempStack))
{
    Pop(&tempStack, &AnItem);
    Push(&itemsStack,AnItem);

}


printf("Items in the box ");

TraverseStack(itemsStack);


printf("Items out the box ");

TraverseStack(tempStack);



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

        printf("%c, ",Stack.Element[i].size);
        printf("%d\n",Stack.Element[i].price);

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
