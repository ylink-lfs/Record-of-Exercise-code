#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
/////////////////////以下是 宏定义参数/////////////////////
#define WIDTH				800					//屏幕宽度
#define HEIGHT  			780					//屏幕高度
#define B_WIDTH 			60					//泡泡/泡泡枪的宽度
#define B_HEIGHT			60					//泡泡/泡泡枪的高度
#define S_WIDTH				220					//计分板的宽度
#define S_HEIGHT			80					//计分板的高度
#define LB_WIDTH			540					//左侧背景的宽度
#define RB_WIDTH			260					//右侧背景的宽度
#define cur_positioni			12				   //泡泡枪的行数
#define score_per_Bubble	100				   //每个泡泡的分数
////////////////////以下是 全局变量////////////////////
IMAGE picture[7];																	//创建泡泡图像对象
IMAGE initbackimage, scoreimage, Leftbackimage, Rightbackimage;						//创建背景图像对象
IMAGE start,restart, end;															//创建图标图像对象
int array2D[13][9];				//定义一个二维数组
int i;							//数组的行数
int j;							//数组的列数
int cur_position=4;					//泡泡枪当前的位置（列数）
int pre_position = 4;				//泡泡枪之前的位置（列数）
//int bobCount = 0;				//连通泡泡计数
int thisBubble = 0;				//这个泡泡
int nextBubble = 0;				//下一个泡泡
int shootingBubble = 0;			//发射中的泡泡
int GamePhase = 0;				//游戏阶段 （0代表载入阶段 1代表开始阶段 2代表游戏阶段 3代表结束阶段）
int mouseX;						//鼠标位置坐标X
int mouseY;						//鼠标位置坐标Y
bool isMouseDown;				//鼠标按下
int number=0;					//泡泡消除个数
int count=0;					//记录总的泡泡消除个数
int score=0;					//分数

/////////////////////以下是 函数声明/////////////////////
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
	//置随机数种子
	srand((unsigned)time(NULL));
	//初始化设备，加载图片
	initgraph(WIDTH, HEIGHT,SHOWCONSOLE);
	//开启缓冲,防止闪屏
	BeginBatchDraw();
	// 鼠标消息变量
	MOUSEMSG mmsg;
	while (true)
	{
		//处理鼠标消息
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
		//逻辑处理
		Manager();
		//绘图处理
		Draw();
		//显示缓存的绘制内容6

		FlushBatchDraw();
	}

	//结束批量绘制，并执行未完成的绘制任务
	EndBatchDraw();
	system("pause");
	closegraph();
	return 0;
}
void Menu()
{
	loadimage(&initbackimage, "Backimage\\initbackimage.jpg", WIDTH, HEIGHT);//加载菜单页面背景
	loadimage(&start, "Signal\\start.jpg", 300, 200);//加载开始按钮图片
	putimage(0, 0, &initbackimage);
	putimage(250, 350, &start);
	mciSendString("open backmusic.mp3 alias music", 0, 0, 0);//打开音乐文件
	//mciSendString("play music repeat", 0, 0, 0);//播放音乐
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
	loadimage(&picture[0], "Bubble\\1.jpg", B_WIDTH, B_HEIGHT);//加载黑色泡泡图片 泡泡大小60*60
	loadimage(&picture[1], "Bubble\\2.jpg", B_WIDTH, B_HEIGHT);//加载蓝色泡泡图片 泡泡大小60*60
	loadimage(&picture[2], "Bubble\\3.jpg", B_WIDTH, B_HEIGHT);//加载黄色泡泡图片 泡泡大小60*60             
	loadimage(&picture[3], "Bubble\\4.jpg", B_WIDTH, B_HEIGHT);//加载紫色泡泡图片 泡泡大小60*60	                                  	
	loadimage(&picture[4], "Bubble\\5.jpg", B_WIDTH, B_HEIGHT);//加载绿色泡泡图片 泡泡大小60*60                                   					                                   
	loadimage(&picture[5], "Bubble\\6.jpg", B_WIDTH, B_HEIGHT);//加载泡泡枪图片
	loadimage(&picture[6], "Bubble\\7.jpg", B_WIDTH, B_HEIGHT);//加载空白图片
	loadimage(&scoreimage, "Backimage\\score.jpg", S_WIDTH, S_HEIGHT);//加载计分板图片
	loadimage(&Leftbackimage, "Backimage\\Leftbackimage.jpg", LB_WIDTH, HEIGHT);//加载背景图片
	loadimage(&Rightbackimage, "Backimage\\Rightbackimage.jpg", RB_WIDTH, HEIGHT); // 加载记分板背景图片
	putimage(540, 0, &Rightbackimage); // 绘制右侧背景
	putimage(0, 0, &Leftbackimage);// 绘制左侧背景
	putimage(560, 80, &scoreimage);//绘制计分板
	GamePhase = 2;
	outtextxy(560, 160,"0");
	ProduceInitialBubble();
}
void ProduceInitialBubble()
{
	for (i = 0; i < 6; i++)//初始化二维数组
	{
		for (j = 0; j < 9; j++)
		{
			array2D[i][j] = rand() % 5 + 1;//随机分配1~5代表不同颜色的泡泡
		}
	}
			array2D[12][cur_position] = 6;//初始泡泡枪的位置
			thisBubble = rand() % 5 + 1;//初始发射泡泡的分数
			array2D[11][cur_position] = thisBubble;
		
}
/*void NextBubble()    //随机生成下一次要发射泡泡
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
		RiseBubble();		//如果泡泡悬空
		if (count >= 9)
			ProduceNewBubble();
}
	//碰撞检测
int StopBubble(int x, int y)
{

	if (array2D[x - 1][y] != 0)                  //直线上
	{
		return 1;
	}
	return 0;
}
void RemoveBubble(int x, int y) 
{
	//递归消除
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
	//如果匹配
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
	//没有上升空间了
	if (x == 0)
		return false;
	//最左侧泡泡
	else if (y == 0)
	{
		//右侧、上侧不接壤
		if (!array2D[x - 1][y] && !array2D[x][y + 1])
			return true;
		else
			return false;
	}
	//最右侧泡泡
	else if (y == 8)
	{
		//左侧、上侧不接壤
		if (!array2D[x - 1][y] && !array2D[x][y - 1])
			return true;
		else
			return false;
	}
	
	//中间区域的泡泡
	else
	{
		//左侧、上侧、右侧不接壤
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
		}			         //每一行往下移动，给第一行留下空间

	}
	for (i = 0; i<9; i++)
	{
		array2D[0][i] = rand() % 5;  //第一行的每一个随机赋予值
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
	if (GamePhase == 2)	//游戏阶段
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
					array2D[12][cur_position] = 0;	//泡泡枪的当前位置
					array2D[11][cur_position] = 0;	//泡泡枪上的泡泡位置
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
void PutImage()//根据二维数组的内容绘制所有图片
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
			case 1:putimage(x, y, &picture[0]);//1代表黑色泡泡
				break;
			case 2:putimage(x, y, &picture[1]);//2代表蓝色泡泡
				break;
			case 3:putimage(x, y, &picture[2]);//3代表黄色泡泡
				break;
			case 4:putimage(x, y, &picture[3]);//4代表紫色泡泡
				break;
			case 5:putimage(x, y, &picture[4]);//5代表绿色泡泡
				break;
			case 6:putimage(x, y, &picture[5]);//6代表泡泡枪
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
	switch (GamePhase)//游戏阶段 0代表载入阶段 1代表开始阶段 2代表游戏阶段 3代表结束阶段
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