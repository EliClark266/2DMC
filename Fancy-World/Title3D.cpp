#include "Game.h"



// ���ñ�������
void CTitle3D::settitlexy(int x, int y)
{
	this->x = x;
	this->y = y;
}



// ����������ʽ
void CTitle3D::setstrstyle(LOGFONT font)
{
	settextstyle(&font);
}



// ����������ɫ
void CTitle3D::setstrcolor(COLORREF textcolor, COLORREF bkcolor)
{
	this->textcolor = textcolor;
	this->bkcolor   = bkcolor;
}



// ���� 3D ����
void CTitle3D::drawtitle3d(LPCTSTR title_text, bool title_3d, int thick)
{
	if (title_3d)
	{
		for (int i = 1; i <= thick; i++)
		{
			settextcolor(bkcolor);
			outtextxy(x - i, y - i, title_text);
		}
	}

	settextcolor(textcolor);
	outtextxy(x, y, title_text);
}