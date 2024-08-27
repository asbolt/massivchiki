#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define STRING 5
#define COMPONENTS 5
#define SCORE 2

main ()
{
    double data [STRING][COMPONENTS];

    int y = 0;
    int x = 0;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < y; x++)
        {
            printf ("Введите счет игры %d:%d\n", y, x);
            scanf ("%lg", &data[y][x]);
        }
    }

    for (y = 0; y < 5; y++)
    {
        for (x = 4; x <= COMPONENTS - y; x--)
        {
            data[y][x] = 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf ("%10d", i);
    }

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            printf ("%10lg", data[y][x]);
        }
        printf ("\n");
    }
}