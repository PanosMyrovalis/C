#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1001

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo);
void createFibonacciSet(stoixeio_synolou n, typos_synolou synolo);
void displayset(typos_synolou set);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);



int main()
{
    stoixeio_synolou max, check, i;
    typos_synolou synolo, temp, temp1;


    Dimiourgia(temp);
    for(i =2; i<=1000; i++)
    {
        Eisagogi(i, temp);
    }

    printf("Dwse to megisto arithmo :");

    scanf("%d", &max);


    while(!Melos(max,temp))
    {
        printf("Dwse to megisto arithmo:");
        scanf("%d",&max);
    }


    createFibonacciSet(max,synolo);




    printf("\n");

        printf("Enter number to check :");
        scanf("%d", &check);

    Dimiourgia(temp);
    for(i =0; i<=1000; i++)
    {
        Eisagogi(i, temp1);
    }

    while(Melos(check,temp1))
    {




        if(isFibonacci(check, synolo))
        {
            printf("Fibonacci!");
            printf("\n");
        }

        else
        {
            printf("Not Fibonacci...");
            printf("\n");
        }

        printf("Enter number to check :");
        scanf("%d", &check);
    }



    return 0;
    system("PAUSE");
}



boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo)
{
    return Melos(n, synolo);
}




void createFibonacciSet(stoixeio_synolou n, typos_synolou synolo)
{
    stoixeio_synolou n1 = 0, n2 = 1, next_number = n1 +n2;

    Dimiourgia(synolo);

    Eisagogi(n1, synolo);
    Eisagogi(n2, synolo);

    while(next_number <=n)
    {
        Eisagogi(next_number, synolo);
        n1 = n2;
        n2 = next_number;
        next_number = n1 + n2;
    }

    displayset(synolo);


}



void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}



boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    return synolo[stoixeio];
}



void Dimiourgia(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}



void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    synolo[stoixeio] = TRUE;
}

