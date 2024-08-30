#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

enum Status 
{
    SUCCESS = 1, 
    ERROR   = 0
};

struct Matrix
{
    int *adress;
    int ySize;
    int xSize;
};

Status scanSize (int *xSize, int *ySize);
Status scanNumbers (Matrix *matrix);
Status printMatrix (Matrix matrix);
Status createMatrix (Matrix *matrix, int xSize, int ySize);
Status additionMatrix (Matrix matrix, Matrix matrix2, Matrix *matrix3);
Status freeAdress (Matrix matrix);
Status createSize (Matrix *matrix, int xSize, int ySize);

int main ()
{
    int ySize = 0, xSize = 0;

    scanSize (&xSize, &ySize);

    Matrix matrix = {};
    Matrix matrix2 = {};
    Matrix matrix3 = {};

    createMatrix (&matrix, ySize, xSize);
    createMatrix (&matrix2, ySize, xSize);
    createMatrix (&matrix3, ySize, xSize);

    scanNumbers (&matrix);
    scanNumbers (&matrix2);

    additionMatrix (matrix, matrix2, &matrix3);

    printf ("Результат сложения матриц:\n");
    printMatrix (matrix3);

    freeAdress (matrix);
    freeAdress (matrix2);
    freeAdress (matrix3);

    return 0;
}

Status createMatrix (Matrix *matrix, int ySize, int xSize)
{
    (*matrix).adress = (int*) calloc (xSize*ySize, sizeof(int));

    if ((*matrix).adress == NULL)
    {
        printf ("Недостаточно памяти\n");
        return ERROR;
    }

    createSize (matrix, xSize, ySize);

    return SUCCESS;
}

Status scanSize (int *xSize, int *ySize)
{
    printf ("Сколько рядов будет в матрицах?\n");
    scanf ("%d", ySize);

    printf ("Cколько чисел будет в каждом ряду?\n");
    scanf ("%d", xSize);

    return SUCCESS;
}

Status createSize (Matrix *matrix, int xSize, int ySize)
{
    (*matrix).xSize = xSize;
    (*matrix).ySize = ySize;

    return SUCCESS;
}

Status scanNumbers (Matrix *matrix)
{

    for (int row = 0; row < (*matrix).ySize; row++)
    {
        printf ("Введите элементы ряда %d:\n", row);
        for (int column = 0; column < (*matrix).xSize; column++)
        {
            scanf ("%d", &(*matrix).adress[row * (*matrix).xSize + column]);
        }
    }

    printf ("Ввод матрицы завершен\n");
    return SUCCESS;
}

Status additionMatrix (Matrix matrix, Matrix matrix2, Matrix *matrix3)
{
    for (int row = 0; row < (*matrix3).ySize; row++)
    {
        for (int column = 0; column < (*matrix3).xSize; column++)
        {
            (*matrix3).adress[row*(*matrix3).xSize + column] = matrix.adress[row*(matrix.xSize) + column] + 
            matrix2.adress[row*(matrix2.xSize) + column];
        }
    }

    return SUCCESS;
}

Status printMatrix (Matrix matrix)
{
    printf (" ");

    for (int column = 0; column < matrix.xSize; column++)
    {
        printf ("%10d", column);
    }
    printf ("\n");

    for (int row = 0; row < matrix.ySize; row++)
    {
        printf ("%d", row);

        for (int column = 0; column < matrix.xSize; column++)
        {
            printf ("%10d", matrix.adress[row*matrix.xSize + column]);
        }

        printf ("\n");
    }

    return SUCCESS;
}

Status freeAdress (Matrix matrix)
{
    free (matrix.adress);
    matrix.adress = NULL;

    return SUCCESS;
}