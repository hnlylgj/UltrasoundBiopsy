

// UltrasoundBiopsyView.h : CUltrasoundBiopsyView ��Ľӿ�
//

#pragma once


class CUltrasoundBiopsyView : public CView
{
protected: // �������л�����
	CUltrasoundBiopsyView();
	DECLARE_DYNCREATE(CUltrasoundBiopsyView)

// ����
public:
	CUltrasoundBiopsyDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	//--------------
	COLORREF m_ViewBackgroundColor;
	LONG DetectMouseMoveID;
	BOOL AutohideribbonID;


// ʵ��
public:
	virtual ~CUltrasoundBiopsyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnApplicationView(UINT id);
	afx_msg void OnUpdateApplicationViewUI(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
public:
	

	afx_msg void OnShowpropertywindow32771();
	afx_msg void OnShowlefttoolwindowMenu();
	afx_msg void OnShowribbonwindow32776();
	afx_msg void OnShowoutputwindow32773();
	//afx_msg void OnShowapptitlewindow32778();
	afx_msg void OnShowstatuswindow32789();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMininsystem32792();
	afx_msg void OnClosemainapp32779();
	afx_msg void OnColsedevice32795();
	afx_msg void OnOpendevice32794();
	afx_msg void OnStartimageing32797();
	afx_msg void OnColseimaging32798();
	afx_msg void OnFreezeimaging32799();
	afx_msg void OnSaveimaging32800();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnAutohideribbon32834();
	afx_msg void OnUpdateShowribbonwindow32776(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAutohideribbon32834(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShowstatuswindow32789(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShowoutputwindow32773(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShowpropertywindow32771(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShowlefttoolwindowMenu(CCmdUI *pCmdUI);
	afx_msg void OnUpdateOpendevice32794(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColsedevice32795(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColseimaging32798(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFreezeimaging32799(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSaveimaging32800(CCmdUI *pCmdUI);
	afx_msg void OnUpdateStartimageing32797(CCmdUI *pCmdUI);
protected:
	void OnAppMainVieChange(UINT nID);
	void OnUpdateAppMainViewUI(CCmdUI* pCmdUI);
public:
	afx_msg void OnBnClickedTestButton();
};

#ifndef _DEBUG  // UltrasoundBiopsyView.cpp �еĵ��԰汾
inline CUltrasoundBiopsyDoc* CUltrasoundBiopsyView::GetDocument() const
   { return reinterpret_cast<CUltrasoundBiopsyDoc*>(m_pDocument); }
#endif

