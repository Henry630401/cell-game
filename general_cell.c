#include"head.h"
/*
此函数是cell[i][j]周围有八个细胞，更新tempCell[i][j]
*/
void general(int i, int j){
    int sum = 0;
    if(cell[i - 1][j] == 1)//上面的cell
        sum++;
    if(cell[i - 1][j + 1] == 1)//右上面的cell
        sum++;
    if(cell[i][j + 1] == 1)//右面的cell
        sum++;
    if(cell[i + 1][j + 1] == 1)//右下面的cell
        sum++;
    if(cell[i + 1][j] == 1)//正下面的cell
        sum++;
    if(cell[i + 1][j - 1] == 1)//左下面的cell
        sum++;
    if(cell[i][j - 1] == 1)//左面的cell
        sum++;
    if(cell[i - 1][j - 1] == 1)//左上面的cell
        sum++;
	//根据sum判断当前cell的下一个周期的状态
	if(sum == 3)
		tempCell[i][j] = 1;
	else if(sum == 2)
		tempCell[i][j] = cell[i][j];
	else
	 	tempCell[i][j] = 0;
}
