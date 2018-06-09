#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define SIZE 3
#define MAXWIDTH (3)
#define MAXHEIGHT MAXWIDTH

int cell[SIZE+1][SIZE+1] = {0};//原始数组
int tempCell[SIZE+1][SIZE+1] = {0};//临时存放细胞下一个状态数组
void row_col_cell(int i, int j);
void general(int i, int j);
void copy_cell();
void deadOrlive();

//程序中用到的各种字符，以及它们的颜色和类型（以数字表示）
struct{
    char *ch;
    int color;
    char type;
}
charBorder = {"□", 4, 1},  //死细胞 
charBg = {"■", 2, 2};  //活细胞 
//charSnake = {"★", 0xe, 3};  

//用一个结构体数组保存地图中的各个点
struct{
    char type;
    int index;
}globalMap[MAXWIDTH][MAXHEIGHT];


HANDLE hStdin;  //控制台句柄


// 设置颜色
void setColor(int color){
    SetConsoleTextAttribute(hStdin, color);
}

// 设置光标位置，x为行，y为列
void setPosition(int x, int y){
    COORD coord;
    coord.X = 2*y;
    coord.Y = x;
    SetConsoleCursorPosition(hStdin, coord);
}

void init(){
    // 设置相关变量 
    int x, y, i, index;
    int xCenter = MAXHEIGHT%2==0 ? MAXHEIGHT/2 : MAXHEIGHT/2+1;
    int yCenter = MAXWIDTH%2==0 ? MAXWIDTH/2 : MAXWIDTH/2+1;
    CONSOLE_CURSOR_INFO cci;  //控制台光标信息

    //判断相关设置是否合理
//    if(MAXWIDTH<16){
//        printf("'MAXWIDTH' is too small!");
//        getch();
//        exit(0);
//    }

    //设置窗口大小 
    system("mode con: cols=96 lines=32");

    //隐藏光标
    hStdin = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdin, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hStdin, &cci);
    
//    //打印背景 
//    for(x=0; x<MAXHEIGHT; x++){
//        for(y=0; y<MAXWIDTH; y++){
//            if(y==0 || y==MAXWIDTH-1 || x==0 || x==MAXHEIGHT-1){
//                globalMap[x][y].type = charBg.type;
//                setColor(charBg.color);
//                printf("%s", charBg.ch);
//            }else{
//                index = (x-1)*(MAXWIDTH-2)+(y-1);
//                globalMap[x][y].type = charBg.type;
//                globalMap[x][y].index = index;
//
//                setColor(charBg.color);
//                printf("%s", charBg.ch);
//            }
//        }
//        printf("\n");
//    }
}
    int main()
    {
    int i, j;
	for(i = 0; i <= SIZE; i++)//第0行初始化
	{
		cell[0][i] = -1;
	}
	for(i = 0; i <= SIZE; i++)
	{
		cell[i][0] = -1;
	}
	cell[1][2] = 1;
	cell[2][3] = 1;
	cell[2][2] = 1;
	init();
	int x,y;	
    
    while(1){
	  for(x=1; x <= MAXHEIGHT; x++){
        for(y=1; y <= MAXWIDTH; y++){
       		if (cell[x][y] == 0) {
       			setColor(charBorder.color);
           		printf("%s", charBorder.ch);
			   } 
			   else {
			   	setColor(charBg.color);
               printf("%s", charBg.ch);
			   }
        }
        printf("\n");
	  }
	  deadOrlive();
	  Sleep(2000);
    }
		return 0;
	}
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

void deadOrlive()
{
    int i, j;
    for(i = 1; i < SIZE + 1; i++)
    {
        for(j = 1; j < SIZE + 1; j++)
        {
            if(i == SIZE || j == SIZE)
                row_col_cell(i, j);
            else
                general(i, j);
        }
    }
    
    copy_cell();
    
}
