
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// UltrasoundBiopsy.h : UltrasoundBiopsy Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "UIDialog\StartingSplash.h"   
#include "USGCode\USGFW2ForMX.h"
// CUltrasoundBiopsyApp:
// �йش����ʵ�֣������ UltrasoundBiopsy.cpp
//

class CUltrasoundBiopsyApp : public CWinAppEx
{
public:
	CUltrasoundBiopsyApp();

   //---------------------------
	//protected:
	 StartingSplash mStartingSplashDlg;
	
	//--�ҵĴ���-----------------------------------------------
	 CUSGFW2ForMX* mPUSGFW2ForMX; 

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUltrasoundBiopsyApp theApp;
