#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define STRING 5
#define COMPONENTS 5
#define SCORE 2

main ()
{
    double data [STRING][COMPONENTS] = {{0, 0, 0, 0, 0},
                                        {1.2, 0, 0, 0, 0},
                                        {2.6, 4.3, 0, 0, 0},
                                        {2.3, 1.6, 3.5, 0, 0},
                                        {3.4, 5.1, 1.1, 2.1, 0}};

    int y = 0;
    int x = 0;

    for (int i = 0; i < 5; i++)
    {
        printf ("%10d", i);
    }
    printf ("\n");

    for (y = 0; y < 5; y++)
    {
        printf ("%d", y);
        for (x = 0; x < y; x++)
        {
            printf ("%10.1lf", data[y][x]);
        }
        for (x = y; x < 5; x++)
        {
            printf ("%10.0lf", data[y][x]);
        }
        printf ("\n");
    }
}