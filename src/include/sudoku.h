#pragma once

#ifndef SUDOKU_H
#define SUDOKU_H

#define ATTEMPTS_MAX 100

typedef struct Sudoku
{
    int cells[9][9];
} Sudoku;

void Sudoku_init(Sudoku* sudoku);

void Sudoku_print(Sudoku* sudoku);

bool Sudoku_is_unique(Sudoku* sudoku, int row, int col, int value);

void Sudoku_generate(Sudoku* sudoku);

void Sudoku_new(void);


#endif //SUDOKU_H
