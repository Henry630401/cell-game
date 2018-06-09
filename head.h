#include <stdio.h>
#include <stdlib.h>
#include "main.c"
#include "copy_cell.c"
#include "general_cell.c"
#include "rol_col_cell.c"
#define SIZE 3
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
int cell[SIZE+1][SIZE+1] = {0};//原始数组
int tempCell[SIZE+1][SIZE+1] = {0};//临时存放细胞下一个状态数组
void row_col_cell(int i, int j);
void general(int i, int j);
void copy_cell();
#endif // HEAD_H_INCLUDED


