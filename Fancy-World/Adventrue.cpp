#include "Game.h"	// ��Ϸ��ͷ�ļ�



// ��ʼ�������
void CAdventrue::game()
{
	wchar_t ch = '#';
	MOUSEMSG msg;

	CButton* but = new CButton();
	but->setbuttoncolor(RGB(100, 100, 100),
						RGB(150, 150, 150),
						RGB(255, 255, 255));
	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = BUTTON_HEIGHT;
	wcscpy_s(font.lfFaceName, L"΢���ź� Light");
	font.lfQuality = ANTIALIASED_QUALITY;			// ����������ʽ

	while (1)
	{
		getmsg(ch, msg);		// ��ȡ��Ϣ

		buildbk();				// ���Ʊ���

		buildtitle();			// ���Ʊ���

		but->setstrstyle(font);	// ����������ʽ

		// ���ư�ť
		but->setbuttonstyle(WIN_WIDTH  / 2 - textwidth(CREATE_WORLD)  / 2 - BUTTON_SPACING_WIDTH,
						    WIN_HEIGHT / 2 - textheight(CREATE_WORLD) / 2 - BUTTON_SPACING_HEIGHT,
						    BUTTON_SPACING_WIDTH, BUTTON_SPACING_HEIGHT);
		if (but->drawbutton(msg, CREATE_WORLD)) {}

		but->setbuttonstyle(WIN_WIDTH  / 2 - textwidth(OPEN_WORLD)  / 2 - BUTTON_SPACING_WIDTH,
						    WIN_HEIGHT / 2 - textheight(OPEN_WORLD) / 2 - BUTTON_SPACING_HEIGHT + BUTTON_SPACING,
						    BUTTON_SPACING_WIDTH, BUTTON_SPACING_HEIGHT);
		if (but->drawbutton(msg, OPEN_WORLD)) {}

		but->setbuttonstyle(WIN_WIDTH  / 2 - textwidth(EXIT_GAME)  / 2 - BUTTON_SPACING_WIDTH,
						    WIN_HEIGHT / 2 - textheight(EXIT_GAME) / 2 - BUTTON_SPACING_HEIGHT + BUTTON_SPACING * 2,
						    BUTTON_SPACING_WIDTH, BUTTON_SPACING_HEIGHT);
		if (but->drawbutton(msg, EXIT_GAME))
			break;

		but->setbuttonstyle(WIN_WIDTH  / 2 - textwidth(GAME_HELP)  / 2 - BUTTON_SPACING_WIDTH,
						    WIN_HEIGHT / 2 - textheight(GAME_HELP) / 2 - BUTTON_SPACING_HEIGHT + BUTTON_SPACING * 3,
						    BUTTON_SPACING_WIDTH, BUTTON_SPACING_HEIGHT);
		if (but->drawbutton(msg, GAME_HELP)) {}
		// ���ư�ť

		settextcolor(BLACK);
		settextstyle(25, 0, L"Verdana");
		outtextxy(25, WIN_HEIGHT - 50, VERSION_INFO);	// ���ư汾��Ϣ

		buildcloud();

		FlushBatchDraw();
	}

	delete but;
	but = NULL;
}



// ��ȡ���̡������Ϣ
void CAdventrue::getmsg(wchar_t & ch, MOUSEMSG & msg)
{
	if (_kbhit())
		ch = _getch();

	if (MouseHit())
		msg = GetMouseMsg();
}



// ���Ʊ���
void CAdventrue::buildbk()
{
	setbkcolor(RGB(96, 146, 231));
	cleardevice();
}



// ���Ʊ���
void CAdventrue::buildtitle()
{
	IMAGE* png = new IMAGE();
	loadimage(png, TITLE_ADDR);
	CIMAGE::PutImage(NULL, WIN_WIDTH  / 2 - png->getwidth()  / 2, 
						  (WIN_HEIGHT / 2 - textheight(CREATE_WORLD) / 2 - BUTTON_SPACING_HEIGHT) / 2
						 - png->getheight() / 2, png);
	delete png;
	png = NULL;
}



// ������
void CAdventrue::buildcloud()
{
	static int x[7], y[7], v[7] = { 0, 0, 0, 0, 0, 0, 0 };
	IMAGE* png = new IMAGE();
	loadimage(png, CLOUD_ADDR);
	if (v[0] == 0)
	{
		for (int j = 0; j < 7; j++)
		{
			x[j] = rand() % WIN_WIDTH - png->getwidth();
			y[j] = rand() % 590 + 1;
			v[j] = rand() % 3 + 1;
		}
	}
	else
	{
		for (int j = 0; j < 7; j++)
		{
			x[j] += v[j];
			if (x[j] > WIN_WIDTH)
			{
				x[j] = -png->getwidth();
				y[j] = rand() % (WIN_HEIGHT - png->getheight()) + 1;
				v[j] = rand() % 3 + 1;
			}
		}
	}
	for (int i = 0; i < 7; i++)
		CIMAGE::PutImage(NULL, x[i], y[i], png);
	delete png;
	png = NULL;
}