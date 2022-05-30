#pragma once


//CStaticBackground
class CStaticBackground : public CStatic
{
	//CObjectŬ������ ���� ��� ���� ������Ʈ 
	//Ŭ������ ���� �ǽð� ���������� �� �� �ֵ��� ���ִ� ��ũ��.
	DECLARE_DYNAMIC(CStaticBackground);

public:
	CStaticBackground();
	~CStaticBackground();

protected:
	DECLARE_MESSAGE_MAP()

public:
	CRect m_rc;
	Pen* m_pPen_black;
	Image* m_plmage;
	BOOL m_bDrawLine;
	BOOL m_bReleaseImage;

	void ReleaseInfo();
	afx_msg void OnPaint();
};

