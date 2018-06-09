#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAXWIDTH (30)
#define MAXHEIGHT MAXWIDTH

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

void init(){
    // 设置相关变量 
    int x, y, i, index;
    int xCenter = MAXHEIGHT%2==0 ? MAXHEIGHT/2 : MAXHEIGHT/2+1;
    int yCenter = MAXWIDTH%2==0 ? MAXWIDTH/2 : MAXWIDTH/2+1;
    CONSOLE_CURSOR_INFO cci;  //控制台光标信息

    //判断相关设置是否合理
    if(MAXWIDTH<16){
        printf("'MAXWIDTH' is too small!");
        getch();
        exit(0);
    }

    //设置窗口大小 
    system("mode con: cols=96 lines=32");

    //隐藏光标
    hStdin = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdin, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hStdin, &cci);
    
    //打印背景 
    for(x=0; x<MAXHEIGHT; x++){
        for(y=0; y<MAXWIDTH; y++){
            if(y==0 || y==MAXWIDTH-1 || x==0 || x==MAXHEIGHT-1){
                globalMap[x][y].type = charBg.type;
                setColor(charBg.color);
                printf("%s", charBg.ch);
            }else{
                index = (x-1)*(MAXWIDTH-2)+(y-1);
                globalMap[x][y].type = charBg.type;
                globalMap[x][y].index = index;

                setColor(charBg.color);
                printf("%s", charBg.ch);
            }
        }
        printf("\n");
    }
}
    int main()
    {
    	init();
    	return 0;
	}
