#include"head.h"
/*
此函数是最后一行和最后一列的cell[i][j]，更新tempCell[i][j]
*/
void row_col_cell(int i, int j){ //传入当时细胞
	int sum = 0;

	if((SIZE == i) && (j != SIZE)) //最后一行但不是最后一列
	{
		if(cell[i][j - 1] == 1) //左边的细胞
			sum++;
		if(cell[i - 1][j - 1] == 1)//左上角的细胞
			sum++;
		if(cell[i - 1][j] == 1)//正上方的细胞
			sum++;
		if(cell[i + 1][j + 1] == 1)//右上角的细胞
			sum++;
		if(cell[i][j + 1] == 1)//右边的细胞
			sum++;

	 }
	 else if((SIZE == j) && (SIZE != i )) //最后一列但不是最后一行
	{
		if(cell[i - 1][j] == 1) //正上边的细胞
			sum++;
		if(cell[i - 1][j - 1] == 1)//左上角的细胞
			sum++;
		if(cell[i][j - 1] == 1)//左方的细胞
			sum++;
		if(cell[i + 1][j - 1] == 1)//左下角的细胞
			sum++;
		if(cell[i + 1][j] == 1)//正下边的细胞
			sum++;
	}
	else{//最后一个cell
		if(cell[i - 1][j] == 1)//正上方的细胞
			sum++;
		if(cell[i - 1][j - 1] == 1)//左上角的细胞
		    sum++;
		if(cell[i][j - 1] == 1)//左边的细胞
			sum++;
	}
	//根据sum判断当前cell的下一个周期的状态
	if(sum == 3)
		tempCell[i][j] = 1;
	else if(sum == 2)
		tempCell[i][j] = cell[i][j];
	else
	 	tempCell[i][j] = 0;

}

