#include"head.h"
/*
�˺��������һ�к����һ�е�cell[i][j]������tempCell[i][j]
*/
void row_col_cell(int i, int j){ //���뵱ʱϸ��
	int sum = 0;

	if((SIZE == i) && (j != SIZE)) //���һ�е��������һ��
	{
		if(cell[i][j - 1] == 1) //��ߵ�ϸ��
			sum++;
		if(cell[i - 1][j - 1] == 1)//���Ͻǵ�ϸ��
			sum++;
		if(cell[i - 1][j] == 1)//���Ϸ���ϸ��
			sum++;
		if(cell[i + 1][j + 1] == 1)//���Ͻǵ�ϸ��
			sum++;
		if(cell[i][j + 1] == 1)//�ұߵ�ϸ��
			sum++;

	 }
	 else if((SIZE == j) && (SIZE != i )) //���һ�е��������һ��
	{
		if(cell[i - 1][j] == 1) //���ϱߵ�ϸ��
			sum++;
		if(cell[i - 1][j - 1] == 1)//���Ͻǵ�ϸ��
			sum++;
		if(cell[i][j - 1] == 1)//�󷽵�ϸ��
			sum++;
		if(cell[i + 1][j - 1] == 1)//���½ǵ�ϸ��
			sum++;
		if(cell[i + 1][j] == 1)//���±ߵ�ϸ��
			sum++;
	}
	else{//���һ��cell
		if(cell[i - 1][j] == 1)//���Ϸ���ϸ��
			sum++;
		if(cell[i - 1][j - 1] == 1)//���Ͻǵ�ϸ��
		    sum++;
		if(cell[i][j - 1] == 1)//��ߵ�ϸ��
			sum++;
	}
	//����sum�жϵ�ǰcell����һ�����ڵ�״̬
	if(sum == 3)
		tempCell[i][j] = 1;
	else if(sum == 2)
		tempCell[i][j] = cell[i][j];
	else
	 	tempCell[i][j] = 0;

}

