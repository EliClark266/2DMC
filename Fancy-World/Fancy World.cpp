#include "Game.h"



int main()
{
	srand((unsigned int)time(NULL));
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	BeginBatchDraw();

	CAdventrue* beg = new CAdventrue();	// ����ָ��
	beg->game();						// ��ʼ��Ϸ

	EndBatchDraw();
	closegraph();
	return 0;
}