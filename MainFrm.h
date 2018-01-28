
// ��Ȩ����(C) Maxenmed  Corporation
// ��������Ȩ����

// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "FileView.h"
#include "ClassView.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"
#include "UIDialog\LogoCover.h" 
#include "UIDialog\InitianlizingText.h"
#include "MyPrivateStatusBar.h"
#include "BModeCtrlBox.h"

#define WM_MYMSG WM_USER+8

class CMainFrame : public CFrameWndEx
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
public:
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	//CMyPrivateStatusBar m_wndStatusBar;
	CFileView         m_wndFileView;
	CClassView        m_wndClassView;
	COutputWnd        m_wndOutput;
	CPropertiesWnd    m_wndProperties;
	//----------------------------------------
	CProgressCtrl   m_Progress;
	CBModeCtrlBox mBModeAdustCtrlBox;
	CBModeCtrlBox* pMModeAdustCtrlBox;
	CDockablePane* m_pTabbedBar;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	//------------------------------------------------------------
	BOOL USGDeviceStateID;
	BOOL USGImagingRunModeID;
	BOOL USGFreezingID;
	afx_msg void OnUSGDeviceStateChange(UINT id);
	afx_msg void OnUpdateUSGDeviceStateChangUI(CCmdUI* pCmdUI);


	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
public:
	afx_msg void OnShowpropertywindow32771();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg LRESULT MyMsgHandler(WPARAM,LPARAM);
	afx_msg LRESULT OnMyProcessMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
};


