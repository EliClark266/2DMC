#pragma once
//窗体XY
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
	const wchar_t* NewGame = _T("新建游戏（N）");
	const wchar_t* OpenGame = _T("打开游戏（O）");
	const wchar_t* News = _T("游戏资讯（P）");
	const wchar_t* ExitGame = _T("退出游戏（E）");
	CButton StartupWindowButton[4];
	LOGFONT font;
	
	//设置背景颜色
	setbkcolor(RGB(240, 240, 240));
	cleardevice();
	
	//标题
	settextcolor(BLACK);
	settextstyle(100, 0, _T("微软雅黑"), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, ANTIALIASED_QUALITY, NULL);
	outtextxy((WIN_X - textwidth(_T("平面世界"))) / 2, 50, _T("平面世界"));
	
	//按钮初始化
	for(int i = 0;i < 4;i ++)StartupWindowButton[0].setbuttoncolor(RGB(200, 200, 200),RGB(240, 240, 240),RGB(0,0,0));
	gettextstyle(&font);
	font.lfHeight = 25;
	wcscpy_s(font.lfFaceName, L"微软雅黑 Light");
	font.lfQuality = ANTIALIASED_QUALITY;

	//新建游戏按钮
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(NewGame) / 2, WIN_Y / 2 - 10, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, NewGame,true);
	
	//打开游戏按钮
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(OpenGame) / 2, WIN_Y / 2 - 20, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, OpenGame, true);
	
	//资讯按钮
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(News) / 2, WIN_Y / 2 - 30, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, News, true);

	//退出游戏按钮
	StartupWindowButton[0].setbuttonstyle(WIN_X / 2 - textwidth(ExitGame) / 2, WIN_Y / 2 - 40, 25, 5);
	StartupWindowButton[0].setkeyrespond((wchar_t)"N");
	StartupWindowButton[0].drawbutton(StartupMsg, ExitGame, true);

	//版本按钮
	settextcolor(WHITE);
	settextstyle(15, 0, L"Verdana");
	outtextxy(25, 450, L"V1.0");

}

void makeWindow() {
	
	setfillcolor(RGB(255, 255, 255));
	setlinecolor(RGB(10, 10, 10));
	//创建左侧信息栏
	fillrectangle(10, 10, PlayMessage_X, PlayMessage_Y);
	//创建右侧信息栏
	fillrectangle(PlayMessage_X + 10, 10, MainWindow_X + PlayMessage_X, MainWindow_Y);
}

void button(TCHAR text,int x,int y) {
	setlinecolor(RGB(10, 10, 10));
	//创建按钮
	fillrectangle(x, y, (x + textwidth(text)) / 2, (y + textheight(text)) / 2);
}