

// UltrasoundBiopsyView.cpp : CUltrasoundBiopsyView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UltrasoundBiopsy.h"
#endif
#include "MainFrm.h"
#include "UltrasoundBiopsyDoc.h"
#include "UltrasoundBiopsyView.h"
#include "UIDialog\WaitingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUltrasoundBiopsyView

IMPLEMENT_DYNCREATE(CUltrasoundBiopsyView, CView)

BEGIN_MESSAGE_MAP(CUltrasoundBiopsyView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_COMMAND_RANGE(ID_ShowPropertyWindow_32771, (UINT)ID_ShowLeftToolWindow_Menu,ID_ShowRibbonWindow_32776,ID_ShowOutputWindow_32773,ID_ShowStatusWindow_32789, &CUltrasoundBiopsyView::OnAppMainVieChange)
	//ON_UPDATE_COMMAND_UI_RANGE(ID_ShowPropertyWindow_32771, ID_ShowLeftToolWindow_Menu,ID_ShowRibbonWindow_32776,ID_ShowOutputWindow_32773,ID_ShowStatusWindow_32789, &CUltrasoundBiopsyView::OnUpdateApplicationViewUI)

	ON_COMMAND(ID_ShowPropertyWindow_32771, &CUltrasoundBiopsyView::OnShowpropertywindow32771)
	ON_COMMAND(ID_ShowLeftToolWindow_Menu, &CUltrasoundBiopsyView::OnShowlefttoolwindowMenu)
	ON_COMMAND(ID_ShowRibbonWindow_32776, &CUltrasoundBiopsyView::OnShowribbonwindow32776)
	ON_COMMAND(ID_ShowOutputWindow_32773, &CUltrasoundBiopsyView::OnShowoutputwindow32773)
	ON_COMMAND(ID_ShowStatusWindow_32789, &CUltrasoundBiopsyView::OnShowstatuswindow32789)
	
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_MininSystem_32792, &CUltrasoundBiopsyView::OnMininsystem32792)
	ON_COMMAND(ID_CloseMainApp_32779, &CUltrasoundBiopsyView::OnClosemainapp32779)
	ON_COMMAND(ID_ColseDevice_32795, &CUltrasoundBiopsyView::OnColsedevice32795)
	ON_COMMAND(ID_OpenDevice_32794, &CUltrasoundBiopsyView::OnOpendevice32794)
	ON_COMMAND(ID_StartImageing_32797, &CUltrasoundBiopsyView::OnStartimageing32797)
	ON_COMMAND(ID_ColseImaging_32798, &CUltrasoundBiopsyView::OnColseimaging32798)
	ON_COMMAND(ID_FreezeImaging_32799, &CUltrasoundBiopsyView::OnFreezeimaging32799)
	ON_COMMAND(ID_SaveImaging_32800, &CUltrasoundBiopsyView::OnSaveimaging32800)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_AutoHideRibbon_32834, &CUltrasoundBiopsyView::OnAutohideribbon32834)
	ON_UPDATE_COMMAND_UI(ID_ShowRibbonWindow_32776, &CUltrasoundBiopsyView::OnUpdateShowribbonwindow32776)
	ON_UPDATE_COMMAND_UI(ID_AutoHideRibbon_32834, &CUltrasoundBiopsyView::OnUpdateAutohideribbon32834)
	ON_UPDATE_COMMAND_UI(ID_ShowStatusWindow_32789, &CUltrasoundBiopsyView::OnUpdateShowstatuswindow32789)
	ON_UPDATE_COMMAND_UI(ID_ShowOutputWindow_32773, &CUltrasoundBiopsyView::OnUpdateShowoutputwindow32773)
	ON_UPDATE_COMMAND_UI(ID_ShowPropertyWindow_32771, &CUltrasoundBiopsyView::OnUpdateShowpropertywindow32771)
	ON_UPDATE_COMMAND_UI(ID_ShowLeftToolWindow_Menu, &CUltrasoundBiopsyView::OnUpdateShowlefttoolwindowMenu)
	ON_UPDATE_COMMAND_UI(ID_OpenDevice_32794, &CUltrasoundBiopsyView::OnUpdateOpendevice32794)
	ON_UPDATE_COMMAND_UI(ID_ColseDevice_32795, &CUltrasoundBiopsyView::OnUpdateColsedevice32795)
	ON_UPDATE_COMMAND_UI(ID_ColseImaging_32798, &CUltrasoundBiopsyView::OnUpdateColseimaging32798)
	ON_UPDATE_COMMAND_UI(ID_FreezeImaging_32799, &CUltrasoundBiopsyView::OnUpdateFreezeimaging32799)
	ON_UPDATE_COMMAND_UI(ID_SaveImaging_32800, &CUltrasoundBiopsyView::OnUpdateSaveimaging32800)
	ON_UPDATE_COMMAND_UI(ID_StartImageing_32797, &CUltrasoundBiopsyView::OnUpdateStartimageing32797)
	ON_BN_CLICKED(IDC_Test_BUTTON, &CUltrasoundBiopsyView::OnBnClickedTestButton)
END_MESSAGE_MAP()

// CUltrasoundBiopsyView 构造/析构

CUltrasoundBiopsyView::CUltrasoundBiopsyView()
{
	// TODO: 在此处添加构造代码
	 m_ViewBackgroundColor=RGB(49,69,100);//象牙黑41,36,33
	 DetectMouseMoveID=0;
	 AutohideribbonID=FALSE;
}

CUltrasoundBiopsyView::~CUltrasoundBiopsyView()
{
}

BOOL CUltrasoundBiopsyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.lpszClass=AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,0,(HBRUSH)::GetStockObject(m_ViewBackgroundColor),0);//这里默认为白色画刷 WHITE_BRUSH ,现在修改为m_ViewBackgroundColor
	return CView::PreCreateWindow(cs);
}

// CUltrasoundBiopsyView 绘制

void CUltrasoundBiopsyView::OnDraw(CDC* /*pDC*/)
{
	CUltrasoundBiopsyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CUltrasoundBiopsyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUltrasoundBiopsyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// CUltrasoundBiopsyView 诊断

#ifdef _DEBUG
void CUltrasoundBiopsyView::AssertValid() const
{
	CView::AssertValid();
}

void CUltrasoundBiopsyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUltrasoundBiopsyDoc* CUltrasoundBiopsyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUltrasoundBiopsyDoc)));
	return (CUltrasoundBiopsyDoc*)m_pDocument;
}
#endif //_DEBUG

// CUltrasoundBiopsyView 消息处理程序


void CUltrasoundBiopsyView::OnShowpropertywindow32771()
{
	// TODO: 在此添加命令处理程序代码
	//CMainFrame* pFrame = (CMainFrame*)(AfxGetApp->m_pMainWnd); 
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndProperties.ShowWindow(pMainFrame->m_wndProperties.IsVisible() ? SW_HIDE : SW_SHOW);
	pMainFrame->m_wndProperties.ShowPane(!(pMainFrame->m_wndProperties.IsVisible()), FALSE, TRUE);
	//pMainFrame->m_wndProperties.UpdateWindow();  
	//pMainFrame->RecalcLayout(FALSE);
}

void CUltrasoundBiopsyView::OnShowlefttoolwindowMenu()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pMainFrame->m_wndFileView.ShowPane(!(pMainFrame->m_wndFileView.IsVisible()), FALSE, TRUE);
	pMainFrame->m_wndClassView.ShowPane(!(pMainFrame->m_wndClassView.IsVisible()), FALSE, TRUE);
	pMainFrame->pMModeAdustCtrlBox->ShowPane(!(pMainFrame->pMModeAdustCtrlBox->IsVisible()), FALSE, TRUE);
	pMainFrame->mBModeAdustCtrlBox.ShowPane(!(pMainFrame->mBModeAdustCtrlBox.IsVisible()), FALSE, TRUE);
	//CDockablePane* pTabbedBar = NULL;
	//pMainFrame->m_wndClassView.AttachToTabWnd(&(pMainFrame->m_wndFileView), DM_SHOW, TRUE, &pTabbedBar);
	//pTabbedBar->ShowWindow(1); 
	//pMainFrame->m_wndFileView.ShowWindow(pMainFrame->m_wndFileView.IsVisible() ? SW_HIDE : SW_SHOW);
	//pMainFrame->m_wndClassView.ShowWindow(pMainFrame->m_wndClassView.IsVisible() ? SW_HIDE : SW_SHOW);
	//pMainFrame->RecalcLayout(FALSE);
}

void CUltrasoundBiopsyView::OnShowribbonwindow32776()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndRibbonBar.ShowWindow(pMainFrame->m_wndRibbonBar.IsVisible() ? SW_HIDE : SW_SHOW);
	//pMainFrame->RecalcLayout(FALSE);
	pMainFrame->m_wndRibbonBar.ShowPane(!(pMainFrame->m_wndRibbonBar.IsVisible()), FALSE, TRUE);

}

void CUltrasoundBiopsyView::OnShowoutputwindow32773()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndOutput.ShowWindow(pMainFrame->m_wndOutput.IsVisible() ? SW_HIDE : SW_SHOW);
	//pMainFrame->RecalcLayout(FALSE);
	pMainFrame->m_wndOutput.ShowPane(!(pMainFrame->m_wndOutput.IsVisible()), FALSE, TRUE);
	
}

/*
void CUltrasoundBiopsyView::OnShowapptitlewindow32778()
{
	// TODO: 在此添加命令处理程序代码m_MainButton
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pMainFrame->m_MainButton.SetVisible(pMainFrame->m_MainButton.IsVisible() ? SW_HIDE : SW_SHOW);
	pMainFrame->RecalcLayout(FALSE);
}
*/

void CUltrasoundBiopsyView::OnShowstatuswindow32789()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndStatusBar.ShowWindow(pMainFrame->m_wndStatusBar.IsVisible() ? SW_HIDE : SW_SHOW);
	//pMainFrame->RecalcLayout(FALSE);
	pMainFrame->m_wndStatusBar.ShowPane(!(pMainFrame->m_wndStatusBar.IsVisible()), FALSE, TRUE);
}

BOOL CUltrasoundBiopsyView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect mClientRect;   
	GetClientRect(&mClientRect);   
	CBrush  mBrush;   
	mBrush.CreateSolidBrush(m_ViewBackgroundColor);   
	pDC->FillRect(&mClientRect,&mBrush);  
	return CView::OnEraseBkgnd(pDC);
}

void CUltrasoundBiopsyView::OnMininsystem32792()
{
	// TODO: 在此添加命令处理程序代码
	AfxGetMainWnd()->SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);//窗口中发送最小化消息

}

void CUltrasoundBiopsyView::OnClosemainapp32779()
{
	// TODO: 在此添加命令处理程序代码
	if(AfxMessageBox(L"是否真的要退出当前系统？",MB_YESNO)==IDYES)
      AfxGetMainWnd()->SendMessage(WM_CLOSE);

}

void CUltrasoundBiopsyView::OnOpendevice32794()
{
	// TODO: 在此添加命令处理程序代码
	if(theApp.mPUSGFW2ForMX==NULL)
	{
		
		WaitingDlg* pWaitingDlg=new WaitingDlg(this);
		pWaitingDlg->Create(WaitingDlg::IDD,this);
		pWaitingDlg->mWaitingTextString="正在打开设备，请稍等..."; 
		pWaitingDlg->ShowWindow(SW_SHOW);
		pWaitingDlg->UpdateWindow();
	    pWaitingDlg->UpdateData(0);
		/*
		CProgressCtrl*   pProcessProgress=new CProgressCtrl();
		CRect mProgressRect;
		mProgressRect.SetRect(700,500,50,20);
		pProcessProgress->Create(WS_CHILD | WS_VISIBLE,mProgressRect,this->GetActiveWindow(),1089); 
		pProcessProgress->SetRange(0,10);
		pProcessProgress->SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);   
		pProcessProgress->ShowWindow(SW_SHOW);
		pProcessProgress->UpdateWindow();
	    pProcessProgress->SetPos(1); 
		Sleep(200);
		  pProcessProgress->SetPos(2); 
		Sleep(200);
		 pProcessProgress->SetPos(3); 
		 Sleep(200);
		 pProcessProgress->SetPos(4); 
			Sleep(200);
		 pProcessProgress->SetPos(10); 
		 pProcessProgress->DestroyWindow();
		 delete pProcessProgress;
		 */
		/*
		CRect mProgressRect;
	    CMFCRibbonBaseElement * pElement;  
		CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
     	pElement = pMainFrame->m_wndStatusBar.FindElement(ID_STATUSBAR_PANE6); 
	    mProgressRect=pElement->GetRect(); 
	    pMainFrame->m_Progress.SetWindowPos(NULL,mProgressRect.left,mProgressRect.top,mProgressRect.Width(),mProgressRect.Height(),SWP_NOZORDER);     
	    pMainFrame->m_Progress.StepIt(); 
	    pElement->Redraw(); 

		 pMainFrame->m_Progress.StepIt(); 
	    pElement->Redraw(); 

		 pMainFrame->m_Progress.StepIt(); 
	     pElement->Redraw(); 
		 */
		AfxGetMainWnd()->SendMessage(WM_MYMSG, 10,0);//窗口中发送最小化消息
		// Sleep(1000);
		// AfxGetMainWnd()->SendMessage(WM_MYMSG, 20,0);//窗口中发送消息
		//  Sleep(1000);
		// AfxGetMainWnd()->SendMessage(WM_MYMSG, 30,0);//窗口中发送消息

		theApp.mPUSGFW2ForMX=new CUSGFW2ForMX;
	    if(theApp.mPUSGFW2ForMX->ConnectToDevice())
		{
		  //GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(L"Connect to Beamformer Success!");
          //pTestResultBoxOne->SetWindowText(L"Connect to Beamformer Success!/r/n");
			/*
          CString ResultStr;
		  mCurrentTimer=CTime::GetCurrentTime();
		  int h = mCurrentTimer.GetHour();
		  int m = mCurrentTimer.GetMinute();
		  int s = mCurrentTimer.GetSecond();
          ResultStr.Format(L"%d:%d:%d Connect to Beamformer Success",h,m,s);
		  ResultStr=ResultStr+L"\r\n";
		  ReturnResultstr= ReturnResultstr+ResultStr;
		  pTestResultBoxOne->SetWindowText(ReturnResultstr);
		  
		  //EnableDisableUserInterfaceControls(1);
		  mConnectDeviceBtn.EnableWindow(0);
	      mDisconnectDeviceBtn.EnableWindow(1);
	      mStartGeneratorBtn.EnableWindow(1);
	      mGetProbsBtn.EnableWindow(1);
		  */

        }
	    else 
		{
            
			//GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(L"Connect to Beamformer Failse！");
			 //pTestResultBoxOne->SetWindowText(L"Connect to Beamformer Failse!/r/n");
			/*
			 CString ResultStr;
		     mCurrentTimer=CTime::GetCurrentTime();
		     int h = mCurrentTimer.GetHour();
		     int m = mCurrentTimer.GetMinute();
		     int s = mCurrentTimer.GetSecond();
             ResultStr.Format(L"%d:%d:%d Connect to Beamformer Failse!",h,m,s);
		     ResultStr=ResultStr+L"\r\n";
			 pTestResultBoxOne->GetWindowText(ReturnResultstr); 
		     ReturnResultstr= ReturnResultstr+ResultStr;
		     pTestResultBoxOne->SetWindowText(ReturnResultstr);
			 */
		}
	    
		 Sleep(1000);
		 AfxGetMainWnd()->SendMessage(WM_MYMSG, 40,0);//窗口中发送消息
		 Sleep(1000);
		 AfxGetMainWnd()->SendMessage(WM_MYMSG, 60,0);//窗口中发送消息
		 //Sleep(2000);
		 //AfxGetMainWnd()->SendMessage(WM_MYMSG, 80,0);//窗口中发送消息
		  Sleep(800);
		 AfxGetMainWnd()->SendMessage(WM_MYMSG, 100,0);//窗口中发送消息
		 Sleep(200);
		 AfxGetMainWnd()->SendMessage(WM_MYMSG, 0,0);//窗口中发送消息

		pWaitingDlg->DestroyWindow(); //CANCEL Wait SCREEN;
		delete pWaitingDlg;



	}
		
	
}

void CUltrasoundBiopsyView::OnColsedevice32795()
{
	// TODO: 在此添加命令处理程序代码
	theApp.mPUSGFW2ForMX->DisconnectToDevice(); 
	delete theApp.mPUSGFW2ForMX; 
	theApp.mPUSGFW2ForMX=NULL;
	Invalidate();//重绘窗口命令！
	/*
	//Invalidate();//重绘窗口命令！
	//GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(L"Disconnect to Beamformer Success！");
	//pTestResultBoxOne->SetWindowText(L"Disconnect to Beamformer Success!/r/n");
	CString ResultStr;
	mCurrentTimer=CTime::GetCurrentTime();
	int h = mCurrentTimer.GetHour();
	int m = mCurrentTimer.GetMinute();
	int s = mCurrentTimer.GetSecond();
    ResultStr.Format(L"%d:%d:%d Disconnect to Beamformer Success",h,m,s);
	ResultStr=ResultStr+L"\r\n";
	pTestResultBoxOne->GetWindowText(ReturnResultstr); 
	ReturnResultstr= ReturnResultstr+ResultStr;
	pTestResultBoxOne->SetWindowText(ReturnResultstr);
	EnableDisableUserInterfaceControls(0);
	mConnectDeviceBtn.EnableWindow(1);
	*/
}

void CUltrasoundBiopsyView::OnStartimageing32797()
{
	// TODO: 在此添加命令处理程序代码
	CString ReturnResultstr;
	if(theApp.mPUSGFW2ForMX->USGDeviceStatus!=1)
	{
       //GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(L"Device may not be Connected！");
		//----
		//----
	   return;
	}
	theApp.mPUSGFW2ForMX->LogicScanModeID=(SCAN_MODE)1;//mModeSelectCombox.GetCurSel()--B Mode ;
	///*
	LONG nFullWidth=(LONG)GetSystemMetrics(SM_CXSCREEN);     
    LONG nFullHeight=(LONG)GetSystemMetrics(SM_CYSCREEN);  
	LONG mUSGViewWidth=512;//683;//512;//914;
	LONG mUSGViewHeight=512;//512;//588;//521
	CRect ScreeRect;
	GetWindowRect(&ScreeRect);
	//CRect mClientRect;
    //GetClientRect(mClientRect);
	//LONG mWidth=(LONG)mClientRect.Width();
	//LONG mHight=(LONG)mClientRect.Height();
	tagRECT mOutputRectangle ;
    mOutputRectangle.left=(nFullWidth-mUSGViewWidth-ScreeRect.left-10)/2;
	mOutputRectangle.top=(nFullHeight-mUSGViewHeight-ScreeRect.top-10)/2;
	mOutputRectangle.right=mOutputRectangle.left+mUSGViewWidth;
	mOutputRectangle.bottom=mOutputRectangle.top+mUSGViewHeight; 
	theApp.mPUSGFW2ForMX->pRECT=&mOutputRectangle;
	
	//------------------------------------------
	WaitingDlg* pWaitingDlg=new WaitingDlg(this);
	pWaitingDlg->Create(WaitingDlg::IDD,this);
	pWaitingDlg->mWaitingTextString="正在生成图像，请稍等..."; 
	pWaitingDlg->ShowWindow(SW_SHOW);
	pWaitingDlg->UpdateWindow();
	pWaitingDlg->UpdateData(0);
	if(theApp.mPUSGFW2ForMX->StartUSGGenerator(this->GetSafeHwnd()))
	{
		/*
		//ReturnResultstr.Format(L"%d [Start B_Mode Scaning Generator Success！]",mPUSGFW2ForMX->ReturnResultValue);
		//GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(ReturnResultstr);
		CString ResultStr;
		mCurrentTimer=CTime::GetCurrentTime();
		int h = mCurrentTimer.GetHour();
		int m = mCurrentTimer.GetMinute();
		int s = mCurrentTimer.GetSecond();
        ResultStr.Format(L"%d:%d:%d %d[Start B_Mode Generator Success]",h,m,s,mPUSGFW2ForMX->ReturnResultValue);
		ResultStr=ResultStr+L"\r\n";
		pTestResultBoxOne->GetWindowText(ReturnResultstr); 
		ReturnResultstr= ReturnResultstr+ResultStr;
		pTestResultBoxOne->SetWindowText(ReturnResultstr);
		InitializeUserInterfaceControls();
	    EnableDisableUserInterfaceControls(1);
		mConnectDeviceBtn.EnableWindow(0);
		mStartGeneratorBtn.EnableWindow(0);
	    mSaveFileBtn.EnableWindow(0);
	    mRunViewBtn.EnableWindow(0);
		//-----------------------------------------------
		ImageEnhancementUpdateGUI();
	    ClearViewUpdateGUI();
	    FocusUpdateGUI();
		//------------------------------------------------
		*/
		theApp.mPUSGFW2ForMX->pDrawImage->UpdateAlphaBitmap();  
		DetectMouseMoveID=1;
		//pAutoAdjustment=new AutoAdjustment();
		//pAutoAdjustment->pUSGFW2ForMX=theApp.mPUSGFW2ForMX; 
		

	}
	else
	{
		//-------------------------------------------------
		theApp.mPUSGFW2ForMX->CloseUSGGenerator(); 
		/*
		//ReturnResultstr.Format(L"%d [Start B_Mode Scaning Generator False！]",mPUSGFW2ForMX->ReturnResultValue);
		//GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(ReturnResultstr);
		CString ResultStr;
		mCurrentTimer=CTime::GetCurrentTime();
		int h = mCurrentTimer.GetHour();
		int m = mCurrentTimer.GetMinute();
		int s = mCurrentTimer.GetSecond();
        ResultStr.Format(L"%d:%d:%d %d[Start B_Mode Generator False]",h,m,s,mPUSGFW2ForMX->ReturnResultValue);
		ResultStr=ResultStr+L"\r\n";
		pTestResultBoxOne->GetWindowText(ReturnResultstr); 
		ReturnResultstr= ReturnResultstr+ResultStr;
		pTestResultBoxOne->SetWindowText(ReturnResultstr);
		*/
			
	}
	pWaitingDlg->DestroyWindow(); 
	delete pWaitingDlg;
	return;
}

void CUltrasoundBiopsyView::OnColseimaging32798()
{
	// TODO: 在此添加命令处理程序代码
	theApp.mPUSGFW2ForMX->CloseUSGGenerator(); 
	Invalidate();//重绘窗口命令！
}

void CUltrasoundBiopsyView::OnFreezeimaging32799()
{
	// TODO: 在此添加命令处理程序代码
	theApp.mPUSGFW2ForMX->FreezeImage(); 
	/*
	//GetDlgItem(IDC_Return_Result_EDIT)->SetWindowText(L"Freeze Scaning Image Success！");
	CString ResultStr;
	mCurrentTimer=CTime::GetCurrentTime();
	int h = mCurrentTimer.GetHour();
	int m = mCurrentTimer.GetMinute();
	int s = mCurrentTimer.GetSecond();
    ResultStr.Format(L"%d:%d:%d Freeze Scaning Image Success",h,m,s);
	ResultStr=ResultStr+L"\r\n";
	pTestResultBoxOne->GetWindowText(ReturnResultstr); 
	ReturnResultstr= ReturnResultstr+ResultStr;
	pTestResultBoxOne->SetWindowText(ReturnResultstr);
	EnableDisableUserInterfaceControls(0);
	mRunViewBtn.EnableWindow(1);
	mConnectDeviceBtn.EnableWindow(0);
	mDisconnectDeviceBtn.EnableWindow(1);
	mStartGeneratorBtn.EnableWindow(0);
	mCloseGeneratorBtn.EnableWindow(1);
	mSaveFileBtn.EnableWindow(1);

	mEnableEnhanceCheck.EnableWindow(1);;
	mEnableSpeckleCheck.EnableWindow(1);;
	//mScaningDirectionCheck.EnableWindow(1);
	mViewRotateSlider.EnableWindow(1);
	mViewRotateCombox.EnableWindow(1);
	mRejectionCombox.EnableWindow(1);
	mRejectionSlider.EnableWindow(1);
	mNegativeCheck.EnableWindow(1);
	mDefaultPaletteBtn.EnableWindow(1);
	mGammaSetSlider.EnableWindow(1);;
	mBrightnessSetSlider.EnableWindow(1);;
	mContrastSetSlider.EnableWindow(1);;

	ImageEnhancementUpdateGUI();
	ClearViewUpdateGUI();
	FocusUpdateGUI();
	*/
}

void CUltrasoundBiopsyView::OnSaveimaging32800()
{
	// TODO: 在此添加命令处理程序代码
       CFileDialog dlg(FALSE,L"bmp",NULL,OFN_OVERWRITEPROMPT,L"Bitmap Files (*.bmp)|*.bmp|");
		if (dlg.DoModal() == IDOK)
		{
			CString mFileNameURL;
			mFileNameURL = dlg.GetPathName();
			LPTSTR FileNamestr = mFileNameURL.GetBuffer();
		    theApp.mPUSGFW2ForMX->SaveImageToFile(FileNamestr); 
			mFileNameURL.ReleaseBuffer();
			
		}
	
}

void CUltrasoundBiopsyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(DetectMouseMoveID==1)
	{
		CString PointInforStr;
		CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
		CClientDC dc(this);
		CMFCRibbonBaseElement * pElement;  
        pElement = pMainFrame->m_wndStatusBar.FindElement(ID_STATUSBAR_PANE4); 
		//获取该点像素值
		COLORREF color=dc.GetPixel(point);
		BYTE R,G,B,temp;
		PointInforStr.Format(L"(x=%i,y=%i) (R=%i G=%i B=%i)",point.x, point.y,GetRValue(color),GetGValue(color),GetBValue(color));
		//在状态栏中显示像素值
		pElement->SetText(PointInforStr);  
		pElement->Redraw(); 
		if(AutohideribbonID)
		{
				if(pMainFrame->m_wndRibbonBar.IsVisible()==FALSE)
				{
					if(point.y<=8)
					pMainFrame->m_wndRibbonBar.ShowWindow(SW_SHOW); 
	  				pMainFrame->RecalcLayout(FALSE);
				}
				else
				{
					if(point.y>30)
					pMainFrame->m_wndRibbonBar.ShowWindow(SW_HIDE); 
	  				pMainFrame->RecalcLayout(FALSE);

			   }
		}
		
	}
	CView::OnMouseMove(nFlags, point);
}

void CUltrasoundBiopsyView::OnAutohideribbon32834()
{
	// TODO: 在此添加命令处理程序代码
	//return;
	AutohideribbonID=!AutohideribbonID;
	//if(AutohideribbonID
	//CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndRibbonBar.ShowWindow(AutohideribbonID==TRUE ? SW_HIDE : SW_SHOW);
	//pMainFrame->RecalcLayout(FALSE);
}

void CUltrasoundBiopsyView::OnApplicationView(UINT id)
{
		

	switch (id)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
	
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
	
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
	
		break;

	
	}

	
}


void CUltrasoundBiopsyView::OnUpdateApplicationViewUI(CCmdUI* pCmdUI)
{
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pMainFrame->m_wndRibbonBar.ShowWindow(pMainFrame->m_wndRibbonBar.IsVisible() ? SW_HIDE : SW_SHOW);
	
	switch(pCmdUI->m_nID)
	{
	case ID_ShowRibbonWindow_32776:
		pCmdUI->SetCheck(pMainFrame->m_wndRibbonBar.IsVisible() ? 1 : 0); 
		break;
	case ID_ShowStatusWindow_32789:
		pCmdUI->SetCheck(pMainFrame->m_wndStatusBar.IsVisible() ? 1 : 0); 
		break;
    case ID_AutoHideRibbon_32834:
		pCmdUI->SetCheck(AutohideribbonID==TRUE? 1 : 0); 
		break;

	}

	//pCmdUI->SetCheck( == pCmdUI->m_nID);
}

void CUltrasoundBiopsyView::OnUpdateShowribbonwindow32776(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pCmdUI->SetCheck(pMainFrame->m_wndRibbonBar.IsVisible() ? 1 : 0); 
	//---test---
	CClientDC mClientDC(this); 
	mClientDC.SetTextColor(RGB(33,45,120)); 
	CString strTime; 
    strTime = CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S"));  
	mClientDC.TextOutW(200,300,strTime); 

}


void CUltrasoundBiopsyView::OnUpdateAutohideribbon32834(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pCmdUI->SetCheck(AutohideribbonID==TRUE? 1 : 0); 

}


void CUltrasoundBiopsyView::OnUpdateShowstatuswindow32789(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pCmdUI->SetCheck(pMainFrame->m_wndStatusBar.IsVisible() ? 1 : 0); 
}


void CUltrasoundBiopsyView::OnUpdateShowoutputwindow32773(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pCmdUI->SetCheck(pMainFrame->m_wndOutput.IsVisible() ? 1 : 0); 
}


void CUltrasoundBiopsyView::OnUpdateShowpropertywindow32771(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pCmdUI->SetCheck(pMainFrame->m_wndProperties.IsVisible() ? 1 : 0); 
}


void CUltrasoundBiopsyView::OnUpdateShowlefttoolwindowMenu(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//CMainFrame* pMainFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	//pCmdUI->SetCheck(pMainFrame->m_wndRibbonBar.IsVisible() ? 1 : 0); 
}


void CUltrasoundBiopsyView::OnUpdateOpendevice32794(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	 // if(theApp.mPUSGFW2ForMX->ConnectToDevice())
	if(theApp.mPUSGFW2ForMX!=NULL)
	 pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->USGDeviceStatus==1 ? 0 : 1); 	

}


void CUltrasoundBiopsyView::OnUpdateColsedevice32795(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(theApp.mPUSGFW2ForMX!=NULL)
	 pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->USGDeviceStatus==1 ? 1: 0); 	

}


void CUltrasoundBiopsyView::OnUpdateStartimageing32797(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(theApp.mPUSGFW2ForMX!=NULL)
	 pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->USGDeviceStatus==1 ? 1: 0); 
	
}


void CUltrasoundBiopsyView::OnUpdateColseimaging32798(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码=131
	if(theApp.mPUSGFW2ForMX!=NULL)
	pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->ReturnResultValue==0 ? 1: 0);

}


void CUltrasoundBiopsyView::OnUpdateFreezeimaging32799(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(theApp.mPUSGFW2ForMX!=NULL)
    pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->ReturnResultValue==1 ? 1: 0);


}


void CUltrasoundBiopsyView::OnUpdateSaveimaging32800(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(theApp.mPUSGFW2ForMX!=NULL)
	pCmdUI->SetCheck(theApp.mPUSGFW2ForMX->USGFreezeStatus==TRUE ? 1: 0);


}


void CUltrasoundBiopsyView::OnAppMainVieChange(UINT nID)
{
}


void CUltrasoundBiopsyView::OnUpdateAppMainViewUI(CCmdUI* pCmdUI)
{
}


void CUltrasoundBiopsyView::OnBnClickedTestButton()
{
	// TODO: 在此添加控件通知处理程序代码
    MessageBox(_T("Hello World!"));

}
