// MModeCtrlFormVIEW.cpp : 实现文件
//

#include "stdafx.h"
#include "UltrasoundBiopsy.h"
#include "MModeCtrlFormVIEW.h"


// CMModeCtrlFormVIEW

IMPLEMENT_DYNCREATE(CMModeCtrlFormVIEW, CFormView)

CMModeCtrlFormVIEW::CMModeCtrlFormVIEW()
	: CFormView(CMModeCtrlFormVIEW::IDD)
{

}

CMModeCtrlFormVIEW::~CMModeCtrlFormVIEW()
{
}

void CMModeCtrlFormVIEW::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMModeCtrlFormVIEW, CFormView)
	ON_BN_CLICKED(IDC_TestMModeCtrlBUTTON, &CMModeCtrlFormVIEW::OnBnClickedTestmmodectrlbutton)
END_MESSAGE_MAP()


// CMModeCtrlFormVIEW 诊断

#ifdef _DEBUG
void CMModeCtrlFormVIEW::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMModeCtrlFormVIEW::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMModeCtrlFormVIEW 消息处理程序


void CMModeCtrlFormVIEW::OnBnClickedTestmmodectrlbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("MModeCtrl:Hello World!"));
	CClientDC mClientDC(this->GetParent()->GetActiveWindow()); 
	mClientDC.SetTextColor(RGB(255,0,0)); 
	CString strTime; 
    strTime = CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S"));  
	mClientDC.TextOutW(700,300,strTime); 
}


BOOL CMModeCtrlFormVIEW::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
int CMModeCtrlFormVIEW::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
		int nResult = 0;
		CFrameWnd* pParentFrame = GetParentFrame();
		if( pParentFrame == pDesktopWnd )
		{
 		 // When this is docked
		 nResult= CFormView::OnMouseActivate(pDesktopWnd, nHitTest, message);
 		}
		else
		{
 		// When this is not docked
 		 BOOL isMiniFrameWnd = pDesktopWnd->IsKindOf( RUNTIME_CLASS( CMiniFrameWnd ) );
		 BOOL isPaneFrameWnd = pDesktopWnd->IsKindOf( RUNTIME_CLASS( CPaneFrameWnd ) );
		 BOOL isMultiPaneFrameWnd = pDesktopWnd->IsKindOf( RUNTIME_CLASS( CMultiPaneFrameWnd ) );
 
		// pDesktopWnd is the frame window for CDockablePane
 		 nResult = CWnd::OnMouseActivate( pDesktopWnd, nHitTest, message );
 
		}
		return nResult;

}