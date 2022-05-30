#include "pch.h"
#include "StaticBackground.h"

//CStaticBackground

//동적으로 Cobject를 상속받은 클래스의 필요성이 발생했다.
IMPLEMENT_DYNAMIC(CStaticBackground, CStatic);

CStaticBackground::CStaticBackground()
{
	m_plmage = NULL;
	m_pPen_black = ::new Pen(Color(255, 0, 0), 2);
	m_bDrawLine = FALSE;
	m_bReleaseImage = TRUE;

}

CStaticBackground::~CStaticBackground()
{
	ReleaseInfo();
}

BEGIN_MESSAGE_MAP(CStaticBackground, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

//CStaticBackground 메시지 처리기입니다.


void CStaticBackground::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.

	if (m_plmage)
	{
		GetClientRect(m_rc);
		Graphics gr(dc.GetSafeHdc());
		Bitmap bitmap(m_rc.right, m_rc.bottom);
		Graphics memG(&bitmap);

		gr.DrawImage(m_plmage, 0, 0, m_rc.right, m_rc.bottom);
		if (m_bDrawLine)
			gr.DrawRectangle(m_pPen_black, 0, 0, m_rc.right, m_rc.bottom);

		CachedBitmap chched(&bitmap, &gr);
		gr.DrawCachedBitmap(&chched, 0, 0);
	}
}

void CStaticBackground::ReleaseInfo()
{
	if (m_bReleaseImage && m_plmage) {
		::delete m_plmage;
		m_plmage = NULL;
	}
	if (m_pPen_black)
	{
		::delete m_pPen_black;
		m_pPen_black = NULL;
	}
}


