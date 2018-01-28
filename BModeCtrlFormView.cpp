// BModeCtrlFormView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UltrasoundBiopsy.h"
#include "BModeCtrlFormView.h"


// CBModeCtrlFormView

IMPLEMENT_DYNCREATE(CBModeCtrlFormView, CFormView)

CBModeCtrlFormView::CBModeCtrlFormView()
	: CFormView(CBModeCtrlFormView::IDD)
{

}

CBModeCtrlFormView::~CBModeCtrlFormView()
{
}
/*
int CBModeCtrlFormView::Create()
{
	this->cre
	return 0;
}
*/
int CBModeCtrlFormView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
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

void CBModeCtrlFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBModeCtrlFormView, CFormView)
	ON_BN_CLICKED(IDC_Test_BUTTON, &CBModeCtrlFormView::OnBnClickedTestButton)
	ON_BN_CLICKED(IDC_TestFormViewBUTTON, &CBModeCtrlFormView::OnBnClickedTestformviewbutton)
END_MESSAGE_MAP()


// CBModeCtrlFormView ���

#ifdef _DEBUG
void CBModeCtrlFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBModeCtrlFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBModeCtrlFormView ��Ϣ�������


BOOL CBModeCtrlFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CBModeCtrlFormView::OnBnClickedTestButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("BModeCtrl:Hello World!"));
	CClientDC mClientDC(this->GetParent()->GetActiveWindow()); 
	mClientDC.SetTextColor(RGB(255,0,0)); 
	CString strTime; 
    strTime = CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S"));  
	mClientDC.TextOutW(700,300,strTime); 



}


void CBModeCtrlFormView::OnBnClickedTestformviewbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("BModeCtrl:Hello World!"));
	CClientDC mClientDC(this->GetParent()->GetActiveWindow()); 
	mClientDC.SetTextColor(RGB(255,0,0)); 
	CString strTime; 
    strTime = CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S"));  
	mClientDC.TextOutW(700,300,strTime); 

}
