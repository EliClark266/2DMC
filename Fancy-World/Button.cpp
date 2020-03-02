#include "Game.h"



// 设置响应按键
void CButton::setkeyrespond(wchar_t ch)
{
	this->ch = ch;
}



// 设置字体样式
void CButton::setstrstyle(LOGFONT font)
{
	settextstyle(&font);
}



// 设置按钮样式
void CButton::setbuttonstyle(int x, int y, int spacing_width, int spacing_height)
{
	this->x = x;
	this->y = y;
	this->spacing_width  = spacing_width;
	this->spacing_height = spacing_height;
}



// 设置按钮颜色
void CButton::setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor)
{
	this->bkcolor	   = bkcolor;
	this->respondcolor = respondcolor;
	this->textcolor    = textcolor;
}



// 绘制按钮
bool CButton::drawbutton(MOUSEMSG& m_msg, LPCTSTR button_text, bool key_respond, wchar_t ch)
{
	setbkmode(TRANSPARENT);

	setfillcolor(bkcolor);
	int ex = x + textwidth(button_text)  + spacing_width  * 2;
	int ey = y + textheight(button_text) + spacing_height * 2;		// 计算右下角坐标
	solidrectangle(x, y, ex, ey);

	if (m_msg.x > x && m_msg.x < ex && m_msg.y > y && m_msg.y < ey)	// 判断鼠标是否在按钮中
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);

		if (m_msg.uMsg == WM_LBUTTONUP)
		{
			m_msg.uMsg = WM_MOUSEMOVE;
			return true;
		}
	}

	if (key_respond && ch == this->ch)								// 判断是否按下响应键
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);
		return true;
	}

	settextcolor(textcolor);
	outtextxy(x + spacing_width, y + spacing_height, button_text);

	return false;
}