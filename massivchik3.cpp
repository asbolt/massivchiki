#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

struct Matrix2 
{
    int *adress;
    int amountSumbols;
};

int createMatrixes (int **matrix, Matrix2 **matrix2, int *sizeMatrix, int *rows);
int scanAmountSumbols (Matrix2 *matrix2, int rows, int sizeMatrix);
int scanSymbols (int rows, Matrix2 *matrix2, int *matrix);
int printMatrix (int rows, Matrix2 *matrix2, int *matrix);

int main ()
{
    int *matrix = NULL;
    Matrix2 *matrix2 = NULL;
    int sizeMatrix = 0;
    int rows = 0;

    createMatrixes (&matrix, &matrix2, &sizeMatrix, &rows);

    scanAmountSumbols (matrix2, rows, sizeMatrix);

    scanSymbols (rows, matrix2, matrix);

    printMatrix (rows, matrix2, matrix);

    return 0;
}

int createMatrixes (int **matrix, Matrix2 **matrix2, int *sizeMatrix, int *rows)
{
    printf ("Сколько символов тебе нужно?\n");
    scanf ("%d", sizeMatrix);

    *matrix = (int *)calloc (*sizeMatrix, sizeof(int));

    printf ("Сколько рядов будет в массиве?\n");
    scanf ("%d", rows);

    *matrix2 = (Matrix2 *)calloc (*rows, sizeof(Matrix2));

    return 0;
}

int scanAmountSumbols (Matrix2 *matrix2, int rows, int sizeMatrix)
{
    int symbolsAmount = 0;
    
    for (int rowIndex = 0; rowIndex < rows-1; rowIndex++)
    {
        int symbols = 0;

        printf ("Сколько символов будет в %d ряду?\n", rowIndex);
        scanf ("%d", &symbols);

        symbolsAmount += symbols;

        if (symbolsAmount > sizeMatrix)
        {
            printf ("Чето дохера, пересчитай\n");
            return 1;
        }
        else if (symbolsAmount == sizeMatrix && rowIndex != rows - 2)
        {
            printf ("А нахер тебе остальные ряды?\n");
            return 1;
        }

        matrix2[rowIndex].amountSumbols = symbols;

        if (rowIndex == rows - 2)
        {
            matrix2[rowIndex+1].amountSumbols = sizeMatrix - symbolsAmount;
        }

        matrix2[rowIndex+1].adress = matrix2[rowIndex].adress + symbols;
    }

    return 0;
}

int scanSymbols (int rows, Matrix2 *matrix2, int *matrix)
{
    int amountSumbols = 0;

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        printf ("Введите элементы ряда %d:\n", rowIndex);

        for (int symbols = 0; symbols < matrix2[rowIndex].amountSumbols; symbols++)
        {
            scanf ("%d", &matrix[amountSumbols]);

            amountSumbols++;
        }
    }

    return 0;
}

int printMatrix (int rows, Matrix2 *matrix2, int *matrix)
{
    printf ("Результат:\n");
    
    int symbol = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {

        for (int symbols = 0; symbols < matrix2[rowIndex].amountSumbols; symbols++)
        { 
            printf ("%d", matrix[symbol]);

            symbol++;
        }

        printf ("\n");
    }

    return 0;
}