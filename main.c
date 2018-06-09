#include"head.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//显示函数
void show()
{
	int i, j;
	for(i = 1; i <= SIZE; i++ )
	{
		for(j = 1; j <= SIZE; j++ )
		{
			if(cell[i][j] == 1)
				printf("  *");
			else
				printf("  -");
		}
		printf("\n");
	}

}
int main(int argc, char *argv[]) {
	int i, j;
	for(i = 0; i <= SIZE; i++)//第0行初始化
	{
		cell[0][i] = -1;
	}
	for(i = 0; i <= SIZE; i++)
	{
		cell[i][0] = -1;
	}
	cell[1][1] = 1;
	cell[2][3] = 1;
	cell[3][1] = 1;
	cell[3][3] = 1;
	show();
	return 0;
}
