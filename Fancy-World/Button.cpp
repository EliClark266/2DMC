#include "Game.h"



// ������Ӧ����
void CButton::setkeyrespond(wchar_t ch)
{
	this->ch = ch;
}



// ����������ʽ
void CButton::setstrstyle(LOGFONT font)
{
	settextstyle(&font);
}



// ���ð�ť��ʽ
void CButton::setbuttonstyle(int x, int y, int spacing_width, int spacing_height)
{
	this->x = x;
	this->y = y;
	this->spacing_width  = spacing_width;
	this->spacing_height = spacing_height;
}



// ���ð�ť��ɫ
void CButton::setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor)
{
	this->bkcolor	   = bkcolor;
	this->respondcolor = respondcolor;
	this->textcolor    = textcolor;
}



// ���ư�ť
bool CButton::drawbutton(MOUSEMSG& m_msg, LPCTSTR button_text, bool key_respond, wchar_t ch)
{
	setbkmode(TRANSPARENT);

	setfillcolor(bkcolor);
	int ex = x + textwidth(button_text)  + spacing_width  * 2;
	int ey = y + textheight(button_text) + spacing_height * 2;		// �������½�����
	solidrectangle(x, y, ex, ey);

	if (m_msg.x > x && m_msg.x < ex && m_msg.y > y && m_msg.y < ey)	// �ж�����Ƿ��ڰ�ť��
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);

		if (m_msg.uMsg == WM_LBUTTONUP)
		{
			m_msg.uMsg = WM_MOUSEMOVE;
			return true;
		}
	}

	if (key_respond && ch == this->ch)								// �ж��Ƿ�����Ӧ��
	{
		setfillcolor(respondcolor);
		solidrectangle(x, y, ex, ey);
		return true;
	}

	settextcolor(textcolor);
	outtextxy(x + spacing_width, y + spacing_height, button_text);

	return false;
}