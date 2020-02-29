#pragma once
//����XY
#include <graphics.h>
#include "Button.h"
constexpr auto WIN_X = 1000;
constexpr auto WIN_Y = 800;
constexpr auto PlayMessage_X = 300;
constexpr auto PlayMessage_Y = 780;
constexpr auto MainWindow_X = 690;
constexpr auto MainWindow_Y = 780;

MOUSEMSG StartupMsg;
void makeStartupWindow() {
	const wchar_t* NewGame = _T("�½���Ϸ��N��");
	const wchar_t* OpenGame = _T("����Ϸ��O��");
	const wchar_t* News = _T("��Ϸ��Ѷ��P��");
	const wchar_t* ExitGame = _T("�˳���Ϸ��E��");
	CButton StartupWindowButton[4];
	LOGFONT font;
	
	//���ñ�����ɫ
	setbkcolor(RGB(240, 240, 240));
	cleardevice();
	
	//����
	settextcolor(BLACK);
	settextstyle(100, 0, _T("΢���ź�"), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, ANTIALIASED_QUALITY, NULL);
	outtextxy((WIN_X - textwidth(_T("ƽ������"))) / 2, 50, _T("ƽ������"));
	
	//��ť��ʼ��
	for(int i = 0;i < 4;i ++)StartupWindowButton[0].setbuttoncolor(RGB(200, 200, 200),RGB(240, 240, 240),RGB(0,0,0));
	gettextstyle(&font);
	font.lfHeight = 25;
	wcscpy_s(font.lfFaceName, L"΢���ź� Light");
	font.lfQuality = ANTIALIASED_QUALITY;

	//�½���Ϸ��ť
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(NewGame) / 2, WIN_Y / 2 - 10, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, NewGame,true);
	
	//����Ϸ��ť
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(OpenGame) / 2, WIN_Y / 2 - 20, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, OpenGame, true);
	
	//��Ѷ��ť
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(News) / 2, WIN_Y / 2 - 30, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, News, true);

	//�˳���Ϸ��ť
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(ExitGame) / 2, WIN_Y / 2 - 40, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, ExitGame, true);

	//�汾��ť
	settextcolor(WHITE);
	settextstyle(15, 0, L"Verdana");
	outtextxy(25, 450, L"V1.0");

}

void makeWindow() {
	
	setfillcolor(RGB(255, 255, 255));
	setlinecolor(RGB(10, 10, 10));
	//���������Ϣ��
	fillrectangle(10, 10, PlayMessage_X, PlayMessage_Y);
	//�����Ҳ���Ϣ��
	fillrectangle(PlayMessage_X + 10, 10, MainWindow_X + PlayMessage_X, MainWindow_Y);
}

void button(TCHAR text,int x,int y) {
	setlinecolor(RGB(10, 10, 10));
	//������ť
	fillrectangle(x, y, (x + textwidth(text)) / 2, (y + textheight(text)) / 2);
}