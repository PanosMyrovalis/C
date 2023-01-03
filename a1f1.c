#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define megisto_plithos 201      //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;


boolean isPrime(stoixeio_synolou n);
void Dimiourgia(typos_synolou synolo);
void createPrimeSet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou primes);
void displaySet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);


int main()
{

    stoixeio_synolou first, last, i;
    typos_synolou synolo1, temp, temp1;

    Dimiourgia(temp);
    for(i =2; i<=199; i++)
    {
        Eisagogi(i, temp);
    }
    printf("Dwse first:");
    scanf("%d",&first);

    while(!Melos(first,temp))
    {
        printf("Dwse first:");
        scanf("%d",&first);
    }

    Dimiourgia(temp1);
    for(i =2; i<=200; i++)
    {
        Eisagogi(i, temp1);
    }
    printf("Dwse last :");
    scanf("%d",&last);

    while(!Melos(last,temp1) || last <=first)
    {
        printf("Dwse last :");
        scanf("%d",&last);
    }



    displaySet(first,last,synolo1);


    return 0;
    system("PAUSE");
}




boolean isPrime(stoixeio_synolou n)


{
    stoixeio_synolou i, temp = 0;
    boolean found = FALSE;


    for (i = 2; i <= n / 2; i++)
    {
            if (n % i == 0)
        {
            temp = 1;
            found = FALSE;
            break;
        }
    }



        if (temp == 0 )
        {

           found = TRUE;

        }

        else
        {
            found == FALSE;

        }
        return found;
    }








    void Dimiourgia(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}




void createPrimeSet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou primes)
{
    stoixeio_synolou i;

    Dimiourgia(primes);


    for(i =first; i<last; i++)
    {


        if(isPrime(i))
        {
            Eisagogi(i, primes);
        }


    }
}



void displaySet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou synolo)
{
    stoixeio_synolou i;

    Dimiourgia(synolo);

    createPrimeSet(first,last,synolo);

    for(i=first; i<=last; i++)
    {

        if(Melos(i,synolo))
        {
             printf("%d", i);
             printf(" ");

        }




    }

}



boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    return synolo[stoixeio];
}



void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    synolo[stoixeio] = TRUE;
}




