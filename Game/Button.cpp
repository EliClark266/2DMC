#include "Button.h"



void CButton::setkeyrespond(wchar_t ch)
{
	this->ch = ch;
}



void CButton::setstrstyle(LOGFONT font)
{
	this->font = font;
}



void CButton::setbuttonstyle(int x, int y, int spacing_width, int spacing_height)
{
	this->x = x;
	this->y = y;
	this->spacing_width = spacing_width;
	this->spacing_height = spacing_height;
}



void CButton::setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor)
{
	this->bkcolor = bkcolor;
	this->respondcolor = respondcolor;
	this->textcolor = textcolor;
}



bool CButton::drawbutton(MOUSEMSG& m_msg, LPCTSTR text, bool key_respond, wchar_t ch)
{
	settextstyle(&font);
	setbkmode(TRANSPARENT);

	setfillcolor(bkcolor);
	int ex = x + textwidth(text) + spacing_width * 2;
	int ey = y + textheight(text) + spacing_height * 2;
	solidrectangle(x, y, ex, ey);

	if (m_msg.x > x&& m_msg.x < ex && m_msg.y > y&& m_msg.y < ey)
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);

		if (m_msg.uMsg == WM_LBUTTONUP)
		{
			m_msg.uMsg = WM_MOUSEMOVE;
			return 1;
		}
	}

	if (key_respond && ch == this->ch)
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);
		return 1;
	}

	settextcolor(textcolor);
	outtextxy(x + spacing_width, y + spacing_height, text);

	return 0;
}

