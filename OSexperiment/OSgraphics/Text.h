// Text.h: interface for the CText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXT_H__ACE670F8_DEFD_4154_9336_E9906CCFCBDF__INCLUDED_)
#define AFX_TEXT_H__ACE670F8_DEFD_4154_9336_E9906CCFCBDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined pi
#define pi 3.1415926535
#endif

#include "Feature.h"

class CText : public CFeature  
{
protected:
	int m_StartX;					//��ע�ı���������
	int m_StartY;					//��ע�ı����������
	float m_Angle1;					//��ע�Ƕ�
	float m_Angle2;					//������ת�Ƕ�
	int m_TextHeight;				//����߶�
	int m_TextWide;					//������
	int m_OffWide;					//�����ע���
	unsigned char m_TextFont;		//����
	CString c_Text;					//��ע�ı�����
	int m_TextLong;					//��ע�ı����ַ����� 
	

public:
	CText();
	virtual ~CText();
	CText(COLORREF ColorPen,short LineWide,short LineType,int StartX,int StartY,float Angle1,float Angle2,int TextHeight,
		int TextWide,int OffWide,CString Text)
		:CFeature (ColorPen,LineWide,LineType)
	{
		m_StartX = StartX;
		m_StartY = StartY;
		m_Angle1 = Angle1;
		m_Angle2 = Angle2;
		m_TextHeight = TextHeight;
		m_TextWide = TextWide;
		m_OffWide = OffWide;
		m_TextLong = Text.GetLength();		//�����ַ��ĳ���
		c_Text = Text;
	}
public:
	virtual void Draw(CDC *pDC);

};

#endif // !defined(AFX_TEXT_H__ACE670F8_DEFD_4154_9336_E9906CCFCBDF__INCLUDED_)
