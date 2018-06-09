#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define SIZE 3
#define MAXWIDTH (3)
#define MAXHEIGHT MAXWIDTH

int cell[SIZE+1][SIZE+1] = {0};//ԭʼ����
int tempCell[SIZE+1][SIZE+1] = {0};//��ʱ���ϸ����һ��״̬����
void row_col_cell(int i, int j);
void general(int i, int j);
void copy_cell();
void deadOrlive();

//�������õ��ĸ����ַ����Լ����ǵ���ɫ�����ͣ������ֱ�ʾ��
struct{
    char *ch;
    int color;
    char type;
}
charBorder = {"��", 4, 1},  //��ϸ�� 
charBg = {"��", 2, 2};  //��ϸ�� 
//charSnake = {"��", 0xe, 3};  

//��һ���ṹ�����鱣���ͼ�еĸ�����
struct{
    char type;
    int index;
}globalMap[MAXWIDTH][MAXHEIGHT];


HANDLE hStdin;  //����̨���


// ������ɫ
void setColor(int color){
    SetConsoleTextAttribute(hStdin, color);
}

// ���ù��λ�ã�xΪ�У�yΪ��
void setPosition(int x, int y){
    COORD coord;
    coord.X = 2*y;
    coord.Y = x;
    SetConsoleCursorPosition(hStdin, coord);
}

void init(){
    // ������ر��� 
    int x, y, i, index;
    int xCenter = MAXHEIGHT%2==0 ? MAXHEIGHT/2 : MAXHEIGHT/2+1;
    int yCenter = MAXWIDTH%2==0 ? MAXWIDTH/2 : MAXWIDTH/2+1;
    CONSOLE_CURSOR_INFO cci;  //����̨�����Ϣ

    //�ж���������Ƿ����
//    if(MAXWIDTH<16){
//        printf("'MAXWIDTH' is too small!");
//        getch();
//        exit(0);
//    }

    //���ô��ڴ�С 
    system("mode con: cols=96 lines=32");

    //���ع��
    hStdin = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdin, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hStdin, &cci);
    
//    //��ӡ���� 
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
	for(i = 0; i <= SIZE; i++)//��0�г�ʼ��
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
