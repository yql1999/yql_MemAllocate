// Cirque.h: interface for the CCirque class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRQUE_H__23423C83_0543_469B_AAB1_EEE0095B03ED__INCLUDED_)
#define AFX_CIRQUE_H__23423C83_0543_469B_AAB1_EEE0095B03ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Circle.h"

class CCirque : public CCircle  
{
public:
	CCirque();
	/*	
	colorFill ��ɫ����Բ���ߵ���ɫ�����ɫ
	LineWidth ��Ե�������
	bFill �Ƿ������ɫ
	CircleX Բ��X����
	CircleY Բ��Y����
	InCircleR ��Բ�뾶
	OutCircleR ��Բ�뾶
	*/
	CCirque(COLORREF  colorFill,
			short LineWidth,
			BOOL bFill,
			short CircleX,short CircleY,
			short InCircleR,short OutCircleR
			)
			:CCircle(colorFill,LineWidth,0,colorFill,0,bFill,	CircleX, CircleY,InCircleR)
	{
		m_OutCircleR=OutCircleR;		
	}
	virtual ~CCirque();
	
protected:
	short m_OutCircleR;	      // ��Ȧ�뾶

	
public:
	void setLine(COLORREF colorPen,short LineWide)  //������ʱ���������ñߵ����ԣ���������ı���һ����
	{
		m_colorPen=colorPen;
		m_LineWide=LineWide;
	}
	virtual void Draw(CDC*pDC);

};

#endif // !defined(AFX_CIRQUE_H__23423C83_0543_469B_AAB1_EEE0095B03ED__INCLUDED_)
