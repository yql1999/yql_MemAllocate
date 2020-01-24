// Text.cpp: implementation of the CText class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "OSexperiment.h"
#include "Text.h"
#include <math.h>                    // for trigonometry functions


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CText::CText()
{

}

CText::~CText()
{

}
void CText::Draw(CDC *pDC)
{
	CFont cjcf;			//����һ����ģ
	int high,wide,cc1,cc2,cd;
	float angg;
	unsigned char c1,c2;
	float x1,y1,ang1;
	char bz[4];
	const char * ls1;
	pDC ->SetBkColor(TRANSPARENT);
	high = m_TextHeight;
	ang1 = (float)(m_Angle1*pi/180);			//�õ���ע����x������Ļ���
	if (high <3 || high > 200)					//����̫С��̫�󣬽�����ʾ
		return;
	x1 = m_StartX - m_TextHeight * (int)sin(ang1);	//��ע���ĺ�����
	y1 = m_StartY + m_TextHeight * (int)cos(ang1);	//��ע����������
	
	angg = (float) (m_Angle2 * 10);
	wide = m_TextWide;
	cjcf.CreateFont(high,wide,angg,0,50,0,0,0,255,OUT_TT_PRECIS,CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY,FIXED_PITCH,"cjc");			//��������
	CFont * cjcbakf = pDC ->SelectObject(&cjcf);	//ѡ����ģ
	pDC ->SetBkMode(TRANSPARENT);					//���û��Ʒ�ʽ
	pDC ->SetTextColor(m_colorPen);					//���ñ�ע�ı���ɫ
	ls1 = (const char *)c_Text;
	cd = strlen(ls1);
	while(cd > 0)
	{
		c1 = *ls1;
		c2 = *(ls1+1);
		if (c1 > 127 && c2>127)
		{
			strncpy(bz,ls1,2);
			bz[2] = 0;
			ls1 = ls1 +2;
			pDC ->TextOut(x1,y1,bz);
			cd = cd -2;
			//��һ���ַ���ʵ����ʾλ��
			x1 = x1 +(m_TextWide * 2 + m_OffWide) * (float) cos(ang1);
			y1 = y1 +(m_TextWide * 2 + m_OffWide) * (float) sin(ang1);
			

		}
		else			//�����һ�������ַ�
		{
			strncpy(bz,ls1,1);
			bz[1] = 0;
			ls1 ++;
			pDC ->TextOut(x1,y1,bz);
			cd = cd - 1;
			//��һ���ַ���ʵ����ʾλ��
			x1 = x1 +(m_TextWide  + m_OffWide) * (float) cos(ang1);
			y1 = y1 +(m_TextWide  + m_OffWide) * (float) sin(ang1);
		}

	}
	pDC ->SelectObject(cjcbakf);

	
}

