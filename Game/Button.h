#pragma once

#include <graphics.h>
#include <conio.h>



class CButton
{
public:
	void setkeyrespond(wchar_t ch);
	void setstrstyle(LOGFONT font);
	void setbuttonstyle(int x, int y, int spacing_width, int spacing_height);
	void setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor);
	bool drawbutton(MOUSEMSG & m_msg, const wchar_t text[], bool key_respond = false, wchar_t ch = 'a');
private:
	LOGFONT font;
	wchar_t ch, text[1000];
	COLORREF bkcolor, respondcolor, textcolor;
	int x, y, width, height, spacing_width, spacing_height;
};