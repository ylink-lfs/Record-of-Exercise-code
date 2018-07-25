#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
/////////////////////������ �궨�����/////////////////////
#define WIDTH				800					//��Ļ���
#define HEIGHT  			780					//��Ļ�߶�
#define B_WIDTH 			60					//����/����ǹ�Ŀ��
#define B_HEIGHT			60					//����/����ǹ�ĸ߶�
#define S_WIDTH				220					//�Ʒְ�Ŀ��
#define S_HEIGHT			80					//�Ʒְ�ĸ߶�
#define LB_WIDTH			540					//��౳���Ŀ��
#define RB_WIDTH			260					//�Ҳ౳���Ŀ��
#define cur_positioni			12				   //����ǹ������
#define score_per_Bubble	100				   //ÿ�����ݵķ���
////////////////////������ ȫ�ֱ���////////////////////
IMAGE picture[7];																	//��������ͼ�����
IMAGE initbackimage, scoreimage, Leftbackimage, Rightbackimage;						//��������ͼ�����
IMAGE start,restart, end;															//����ͼ��ͼ�����
int array2D[13][9];				//����һ����ά����
int i;							//���������
int j;							//���������
int cur_position=4;					//����ǹ��ǰ��λ�ã�������
int pre_position = 4;				//����ǹ֮ǰ��λ�ã�������
//int bobCount = 0;				//��ͨ���ݼ���
int thisBubble = 0;				//�������
int nextBubble = 0;				//��һ������
int shootingBubble = 0;			//�����е�����
int GamePhase = 0;				//��Ϸ�׶� ��0��������׶� 1����ʼ�׶� 2������Ϸ�׶� 3��������׶Σ�
int mouseX;						//���λ������X
int mouseY;						//���λ������Y
bool isMouseDown;				//��갴��
int number=0;					//������������
int count=0;					//��¼�ܵ�������������
int score=0;					//����

/////////////////////������ ��������/////////////////////
//void LoadResource();
void Menu();
void StartPage();
void ProduceInitialBubble();
void ShootBubble();
int StopBubble(int x, int y);
void rmBob(int x, int y);
void RemoveBubble(int x, int y);
void RiseBubble();
void ProduceNewBubble();
void Score(int number);
void Manager();
void PutImage();
void Gameover();
void Draw();
void EndPage();

bool judge_valid_area(int x, int y);
int main()
{
	setbuf(stdin, NULL);
	//�����������
	srand((unsigned)time(NULL));
	//��ʼ���豸������ͼƬ
	initgraph(WIDTH, HEIGHT,SHOWCONSOLE);
	//��������,��ֹ����
	BeginBatchDraw();
	// �����Ϣ����
	MOUSEMSG mmsg;
	while (true)
	{
		//���������Ϣ
		while (MouseHit())
		{

			mmsg = GetMouseMsg();
			switch (mmsg.uMsg)
			{
			case WM_MOUSEMOVE:		mouseX = mmsg.x; mouseY = mmsg.y;		break;
			case WM_LBUTTONDOWN:	isMouseDown = true;						break;
			//case WM_LBUTTONUP:		isMouseDown = false;					break;
			}
		}
		if (GamePhase == 2)
		{
			isMouseDown = false;
		}
		if (GamePhase == 3)
		{
			fflush(NULL);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
		//�߼�����
		Manager();
		//��ͼ����
		Draw();
		//��ʾ����Ļ�������6

		FlushBatchDraw();
	}

	//�����������ƣ���ִ��δ��ɵĻ�������
	EndBatchDraw();
	system("pause");
	closegraph();
	return 0;
}
void Menu()
{
	loadimage(&initbackimage, "Backimage\\initbackimage.jpg", WIDTH, HEIGHT);//���ز˵�ҳ�汳��
	loadimage(&start, "Signal\\start.jpg", 300, 200);//���ؿ�ʼ��ťͼƬ
	putimage(0, 0, &initbackimage);
	putimage(250, 350, &start);
	mciSendString("open backmusic.mp3 alias music", 0, 0, 0);//�������ļ�
	//mciSendString("play music repeat", 0, 0, 0);//��������
	if (mouseX> 250 && mouseX<550 && mouseY>350 && mouseY < 550)
	{
		if (isMouseDown)
		{
			GamePhase = 1;
			isMouseDown = false;
		}
	}

}
void StartPage()
{
	memset(array2D, 0, sizeof(array2D));
	loadimage(&picture[0], "Bubble\\1.jpg", B_WIDTH, B_HEIGHT);//���غ�ɫ����ͼƬ ���ݴ�С60*60
	loadimage(&picture[1], "Bubble\\2.jpg", B_WIDTH, B_HEIGHT);//������ɫ����ͼƬ ���ݴ�С60*60
	loadimage(&picture[2], "Bubble\\3.jpg", B_WIDTH, B_HEIGHT);//���ػ�ɫ����ͼƬ ���ݴ�С60*60             
	loadimage(&picture[3], "Bubble\\4.jpg", B_WIDTH, B_HEIGHT);//������ɫ����ͼƬ ���ݴ�С60*60	                                  	
	loadimage(&picture[4], "Bubble\\5.jpg", B_WIDTH, B_HEIGHT);//������ɫ����ͼƬ ���ݴ�С60*60                                   					                                   
	loadimage(&picture[5], "Bubble\\6.jpg", B_WIDTH, B_HEIGHT);//��������ǹͼƬ
	loadimage(&picture[6], "Bubble\\7.jpg", B_WIDTH, B_HEIGHT);//���ؿհ�ͼƬ
	loadimage(&scoreimage, "Backimage\\score.jpg", S_WIDTH, S_HEIGHT);//���ؼƷְ�ͼƬ
	loadimage(&Leftbackimage, "Backimage\\Leftbackimage.jpg", LB_WIDTH, HEIGHT);//���ر���ͼƬ
	loadimage(&Rightbackimage, "Backimage\\Rightbackimage.jpg", RB_WIDTH, HEIGHT); // ���ؼǷְ屳��ͼƬ
	putimage(540, 0, &Rightbackimage); // �����Ҳ౳��
	putimage(0, 0, &Leftbackimage);// ������౳��
	putimage(560, 80, &scoreimage);//���ƼƷְ�
	GamePhase = 2;
	outtextxy(560, 160,"0");
	ProduceInitialBubble();
}
void ProduceInitialBubble()
{
	for (i = 0; i < 6; i++)//��ʼ����ά����
	{
		for (j = 0; j < 9; j++)
		{
			array2D[i][j] = rand() % 5 + 1;//�������1~5����ͬ��ɫ������
		}
	}
			array2D[12][cur_position] = 6;//��ʼ����ǹ��λ��
			thisBubble = rand() % 5 + 1;//��ʼ�������ݵķ���
			array2D[11][cur_position] = thisBubble;
		
}
/*void NextBubble()    //���������һ��Ҫ��������
{
	if ( )
	{
		nextBubble = rand() % 5 + 1;
		array2D[11][cur_position] = nextBubble;
	}
}*/
void ShootBubble()
{
		shootingBubble = thisBubble;
		thisBubble = nextBubble;
		int x = 0;
		for (int i = 10; i >= 0; i--)
		{
			array2D[i][cur_position] = shootingBubble;
			x = i;
			array2D[i + 1][cur_position] = 0;	
			if (StopBubble(i, cur_position) == 1) 
				break;
			Sleep(80);
		}
		RemoveBubble(x, cur_position);
		RiseBubble();		//�����������
		if (count >= 9)
			ProduceNewBubble();
}
	//��ײ���
int StopBubble(int x, int y)
{

	if (array2D[x - 1][y] != 0)                  //ֱ����
	{
		return 1;
	}
	return 0;
}
void RemoveBubble(int x, int y) 
{
	//�ݹ�����
	number = 0;
	rmBob(x, y);
	if (number <= 2)
	{
		for (i = 0; i < 11; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (array2D[i][j] == -1)
				{
					array2D[i][j] = shootingBubble;
				}
			}
		}
	}
	else
		Score(number);
	
	//printMap();
}
void rmBob(int x, int y) 
{
	//���ƥ��
	if (array2D[x][y] == shootingBubble)
	{
		number++;
		count = number;
		array2D[x][y] = -1;
		if (x > 0) {
			rmBob(x - 1, y);
		}
		if (x < 10) {
			rmBob(x + 1, y);
		}
		if (y > 0) {
			rmBob(x, y - 1);
		}
		if (y < 8) {
			rmBob(x, y + 1);
		}
	}
}
void RiseBubble()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (array2D[i][j])
			{
				if (judge_valid_area(i, j))
				{
					while (i > 0 && !array2D[i - 1][j])
					{
						array2D[i - 1][j] = array2D[i][j];
						array2D[i][j] = 0;
						i--;
					}
				}
				
			}
		}
	}
}
bool judge_valid_area(int x, int y)
{
	//û�������ռ���
	if (x == 0)
		return false;
	//���������
	else if (y == 0)
	{
		//�Ҳࡢ�ϲ಻����
		if (!array2D[x - 1][y] && !array2D[x][y + 1])
			return true;
		else
			return false;
	}
	//���Ҳ�����
	else if (y == 8)
	{
		//��ࡢ�ϲ಻����
		if (!array2D[x - 1][y] && !array2D[x][y - 1])
			return true;
		else
			return false;
	}
	
	//�м����������
	else
	{
		//��ࡢ�ϲࡢ�Ҳ಻����
		if (!array2D[x - 1][y] && !array2D[x][y + 1] && !array2D[x][y - 1])
			return true;
		else
			return false;
	}
}

void ProduceNewBubble()
{
	if (count >= 9)
	{
		for (i = 10; i>0; i--)
		{
			for (j = 0; j<9; j++)
			
			array2D[i+1][j] = array2D[i][j];
		}			         //ÿһ�������ƶ�������һ�����¿ռ�

	}
	for (i = 0; i<9; i++)
	{
		array2D[0][i] = rand() % 5;  //��һ�е�ÿһ���������ֵ
	}
	count = 0;
}
void Score(int n)
{
	char str[20]="";
	score += n * score_per_Bubble;
	printf("%d,", score);
	sprintf(str, "%d", score);
	outtextxy(560, 160, str);

}
void Manager()
{
	if (GamePhase == 2)	//��Ϸ�׶�
	{
		
		
		char key = 0;
		int flag1 = 0, flag2 = 0;
		if (_kbhit())
		{

			key = _getch();
			switch (key)
			{
			case 97://a
				if (cur_position > 0)
				{
					array2D[12][cur_position] = 0;	//����ǹ�ĵ�ǰλ��
					array2D[11][cur_position] = 0;	//����ǹ�ϵ�����λ��
					pre_position = cur_position;
					cur_position--;
					flag1 = 1;
				}
				break;
			case 100://d
				if (cur_position < 8)
				{
					array2D[12][cur_position] = 0;
					array2D[11][cur_position] = 0;
					pre_position = cur_position;
					cur_position++;
					flag1 = 1;
				}
				break;
			case 119://w
				/*for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 9; j++)
						printf("%d ", array2D[i][j]);
					printf("\n");
				}
				printf("\n");*/

				nextBubble = rand() % 5 + 1;
				array2D[11][cur_position] = nextBubble;
				flag2 = 0;
				ShootBubble();
				flag1 = 1;
				break;
			default:
				break;
			}
			if (flag1 == 1)
			{
				array2D[12][cur_position] = 6;
				array2D[11][cur_position] = thisBubble;
				flag1 = 0;
			}
		}

		int end_sen = 0;
		for (int i = 0; i < 9; i++)
		{
			int consistant = 1;
			for (int j = 0; j <= 10; j++)
			{
				if (!array2D[j][i])
					consistant = 0;
			}
			if (consistant)
			{
				end_sen = 1;
				break;
			}
		}
		if (end_sen)
		{
			GamePhase = 3;
		}
			
	}
}
void PutImage()//���ݶ�ά��������ݻ�������ͼƬ
{
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 9; j++)
		{
			x = j * 60;
			y = i * 60;
			switch (array2D[i][j])
			{
			case -1:
				putimage(x, y, &picture[6]);
				array2D[i][j] = 0;
			case 0:  
				if (pre_position != cur_position)
				{
					putimage(pre_position * 60,12*60, &picture[6]);
					putimage(pre_position * 60, 11 * 60, &picture[6]);
				}
				break;
			case 1:putimage(x, y, &picture[0]);//1�����ɫ����
				break;
			case 2:putimage(x, y, &picture[1]);//2������ɫ����
				break;
			case 3:putimage(x, y, &picture[2]);//3�����ɫ����
				break;
			case 4:putimage(x, y, &picture[3]);//4������ɫ����
				break;
			case 5:putimage(x, y, &picture[4]);//5������ɫ����
				break;
			case 6:putimage(x, y, &picture[5]);//6��������ǹ
				break;
			default:
				break;
			}
		}
	}
	/*if (pre_position != cur_position)
	{
		putimage(12, pre_position, &picture[6]);
	}*/

}
void Gameover()
{
	for (i = 0; i<9; i++)
	{
		if (array2D[10][i] != 0)
			GamePhase = 3;
	}
}
void Draw()
{
	switch (GamePhase)//��Ϸ�׶� 0��������׶� 1����ʼ�׶� 2������Ϸ�׶� 3��������׶�
	{
	case 0:	Menu();		break;
	case 1:	StartPage();break;
	case 2:	PutImage();	break;
	case 3:	EndPage();	break;
	}
}
void EndPage()
{
	loadimage(&end, "Signal\\end.jpg", 250, 280);
	loadimage(&restart, "Signal\\restart.jpg", 250, 280);
	putimage(100, 300, &restart);
	putimage(450, 300, &end);
	if (mouseX > 100 && mouseX < 350 && mouseY>300 && mouseY < 580)
	{
		if (isMouseDown)
		{
			GamePhase = 1;	//restart
			isMouseDown = false;
		}
	}
	else if (mouseX > 450 && mouseX < 700 && mouseY>300 && mouseY < 580)
	{
		if (isMouseDown)
		{
			GamePhase = 0;	//end
			isMouseDown = false;
		}
	}
	else
		isMouseDown = false;

	
}