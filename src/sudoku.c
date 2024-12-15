#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <src/include/sudoku.h>
#include <src/include/rand.h>

void Sudoku_init(Sudoku* sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku->cells[i][j] = 0;
        }
    }
}

void Sudoku_print(Sudoku* sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
        }

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                printf("  ");
            }

            printf("%d  ", sudoku->cells[i][j]);
        }
        printf("\n");
    }
}

bool Sudoku_is_unique(Sudoku* sudoku, int row, int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku->cells[row][i] == value || sudoku->cells[i][col] == value)
        {
            return false;
        }
    }

    int cell_start_i = (int)ceil(row / 3) * 3;
    int cell_start_j = (int)ceil(col / 3) * 3;

    for (int i = cell_start_i; i < cell_start_i + 3; i++)
    {
        for (int j = cell_start_j; j < cell_start_j + 3; j++)
        {
            if (sudoku->cells[i][j] == value)
            {
                return false;
            }
        }
    }

    return true;
}

void Sudoku_generate(Sudoku* sudoku)
{
    int attempts = 0;
    int value;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            value = utils_rand(1, 9);

            // if count of unsuccess attempts >= ATTEMPTS_MAX, then reset all and start from the beginning
            if (attempts >= ATTEMPTS_MAX)
            {
                Sudoku_init(sudoku);
                attempts = 0;
                i = 0;
                j = 0;
            }

            if (Sudoku_is_unique(sudoku, i, j, value))
            {
                attempts = 0;
                sudoku->cells[i][j] = value;
            } else
            {
                // increment unsuccess value
                attempts += 1;
                j -= 1;
            }
        }
    }
}

void Sudoku_new(void)
{
    Sudoku sudoku;

    Sudoku_init(&sudoku);
    Sudoku_generate(&sudoku);
    Sudoku_print(&sudoku);
}

