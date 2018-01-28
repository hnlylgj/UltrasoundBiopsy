#pragma once
#include "BModeCtrlFormView.h"
#include "MModeCtrlFormVIEW.h"
// CBModeCtrlBox

class CBModeCtrlBox : public CDockablePane
{
	DECLARE_DYNAMIC(CBModeCtrlBox)

public:
	CBModeCtrlBox();
	CBModeCtrlBox(int nFormViewID);
	virtual ~CBModeCtrlBox();

protected:
	DECLARE_MESSAGE_MAP()
	//-----------------------------------
	int FormViewID;
	CBModeCtrlFormView* pBModeCtrlFormView;
	CMModeCtrlFormVIEW* pMModeCtrlFormView;


public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


