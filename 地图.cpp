#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAXWIDTH (30)
#define MAXHEIGHT MAXWIDTH

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

void init(){
    // ������ر��� 
    int x, y, i, index;
    int xCenter = MAXHEIGHT%2==0 ? MAXHEIGHT/2 : MAXHEIGHT/2+1;
    int yCenter = MAXWIDTH%2==0 ? MAXWIDTH/2 : MAXWIDTH/2+1;
    CONSOLE_CURSOR_INFO cci;  //����̨�����Ϣ

    //�ж���������Ƿ����
    if(MAXWIDTH<16){
        printf("'MAXWIDTH' is too small!");
        getch();
        exit(0);
    }

    //���ô��ڴ�С 
    system("mode con: cols=96 lines=32");

    //���ع��
    hStdin = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdin, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hStdin, &cci);
    
    //��ӡ���� 
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
