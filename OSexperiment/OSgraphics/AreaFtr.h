// AreaFtr.h: interface for the CAreaFtr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREAFTR_H__86F48787_F682_49C8_A9A6_CDF0CFD32054__INCLUDED_)
#define AFX_AREAFTR_H__86F48787_F682_49C8_A9A6_CDF0CFD32054__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Feature.h"

class CAreaFtr : public CFeature  
{
public:
	CAreaFtr();
	CAreaFtr(COLORREF colorPen, short LineWide, short LineType,COLORREF colorFill,short Filltype,BOOL bFill)
		:CFeature(colorPen, LineWide, LineType)
	{
		m_colorFill = colorFill;
		m_FillType = Filltype;
		m_bFill = bFill;
	}
	virtual ~CAreaFtr();
	
protected:
	COLORREF m_colorFill;	//fill color
	short m_FillType;			//��䱳��ͼ��������˵���񱳾���ѩ��������
	BOOL m_bFill;				//��ʾ�Ƿ���䣬

public:
	virtual void Draw(CDC *pDC)=0;
	void SetColorFill(COLORREF colorFill);		//�޸������ɫ

};

#endif // !defined(AFX_AREAFTR_H__86F48787_F682_49C8_A9A6_CDF0CFD32054__INCLUDED_)
