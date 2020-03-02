#include "Game.h"



int main()
{
	srand((unsigned int)time(NULL));
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	BeginBatchDraw();

	CAdventrue* beg = new CAdventrue();	// 创建指针
	beg->game();						// 开始游戏

	EndBatchDraw();
	closegraph();
	return 0;
}