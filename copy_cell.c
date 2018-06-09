#include"head.h"
/*
此函数是一个细胞的周期结束，更新cell的状态
*/
void copy_cell(){
    int i, j;
    for(i = 1; i <= SIZE; i++){
        for(j = 1; j <= SIZE; j++){
            cell[i][j] = tempCell[i][j];
        }
    }
}
