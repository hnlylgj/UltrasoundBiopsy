// StartingSplash.cpp : ʵ���ļ�
//
#include "..\stdafx.h"
#include "StartingSplash.h"
#include "afxdialogex.h"


// StartingSplash �Ի���

IMPLEMENT_DYNAMIC(StartingSplash, CDialogEx)

StartingSplash::StartingSplash(CWnd* pParent /*=NULL*/)
	: CDialogEx(StartingSplash::IDD, pParent)
{
	pFlagChar=NULL;
	pUserName=NULL;;
	pAppName=NULL;;
	pDeveloperName=NULL;;
	pCoprRightName=NULL;;
	pUsableName=NULL;;
}

StartingSplash::~StartingSplash()
{
	if(pFlagChar!=NULL)delete pFlagChar;
	//SAFE_DELETE(pFlagChar);
	
	//SAFE_DELETE(pUserName);
	//SAFE_DELETE(pAppName);
	//SAFE_DELETE(pDeveloperName);
	//SAFE_DELETE(pCoprRightName);
	//SAFE_DELETE(pUsableName);

}

void StartingSplash::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StartingSplash, CDialogEx)
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL StartingSplash::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CRect mRect;   
    GetClientRect(&mRect); 
	y=mRect.Height();

	int CharCount=120;
    pFlagChar=new CHAR[CharCount];//�ָ��ַ���
	for(int i=0;i<CharCount;i++)
    {
	   pFlagChar[i]='=';
    }
    pFlagChar[CharCount-1]='\0';
	//----------------------------------------------------------------
	 pUserName="�л����񹲺͹������ʰ�ҽԺ ";//����-��̳
	 pAppName="�����п�����������ӳ���ϵͳ ";
	 pDeveloperName="��Ȩ��λ:����(�¹�)ҽ����е���޹�˾ ";
	 pCoprRightName="Version 1.0 Copyright@2012";
	 pUsableName="רΪ�������ƵĴ��̵����� ʹҽ����ָ�ϳ������۾���";
	 //---------------------------------------------------------------
	 mUserNameFontCout=200;
	 mAppNameFontCout=250;
	 mDeveloperNameFontCout=180;
	 mCoprRightNameFontCout=120;
	 mUsableNameFontCout=180;
	 mFlagCharFontCout=80;
	 //----------------------------------------------------------------

	 CDC*  pDC = GetDC();
	 CFont  NewOutTextFont;//�ı����������       
	 CFont  *pOldFont;   //������ǰ������ָ�� 

	 NewOutTextFont.CreatePointFont(mUserNameFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mUserNameSize=pDC->GetTextExtent((CString)pUserName);//����ַ�������
	
	
	 NewOutTextFont.DeleteObject(); 
	 NewOutTextFont.CreatePointFont(mAppNameFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mAppNameSize=pDC->GetTextExtent((CString)pAppName);//����ַ�������

	 NewOutTextFont.DeleteObject(); 
	 NewOutTextFont.CreatePointFont(mFlagCharFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mFlagCharSize=pDC->GetTextExtent((CString)pFlagChar);//����ַ�������


	 NewOutTextFont.DeleteObject(); 
	 NewOutTextFont.CreatePointFont(mDeveloperNameFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mDeveloperNameSize=pDC->GetTextExtent((CString)pDeveloperName);//����ַ�������

	 NewOutTextFont.DeleteObject(); 
	 NewOutTextFont.CreatePointFont(mCoprRightNameFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mCoprRightNameSize=pDC->GetTextExtent((CString)pCoprRightName);//����ַ�������

	 NewOutTextFont.DeleteObject(); 
	 NewOutTextFont.CreatePointFont(mUsableNameFontCout,L"����");
	 pOldFont=pDC->SelectObject(&NewOutTextFont);//ѡ������Ҫ������ 
	 mUsableNameSize=pDC->GetTextExtent((CString)pUsableName);//����ַ�������


	ShowWindow(SW_SHOWMAXIMIZED); //ȫ����ʾ
    m_MemBitmap.init(this);  
    SetTimer(1,20,NULL);  
	
	//-------MyCBitmap------------------------------------------------------------------------------------------
    /*
	MyCBitmap.LoadBitmap(IDB_BITMAP4); 
    BITMAP MyBITMAPSize;
     //��ȡλͼ��Ϣ
    MyCBitmap.GetBitmap(&MyBITMAPSize);
    int cx=MyBITMAPSize.bmWidth;  //�õ�ͼ���� 
    int cy=MyBITMAPSize.bmHeight; //�õ�ͼ��߶� 
    CRect mRect; 
    GetDlgItem(IDC_STATIC_RectangleVideoWindow)->GetWindowRect(&mRect); 
    ScreenToClient(&mRect); 
    GetDlgItem(IDC_STATIC_RectangleVideoWindow)->MoveWindow(mRect.left,mRect.top,cx,cy,true);//������С  
	*/
	 
	return TRUE;  // return TRUE unless you set the focus to a control // EXCEPTION: OCX Property Pages should return FALSE
}



// StartingSplash ��Ϣ�������


void StartingSplash::OnTimer(UINT_PTR nIDEvent)
{
	//��ӵ���Ϣ����������
  CRect   mRect;    
  CDC*    pDC = GetDC();
  CDC     mDC;
  this->GetClientRect(&mRect); 
  LONG mOutTextPointX;
  //mOutTextPointX=(int)(mRect.Width()/2);
  mOutTextPointX=mRect.Width();
  //int CharCount;
  //CharCount=120;
  //CHAR * pFlagChar=new CHAR[CharCount];
  //pFlagChar=new CHAR[CharCount];
  //for(int i=0;i<CharCount;i++)
  //{
  //  pFlagChar[i]='=';
  //}
  //pFlagChar[CharCount-1]='\0';
  y--;
  m_MemBitmap.Clear(mRect.left, mRect.top, mRect.right, mRect.bottom, RGB(00,00,00)); //���128,138,135--������41,36,33-�غ�ɫ��RGBֵ94 38 18--69, 33,21
  
  LONG OutTextPosionX,OutTextPosionY,mDistanceValue;
  OutTextPosionX=(mOutTextPointX-mUserNameSize.cx)/2;
  mDistanceValue=0;
  OutTextPosionY=(LONG)y+mDistanceValue;
  m_MemBitmap.TextOut((int)OutTextPosionX ,(int)OutTextPosionY/*y*/,mUserNameFontCout, pUserName,RGB(0,250,0)); //1

  OutTextPosionX=(mOutTextPointX-mAppNameSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy-20;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+60*/,mAppNameFontCout, pAppName,RGB(0,250,0)); //2

  OutTextPosionX=(mOutTextPointX-mFlagCharSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy+mFlagCharSize.cy+30;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+130*/,mFlagCharFontCout,pFlagChar,RGB(0,250,0));//3

  OutTextPosionX=(mOutTextPointX-mDeveloperNameSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy+mFlagCharSize.cy+mDeveloperNameSize.cy+30;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+180*/,mDeveloperNameFontCout,pDeveloperName,RGB(255,0,0)); //4

  OutTextPosionX=(mOutTextPointX-mCoprRightNameSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy+mFlagCharSize.cy+mDeveloperNameSize.cy+mCoprRightNameSize.cy+50;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+240*/,mCoprRightNameFontCout,pCoprRightName,RGB(255,0,0)); //5

  OutTextPosionX=(mOutTextPointX-mFlagCharSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy+mFlagCharSize.cy+mDeveloperNameSize.cy+mCoprRightNameSize.cy+mFlagCharSize.cy+70;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+300*/,mFlagCharFontCout,pFlagChar,RGB(0,250,0));//6

  OutTextPosionX=(mOutTextPointX-mUsableNameSize.cx)/2;
  mDistanceValue=mUserNameSize.cy+ mAppNameSize.cy+mFlagCharSize.cy+mDeveloperNameSize.cy+mCoprRightNameSize.cy+mFlagCharSize.cy+mUsableNameSize.cy+70;
  OutTextPosionY=(LONG)y+mDistanceValue; 
  m_MemBitmap.TextOut((int)OutTextPosionX,(int)OutTextPosionY/*y+340*/,mUsableNameFontCout, pUsableName,RGB(0,250,0));//7

  /*
  m_MemBitmap.Clear(mRect.left, mRect.top, mRect.right, mRect.bottom, RGB(00,00,00)); //���128,138,135--������41,36,33-�غ�ɫ��RGBֵ94 38 18--69, 33,21
  m_MemBitmap.TextOut(mOutTextPointX-125,y,200,  "������̳ҽԺ ",RGB(0,250,0));  
  m_MemBitmap.TextOut(mOutTextPointX-280,y+60,250,  "�����п�����������ӳ���ϵͳ ",RGB(0,250,0));  
  m_MemBitmap.TextOut(mOutTextPointX-400,y+130,80, pFlagChar,RGB(0,250,0)); 
  m_MemBitmap.TextOut(mOutTextPointX-250,y+180,180, "��Ȩ��λ:����(�¹�)ҽ����е���޹�˾ ",RGB(255,0,0)); 
  m_MemBitmap.TextOut(mOutTextPointX-160,y+240,120,"Version 1.0 Copyright@2012",RGB(255,0,0)); 
  m_MemBitmap.TextOut(mOutTextPointX-400,y+300,80,pFlagChar,RGB(0,250,0));
  m_MemBitmap.TextOut(mOutTextPointX-350,y+340,180, "רΪ�������ƵĴ��̵����� ʹҽ����ָ�ϳ������۾���",RGB(0,250,0));
  */
  /*
  m_MemBitmap.TextOut(280,y,180,  " ������̳ҽԺ ",RGB(0,250,0));  
  m_MemBitmap.TextOut(180,y+30,180,  "�����п�����������ӳ�����ϵͳ ",RGB(0,250,0));  
  m_MemBitmap.TextOut(10,y+60,120, "===============================================================================================",RGB(0,0,250)); 
  //m_MemBitmap.TextOut(10,y+60,120, "��Ȩ��: �ƴ��� ",RGB(0,250,0));   
  m_MemBitmap.TextOut(240,y+90,120, "��Ȩ��λ:����ҽ����е���޹�˾ ",RGB(0,250,0)); 
  m_MemBitmap.TextOut(240,y+120,120,"Version 1.0 Copyright@2012",RGB(0,250,0)); 
  m_MemBitmap.TextOut(10,y+150,120,"===============================================================================================",RGB(0,0,250));
  m_MemBitmap.TextOut(280,y+180,150, "רҵ���ɿ����Ƚ���׿Խ",RGB(0,250,0));
  */
  mDC.CreateCompatibleDC(pDC); 
  mDC.SelectObject(&m_MemBitmap);  //�ڴ��豸������λͼ����ѡ�� 
  pDC->BitBlt(0, 0, mRect.Width() , mRect.Height(),  &mDC,  0,0,SRCCOPY); //��λ���亯����ʾ����
  mDC.DeleteDC();    
  ReleaseDC(pDC); //��ǰ����-�ͷ��豸����
  if(y<=-180)//-180
  { 
     KillTimer(1);
	 CDialogEx::OnCancel(); //������ʾ����˳���
  }
  //delete pFlagChar;
  //--------------------
  
  CDialogEx::OnTimer(nIDEvent);
}
LRESULT StartingSplash::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
 if ( message == WM_KEYDOWN ||message == WM_SYSKEYDOWN ||
   message == WM_LBUTTONDOWN ||message == WM_RBUTTONDOWN ||
   message == WM_MBUTTONDOWN ||message == WM_NCLBUTTONDOWN ||
   message == WM_NCRBUTTONDOWN ||message == WM_NCMBUTTONDOWN )
 {//�����¼��������˳���
      
	  KillTimer(1);
	  CDialogEx::OnCancel();
      return TRUE; 
 }
  return CWnd::WindowProc(message, wParam, lParam);
}



void StartingSplash::OnPaint()
{
	CPaintDC mCurrentDC(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//---------------------------------------------------------------------------------------
    //CPaintDC mCurrentDC(this);      //���ô˾�,�õ����ǶԻ����DC,ͼƬ���������ڶԻ�����. 
    //CDC mCurrentDC; 
    //mCurrentDC.m_hDC=::GetDC(NULL);  //���ô�����,�õ�������Ļ��DC,ͼƬ������������Ļ�� 
	//CPaintDC mCurrentDC(GetDlgItem(IDC_STATIC_RectangleVideoWindow)); //�ô˾�,�õ�picture�ؼ���DC,ͼ�񽫱������ڿؼ���   
    //----------------------------------------------------------------------------------------------------------------
	/*
	CRect rcclient; 
    GetDlgItem(IDC_STATIC_RectangleVideoWindow)->GetClientRect(&rcclient); 
    CDC memdc; 
    memdc.CreateCompatibleDC(&mCurrentDC);   
    CBitmap mbitmapInfor; 
    mbitmapInfor.CreateCompatibleBitmap(&mCurrentDC, rcclient.Width(), rcclient.Height()); 
    memdc.SelectObject(&mbitmapInfor ); 
    CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0); 
    CDC maskdc; 
    maskdc.CreateCompatibleDC(&mCurrentDC); 
    CBitmap maskbitmap; 
    maskbitmap.CreateBitmap(rcclient.Width(), rcclient.Height(), 1, 1, NULL); 
    maskdc.SelectObject(&maskbitmap ); 
    maskdc.BitBlt( 0, 0, rcclient.Width(), rcclient.Height(), &memdc,
    rcclient.left, rcclient.top, SRCCOPY); 
    CBrush brush; 
    brush.CreatePatternBrush(&MyCBitmap); 
    mCurrentDC.FillRect(rcclient, &brush);   
    mCurrentDC.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(),&memdc, rcclient.left, rcclient.top,SRCPAINT); 
    brush.DeleteObject(); 
	*/

}
