#include"head.h"
/*
�˺�����һ��ϸ�������ڽ���������cell��״̬
*/
void copy_cell(){
    int i, j;
    for(i = 1; i <= SIZE; i++){
        for(j = 1; j <= SIZE; j++){
            cell[i][j] = tempCell[i][j];
        }
    }
}
