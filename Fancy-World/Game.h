#pragma once



#include "Fancy World.h"



// 贴图类
class CIMAGE
{
public:
	CIMAGE()  {}
	~CIMAGE() {}

	static void PutImage(IMAGE * dstimg, int x, int y, IMAGE * srcimg);	// 透明贴图	（贴图对象，贴图位置，图片对象）
	static void RotateImage(IMAGE* pTo, IMAGE* pFrom, double rad);		// 图片旋转	（新图片，原图片，旋转过的弧度）
};



// 标题类
class CTitle3D
{
public:
	CTitle3D()  {}
	~CTitle3D() {}

	void settitlexy(int x, int y);												// 设置标题坐标	（标题坐标）
	void setstrstyle(LOGFONT font);												// 设置字体样式 （字体样式结构体变量）
	void setstrcolor(COLORREF textcolor, COLORREF bkcolor);						// 设置字体颜色 （标题颜色，3D标题底色）
	void drawtitle3d(LPCTSTR title_text, bool title_3d = false, int thick = 0);	// 绘制 3D 标题	（输出文字，是否绘制3D样式）

private:
	int x, y;						// 标题坐标
	COLORREF textcolor, bkcolor;	// 标题颜色，3D标题底色
};



// 按钮类
class CButton
{
public:
	CButton()  {}
	~CButton() {}

	void setkeyrespond(wchar_t ch);																		// 设置响应按键	（响应按键）
	void setstrstyle(LOGFONT font);																		// 设置字体样式	（字体样式结构体变量）
	void setbuttonstyle(int x, int y, int spacing_width, int spacing_height);							// 设置按钮样式	（按钮坐标，文字和按钮的间距）
	void setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor);					// 设置按钮颜色	（按钮底色，响应颜色，文字颜色）
	bool drawbutton(MOUSEMSG& m_msg, LPCTSTR button_text, bool key_respond = false, wchar_t ch = 'a');	// 绘制按钮		（鼠标消息，输出文字，是否响应键盘消息，按键消息）

private:
	wchar_t ch;												// 响应按键
	COLORREF bkcolor, respondcolor, textcolor;				// 按钮底色，响应颜色，文字颜色
	int x, y, width, height, spacing_width, spacing_height;	// 按钮坐标，按钮大小，文字和按钮的间距
};



// 初始界面类
class CAdventrue
{
public:
	CAdventrue()  {}
	~CAdventrue() {}

	virtual void game();						// 初始界面核心

private:
	void getmsg(wchar_t & ch, MOUSEMSG & msg);	// 获取键盘、鼠标消息	（键盘消息，鼠标消息）

	void buildbk();								// 绘制背景
	void buildtitle();							// 绘制标题
	void buildcloud();							// 绘制云
};