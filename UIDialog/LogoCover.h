#pragma once
#include "..\UltrasoundBiopsy.h"

// LogoCover 对话框

class LogoCover : public CDialogEx
{
	DECLARE_DYNAMIC(LogoCover)

public:
	LogoCover(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LogoCover();

// 对话框数据
	enum { IDD = IDD_LogoCover_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	//--------------
	//CBitmap MyCBitmap;

public:
	int y;
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) ;
    virtual BOOL OnInitDialog();


	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
