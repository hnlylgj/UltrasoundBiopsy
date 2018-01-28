
// 版权所有(C) Maxenmed  Corporation
// 保留所有权利。

// MainFrm.h : CMainFrame 类的接口
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
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
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
// 生成的消息映射函数
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


