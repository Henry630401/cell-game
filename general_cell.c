#include"head.h"
/*
�˺�����cell[i][j]��Χ�а˸�ϸ��������tempCell[i][j]
*/
void general(int i, int j){
    int sum = 0;
    if(cell[i - 1][j] == 1)//�����cell
        sum++;
    if(cell[i - 1][j + 1] == 1)//�������cell
        sum++;
    if(cell[i][j + 1] == 1)//�����cell
        sum++;
    if(cell[i + 1][j + 1] == 1)//�������cell
        sum++;
    if(cell[i + 1][j] == 1)//�������cell
        sum++;
    if(cell[i + 1][j - 1] == 1)//�������cell
        sum++;
    if(cell[i][j - 1] == 1)//�����cell
        sum++;
    if(cell[i - 1][j - 1] == 1)//�������cell
        sum++;
	//����sum�жϵ�ǰcell����һ�����ڵ�״̬
	if(sum == 3)
		tempCell[i][j] = 1;
	else if(sum == 2)
		tempCell[i][j] = cell[i][j];
	else
	 	tempCell[i][j] = 0;
}
