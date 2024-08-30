#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define COMPONENTS 5
#define SCORE 2

enum Status 
{
    SUCCESS = 1, 
    ERROR   = 0
};

Status scan (int *data, int size);
Status printFirstRow ();
Status printMatrix (int data[]);

int main ()
{
    int size = (COMPONENTS-1)*COMPONENTS/2;

    int *data = (int*) calloc (size, sizeof(int));

    scan (data, size);
    
    printFirstRow ();

    printMatrix (data);

    free (data);
    data = NULL;

    return 0;
}

Status scan (int *data, int size)
{
    printf ("Введите элементы \n");
    for (int number = 0; number < size; number++)
    {
        scanf ("%d", &data[number]);
    }

    return SUCCESS;
}

Status printFirstRow ()
{
    printf (" ");

    for (int i = 0; i < COMPONENTS; i++)
    {
        printf ("%10d", i);
    }

    printf ("\n");

    return SUCCESS;
}

Status printMatrix (int data[])
{
    for (int ySize = 0; ySize < COMPONENTS; ySize++)
    {
        printf ("%d", ySize);
        for (int xSize = 0; xSize < ySize; xSize++)
        {
            printf ("%10d", data[(ySize-1)*ySize/2 + xSize]);
        }

        printf ("\n");
    }

    return SUCCESS;
}