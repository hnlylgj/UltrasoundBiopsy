
// ��Ȩ����(C) Maxenmed  Corporation
// ��������Ȩ����

// UltrasoundBiopsyDoc.cpp : CUltrasoundBiopsyDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UltrasoundBiopsy.h"
#endif

#include "UltrasoundBiopsyDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CUltrasoundBiopsyDoc

IMPLEMENT_DYNCREATE(CUltrasoundBiopsyDoc, CDocument)

BEGIN_MESSAGE_MAP(CUltrasoundBiopsyDoc, CDocument)
END_MESSAGE_MAP()


// CUltrasoundBiopsyDoc ����/����

CUltrasoundBiopsyDoc::CUltrasoundBiopsyDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CUltrasoundBiopsyDoc::~CUltrasoundBiopsyDoc()
{
}

BOOL CUltrasoundBiopsyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	SetTitle(L"�Ŵ���[B1032101]");
	return TRUE;
}




// CUltrasoundBiopsyDoc ���л�

void CUltrasoundBiopsyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CUltrasoundBiopsyDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CUltrasoundBiopsyDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CUltrasoundBiopsyDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CUltrasoundBiopsyDoc ���

#ifdef _DEBUG
void CUltrasoundBiopsyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUltrasoundBiopsyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CUltrasoundBiopsyDoc ����
