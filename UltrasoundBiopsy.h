
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// UltrasoundBiopsy.h : UltrasoundBiopsy 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "UIDialog\StartingSplash.h"   
#include "USGCode\USGFW2ForMX.h"
// CUltrasoundBiopsyApp:
// 有关此类的实现，请参阅 UltrasoundBiopsy.cpp
//

class CUltrasoundBiopsyApp : public CWinAppEx
{
public:
	CUltrasoundBiopsyApp();

   //---------------------------
	//protected:
	 StartingSplash mStartingSplashDlg;
	
	//--我的代码-----------------------------------------------
	 CUSGFW2ForMX* mPUSGFW2ForMX; 

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUltrasoundBiopsyApp theApp;
