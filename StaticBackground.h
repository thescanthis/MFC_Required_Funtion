#pragma once


//CStaticBackground
class CStaticBackground : public CStatic
{
	//CObject클래스로 부터 상속 받은 오브젝트 
	//클래스에 대해 실시간 정보접근을 할 수 있도록 해주는 매크로.
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

