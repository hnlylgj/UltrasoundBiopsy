#pragma once
#include "..\UltrasoundBiopsy.h"

// LogoCover �Ի���

class LogoCover : public CDialogEx
{
	DECLARE_DYNAMIC(LogoCover)

public:
	LogoCover(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LogoCover();

// �Ի�������
	enum { IDD = IDD_LogoCover_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
