

// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "UltrasoundBiopsy.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_RIBBON_OpenDevice, ID_RIBBON_SaveImaging, &CMainFrame::OnUSGDeviceStateChange)
	ON_UPDATE_COMMAND_UI_RANGE(ID_RIBBON_OpenDevice, ID_RIBBON_SaveImaging, &CMainFrame::OnUpdateUSGDeviceStateChangUI)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_WM_SETTINGCHANGE()
	ON_COMMAND(ID_ShowPropertyWindow_32771, &CMainFrame::OnShowpropertywindow32771)
	ON_WM_TIMER()
	ON_MESSAGE(WM_MYMSG,OnMyProcessMessage)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_VS_2008);
	pMModeAdustCtrlBox=new CBModeCtrlBox(2);
	USGDeviceStateID=FALSE;
	USGImagingRunModeID=FALSE;;
	USGFreezingID=FALSE;;
}

CMainFrame::~CMainFrame()
{
	delete pMModeAdustCtrlBox;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	//----------------------------------------------
	LogoCover* pLogoCover=new LogoCover(this);
	InitianlizingText* pInitianlizingText=new InitianlizingText(this);
	pLogoCover->Create(LogoCover::IDD,this);
	pInitianlizingText->Create(InitianlizingText::IDD,this);
	pLogoCover->ShowWindow(SW_SHOW);
	int  nFullWidth=GetSystemMetrics(SM_CXSCREEN); 
    int  nFullHeight=GetSystemMetrics(SM_CYSCREEN); 
	int XPostion=(nFullWidth-462)/2;
	int YPostion=nFullHeight-143-60;
	pInitianlizingText->SetWindowPos(NULL,XPostion,YPostion,462,143,SWP_NOZORDER); 
	pInitianlizingText->ShowWindow(SW_SHOW);
	pLogoCover->UpdateWindow();
	pInitianlizingText->UpdateWindow();
	Sleep(1000);
	//---------------------------------------------------------------------------------------------------------------------
	BOOL bNameValid;
	// 基于持久值设置视觉管理器和样式
	OnApplicationLook(theApp.m_nAppLook);
	//---创建 Ribbon----------------------------
	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	CString SoftVersionTitlePane1;
	CString BeamformerStateTitlePane2;
	//-----------------------
	CString ScanModeTitlePane3;
	CString PositionInforTitlePane4;
	CString DtaeTimeTitlePane5;
	CString ProcessingTitlePane6;

	CString CustomerTitlePane7;
	CString UserTitlePane8;

	bNameValid = SoftVersionTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = BeamformerStateTitlePane2.LoadString(IDS_STATUS_PANE2);
	
	ASSERT(bNameValid);
	//-----------------------
	bNameValid = ScanModeTitlePane3.LoadString(IDS_STATUS_PANE3);
	ASSERT(bNameValid);
	bNameValid = PositionInforTitlePane4.LoadString(IDS_STATUS_PANE4);
	PositionInforTitlePane4=" (x=000,y=000) (R=000 G=000 B=000)     ";
	ASSERT(bNameValid);
	bNameValid = DtaeTimeTitlePane5.LoadString(IDS_STATUS_PANE5);
	ASSERT(bNameValid);
	DtaeTimeTitlePane5="0000-00-00-00-00:00:00 ";
	bNameValid = ProcessingTitlePane6.LoadString(IDS_STATUS_PANE6);
	ProcessingTitlePane6=" 进度...............................";
	ASSERT(bNameValid);

	CustomerTitlePane7=" 北京天坛医院.麻醉科";
	UserTitlePane8=" 刘大师";
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, SoftVersionTitlePane1, TRUE), SoftVersionTitlePane1);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, BeamformerStateTitlePane2, TRUE), BeamformerStateTitlePane2);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE3, ScanModeTitlePane3, TRUE), ScanModeTitlePane3);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE4, PositionInforTitlePane4, TRUE), PositionInforTitlePane4);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE5, DtaeTimeTitlePane5, TRUE), DtaeTimeTitlePane5);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE6, ProcessingTitlePane6, TRUE), ProcessingTitlePane6);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE7, CustomerTitlePane7, TRUE), CustomerTitlePane7);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE8, UserTitlePane8, TRUE), UserTitlePane8);
	//m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, BeamformerStateTitlePane2, TRUE), BeamformerStateTitlePane2);
	CRect mProgressRect;
	CMFCRibbonBaseElement * pElement;  
	pElement = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE5); 
	mProgressRect=pElement->GetRect();

    m_Progress.Create(WS_CHILD | WS_VISIBLE,mProgressRect,&m_wndStatusBar,1088); 
	m_Progress.SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);  
	m_Progress.SetPos(0); 
		
	//---------------------------------------------------------------------------------------------------------------------------
	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 加载菜单项图像(不在任何标准工具栏上):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);
	//-------My SELF ---------------------------------------------------------------------------------------------------------------
	if(!mBModeAdustCtrlBox.Create(L"BModeCtrlBox",this,CRect(0,0,300,300),true,ID_BModeCtrlBox_View,WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create dock window\n");
		return FALSE;
	}
   //pMModeAdustCtrlBox
	if(!pMModeAdustCtrlBox->Create(L"MModeCtrlBox",this,CRect(0,0,300,300),true,ID_MModeCtrlBox_View,WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create dock window\n");
		return FALSE;
	}



	// 创建停靠窗口
	if (!CreateDockingWindows())
	{
		TRACE0("未能创建停靠窗口\n");
		return -1;
	}
	mBModeAdustCtrlBox.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&mBModeAdustCtrlBox);

	pMModeAdustCtrlBox->EnableDocking(CBRS_ALIGN_ANY); 
	DockPane(pMModeAdustCtrlBox);
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	m_wndFileView.EnableDocking(CBRS_ALIGN_ANY);
	m_wndClassView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndFileView);
	CDockablePane* pTabbedBar = NULL;
	m_wndClassView.AttachToTabWnd(&m_wndFileView, DM_SHOW, TRUE, &pTabbedBar);

	mBModeAdustCtrlBox.AttachToTabWnd(pTabbedBar, DM_SHOW, TRUE, &pTabbedBar);
	pMModeAdustCtrlBox->AttachToTabWnd(pTabbedBar, DM_SHOW, TRUE, &pTabbedBar);
	//pMModeAdustCtrlBox->AttachToTabWnd(&mBModeAdustCtrlBox, DM_SHOW, TRUE, &pTabbedBar);

	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndOutput);
	m_wndProperties.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndProperties);
	//pMModeAdustCtrlBox->AttachToTabWnd(&m_wndProperties, DM_SHOW, TRUE, &pTabbedBar);
	//pMModeAdustCtrlBox->DockToWindow(&m_wndProperties, CBRS_ALIGN_BOTTOM);

	//--Clear Resource----------------------------------------------------------------
	pLogoCover->DestroyWindow(); //CANCEL START SREEN;
	pInitianlizingText->DestroyWindow();
	delete pLogoCover;
	delete pInitianlizingText;

	SetTimer(1, 1000, NULL); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZE;

	return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;

	// 创建类视图
	CString strClassView;
	bNameValid = strClassView.LoadString(IDS_CLASS_VIEW);
	ASSERT(bNameValid);
	if (!m_wndClassView.Create(strClassView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_CLASSVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建“类视图”窗口\n");
		return FALSE; // 未能创建
	}

	// 创建文件视图
	CString strFileView;
	bNameValid = strFileView.LoadString(IDS_FILE_VIEW);
	ASSERT(bNameValid);
	if (!m_wndFileView.Create(strFileView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_FILEVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建“文件视图”窗口\n");
		return FALSE; // 未能创建
	}

	//----------------------------------------------------------------------------------------------------------------------------
	/*
	CString strBModeCtrlView;
	bNameValid = strBModeCtrlView.LoadString(IDS_BModeCtrl_VIEW);
	ASSERT(bNameValid);
	//mBModeAdustCtrlBar.Create(this,IDD_BModeAdjust_DIALOG,WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI,IDD_BModeAdjust_DIALOG); 
	mBModeAdustCtrlBar.CreateEx(CreateEx(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI,strBModeCtrlView, 
			if (!mBModeAdustCtrlBar.CreateEx((strBModeCtrlView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_FILEVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建“B模式控制箱”窗口\n");
		return FALSE; // 未能创建
	}
	*/
	// 创建输出窗口
	CString strOutputWnd;
	bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
	ASSERT(bNameValid);
	if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建输出窗口\n");
		return FALSE; // 未能创建
	}

	// 创建属性窗口
	CString strPropertiesWnd;
	bNameValid = strPropertiesWnd.LoadString(IDS_PROPERTIES_WND);
	ASSERT(bNameValid);
	if (!m_wndProperties.Create(strPropertiesWnd, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_PROPERTIESWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建“属性”窗口\n");
		return FALSE; // 未能创建
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
	HICON hFileViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_FILE_VIEW_HC : IDI_FILE_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndFileView.SetIcon(hFileViewIcon, FALSE);

	HICON hClassViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_CLASS_VIEW_HC : IDI_CLASS_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndClassView.SetIcon(hClassViewIcon, FALSE);

	HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

	HICON hPropertiesBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_PROPERTIES_WND_HC : IDI_PROPERTIES_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndProperties.SetIcon(hPropertiesBarIcon, FALSE);

}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}
//---------------------------------
void CMainFrame::OnUSGDeviceStateChange(UINT id)
{
	switch (id)
	{
	case ID_RIBBON_OpenDevice:
		USGDeviceStateID=TRUE;
		break;

	case ID_RIBBON_ColseDevice:
		USGDeviceStateID=FALSE;
		break;

	case ID_RIBBON_StartImaging:
		USGImagingRunModeID=TRUE;
		USGImagingRunModeID=TRUE;
		break;

	case ID_RIBBON_ColseImaging:
		USGImagingRunModeID=FALSE;
		break;
    case ID_RIBBON_FreezeImaging:
		USGFreezingID==TRUE;
		break;
   case ID_RIBBON_SaveImaging:
		
		break;

	}


}

void CMainFrame::OnUpdateUSGDeviceStateChangUI(CCmdUI* pCmdUI)
{
	
	switch (pCmdUI->m_nID)
	{
	case ID_RIBBON_OpenDevice:
		pCmdUI->Enable(!USGDeviceStateID);
		break;

	case ID_RIBBON_ColseDevice:
		pCmdUI->Enable(USGDeviceStateID);
		break;
	case ID_RIBBON_StartImaging:
		pCmdUI->Enable(USGDeviceStateID);
		break;
	case ID_RIBBON_ColseImaging:
		pCmdUI->Enable(USGImagingRunModeID);
		break;
	case ID_RIBBON_FreezeImaging:
		pCmdUI->Enable(USGImagingRunModeID);
		break;
    case ID_RIBBON_SaveImaging:
		pCmdUI->Enable(USGFreezingID);
		break;
	}
}

void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CFrameWndEx::OnSettingChange(uFlags, lpszSection);
	m_wndOutput.UpdateFonts();
}


void CMainFrame::OnShowpropertywindow32771()
{
	// TODO: 在此添加命令处理程序代码
	//if（m_wndProperties.IsVisible()
	m_wndProperties.ShowWindow(m_wndProperties.IsVisible() ? SW_HIDE : SW_SHOW);
	m_wndProperties.UpdateWindow();  
	RecalcLayout(FALSE);
	//m_wndProperties.ShowWindow( 


}


void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    CString strTime; 
    CMFCRibbonBaseElement * pElement;  
    strTime = CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S"));  
    pElement = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE5);  
    pElement->SetText(strTime);  
    pElement->Redraw();  
    //-----------------------
	/*
	CRect mProgressRect;
	CMFCRibbonBaseElement * pElement2;  
	pElement2 = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE6); 
	mProgressRect=pElement2->GetRect(); 
	m_Progress.SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);     
	m_Progress.StepIt(); 
	pElement2->Redraw(); 
	*/
	CFrameWndEx::OnTimer(nIDEvent);
}
LRESULT CMainFrame::OnMyProcessMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    CRect mProgressRect;
	CMFCRibbonBaseElement * pElement;  
	pElement = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE6); 
	mProgressRect=pElement->GetRect(); 
	m_Progress.SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);     
	//m_Progress.StepIt(); 
	m_Progress.SetPos(int(wParam)); 
	//pElement->Redraw(); 
	//if(wParam==100)	m_Progress.SetPos(100); 
	//pElement->Redraw(); 
	return 0;
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWndEx::OnPaint()
	CRect mProgressRect;
	CMFCRibbonBaseElement * pElement;  
	pElement = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE6); 
	mProgressRect=pElement->GetRect(); 
	m_Progress.SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);    
	m_Progress.SetPos(0); 
}
