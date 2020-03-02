#pragma once



#include "Fancy World.h"



// ��ͼ��
class CIMAGE
{
public:
	CIMAGE()  {}
	~CIMAGE() {}

	static void PutImage(IMAGE * dstimg, int x, int y, IMAGE * srcimg);	// ͸����ͼ	����ͼ������ͼλ�ã�ͼƬ����
	static void RotateImage(IMAGE* pTo, IMAGE* pFrom, double rad);		// ͼƬ��ת	����ͼƬ��ԭͼƬ����ת���Ļ��ȣ�
};



// ������
class CTitle3D
{
public:
	CTitle3D()  {}
	~CTitle3D() {}

	void settitlexy(int x, int y);												// ���ñ�������	���������꣩
	void setstrstyle(LOGFONT font);												// ����������ʽ ��������ʽ�ṹ�������
	void setstrcolor(COLORREF textcolor, COLORREF bkcolor);						// ����������ɫ ��������ɫ��3D�����ɫ��
	void drawtitle3d(LPCTSTR title_text, bool title_3d = false, int thick = 0);	// ���� 3D ����	��������֣��Ƿ����3D��ʽ��

private:
	int x, y;						// ��������
	COLORREF textcolor, bkcolor;	// ������ɫ��3D�����ɫ
};



// ��ť��
class CButton
{
public:
	CButton()  {}
	~CButton() {}

	void setkeyrespond(wchar_t ch);																		// ������Ӧ����	����Ӧ������
	void setstrstyle(LOGFONT font);																		// ����������ʽ	��������ʽ�ṹ�������
	void setbuttonstyle(int x, int y, int spacing_width, int spacing_height);							// ���ð�ť��ʽ	����ť���꣬���ֺͰ�ť�ļ�ࣩ
	void setbuttoncolor(COLORREF bkcolor, COLORREF respondcolor, COLORREF textcolor);					// ���ð�ť��ɫ	����ť��ɫ����Ӧ��ɫ��������ɫ��
	bool drawbutton(MOUSEMSG& m_msg, LPCTSTR button_text, bool key_respond = false, wchar_t ch = 'a');	// ���ư�ť		�������Ϣ��������֣��Ƿ���Ӧ������Ϣ��������Ϣ��

private:
	wchar_t ch;												// ��Ӧ����
	COLORREF bkcolor, respondcolor, textcolor;				// ��ť��ɫ����Ӧ��ɫ��������ɫ
	int x, y, width, height, spacing_width, spacing_height;	// ��ť���꣬��ť��С�����ֺͰ�ť�ļ��
};



// ��ʼ������
class CAdventrue
{
public:
	CAdventrue()  {}
	~CAdventrue() {}

	virtual void game();						// ��ʼ�������

private:
	void getmsg(wchar_t & ch, MOUSEMSG & msg);	// ��ȡ���̡������Ϣ	��������Ϣ�������Ϣ��

	void buildbk();								// ���Ʊ���
	void buildtitle();							// ���Ʊ���
	void buildcloud();							// ������
};