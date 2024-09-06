#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

struct Matrix
{
    int *matrix = NULL;
    int sizeMatrix = 0;
    int rows = 0;
    int *adress = NULL;
    int amountSumbols[];
};

int createMatrixes (Matrix *matrix);
int scanAmountSumbols (Matrix *matrix);
int scanSymbols (Matrix *matrix);
int printMatrix (Matrix *matrix);

int main ()
{
    Matrix *matrix = NULL;

    createMatrixes (matrix);

    scanAmountSumbols (matrix);

    scanSymbols (matrix);

    printMatrix (matrix);

    return 0;
}

int createMatrixes (Matrix *matrix)
{
    printf ("Сколько символов тебе нужно?\n");
    scanf ("%d", &(*matrix).sizeMatrix);

    (*matrix).matrix = (int *)calloc ((*matrix).sizeMatrix, sizeof(int));

    printf ("Сколько рядов будет в массиве?\n");
    scanf ("%d", &(*matrix).rows);

    (*matrix).adress = (int *)calloc ((*matrix).rows, sizeof(Matrix));

    return 0;
}

int scanAmountSumbols (Matrix *matrix)
{
    int symbolsAmount = 0;
    
    for (int rowIndex = 0; rowIndex < (*matrix).rows - 1; rowIndex++)
    {
        int symbols = 0;

        printf ("Сколько символов будет в %d ряду?\n", rowIndex);
        scanf ("%d", &symbols);

        symbolsAmount += symbols;

        if (symbolsAmount > (*matrix).sizeMatrix)
        {
            printf ("Чето дохера, пересчитай\n");
            return 1;
        }
        else if (symbolsAmount == (*matrix).sizeMatrix && rowIndex != (*matrix).rows - 2)
        {
            printf ("А нахер тебе остальные ряды?\n");
            return 1;
        }

        (*matrix).amountSumbols[rowIndex] = symbols;

        if (rowIndex == (*matrix).rows - 2)
        {
            (*matrix).amountSumbols[rowIndex+1] = (*matrix).sizeMatrix - symbolsAmount;
        }

        (*matrix).amountSumbols[rowIndex + 1] = (*matrix).matrix[rowIndex] + symbols;
    }

    return 0;
}

int scanSymbols (Matrix *matrix)
{
    int amountSumbols = 0;

    for (int rowIndex = 0; rowIndex < (*matrix).rows; rowIndex++)
    {
        printf ("Введите элементы ряда %d:\n", rowIndex);

        for (int symbols = 0; symbols < (*matrix).amountSumbols[rowIndex]; symbols++)
        {
            scanf ("%d", &(*matrix).matrix[amountSumbols]);

            amountSumbols++;
        }
    }

    return 0;
}

int printMatrix (Matrix *matrix)
{
    printf ("Результат:\n");

    int symbol = 0;
    for (int rowIndex = 0; rowIndex < (*matrix).rows; rowIndex++)
    {

        for (int symbols = 0; symbols < (*matrix).amountSumbols[rowIndex]; symbols++)
        { 
            printf ("%d ", *(matrix[rowIndex].adress + symbols));

            symbol++;
        }

        printf ("\n");
    }

    return 0;
}