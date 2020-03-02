#include "Game.h"



// Í¸Ã÷ÌùÍ¼
void CIMAGE::PutImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	DWORD * dst = GetImageBuffer(dstimg);
	DWORD * src = GetImageBuffer(srcimg);

	int src_width  = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width  = (dstimg == NULL ? getwidth()  : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	int iwidth  = (x + src_width  > dst_width)  ? dst_width  - x : src_width;
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;

	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }
	dst += dst_width * y + x;

	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);
			int sg = ((src[ix] & 0xff00) >> 8);
			int sb =   src[ix] & 0xff;
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db =   dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
					| ((sg + dg * (255 - sa) / 255) << 8)
					|  (sb + db * (255 - sa) / 255);
		}

		dst += dst_width;
		src += src_width;
	}
}



// Í¼Æ¬Ðý×ª
void CIMAGE::RotateImage(IMAGE * pTo, IMAGE * pFrom, double rad)
{
	IMAGE* pWorking = GetWorkingImage();
	SetWorkingImage(pFrom);
	int iWidth = getwidth();
	int iHeight = getheight();

	while (rad > 2 * PI)
		rad -= 2 * PI;

	double pad = rad;
	if (pad > PI / 2 && pad <= PI)
	{
		pad -= PI / 2;
		pad = PI / 2 - pad;
	}
	else if (pad > PI && pad <= PI / 2 * 3)
	{
		pad -= PI;
	}
	else if (pad > PI / 2 * 3 && pad <= PI * 2)
	{
		pad -= PI / 2 * 3;
		pad = PI / 2 - pad;
	}

	int	tWidth = int(iWidth * cos(pad) + iHeight * sin(pad));
	int	tHeight = int(iHeight * cos(pad) + iWidth * sin(pad));

	int iMinX = -(iWidth / 2), iMinY = -(iHeight / 2);
	int iMaxX = iMinX + iWidth, iMaxY = iMinY + iHeight;

	int tMinX = -(tWidth / 2), tMinY = -(tHeight / 2);
	int tMaxX = tMinX + tWidth, tMaxY = tMinY + tHeight;

	setorigin(-iMinX, -iMinY);

	SetWorkingImage(NULL);
	pTo->Resize(tWidth, tHeight);

	DWORD* dst = GetImageBuffer(pTo);
	DWORD* src = GetImageBuffer(pFrom);

	SetWorkingImage(pTo);
	for (int y1 = 0; y1 < tHeight; y1++)
	{
		for (int x1 = 0; x1 < tWidth; x1++)
			dst[x1] = 0x00000000;
		dst += tWidth;
	}
	SetWorkingImage(pWorking);
	for (int y1 = 0; y1 < tHeight; y1++)
		dst -= tWidth;

	for (int y1 = tMinY; y1 < tMaxY; y1++)
	{
		for (int x1 = tMinX; x1 < tMaxX; x1++)
		{
			int x = int(x1 * cos(rad) - y1 * sin(rad));
			int y = int(x1 * sin(rad) + y1 * cos(rad));

			int sxy = (iHeight - (y - iMinY) - 1) * iWidth + (x - iMinX);
			int dxy = (tHeight - (y1 - tMinY) - 1) * tWidth + (x1 - tMinX);

			if (x >= iMinX && x < iMaxX && y >= iMinY && y < iMaxY)
				dst[dxy] = src[sxy];
		}
	}

	SetWorkingImage(pFrom);
	setorigin(0, 0);
	SetWorkingImage(pWorking);
}