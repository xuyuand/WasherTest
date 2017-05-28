// PreviewPrint.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "PrintDemo.h"
#include "PreviewPrint.h"
#include "PrintFrame.h"


// CPreviewPrint

IMPLEMENT_DYNCREATE(CPreviewPrint, CPreviewView)

CPreviewPrint::CPreviewPrint()
{
	m_bIsCloseFrame	= FALSE;
}

CPreviewPrint::~CPreviewPrint()
{
}

BEGIN_MESSAGE_MAP(CPreviewPrint, CPreviewView)
   ON_COMMAND(AFX_ID_PREVIEW_CLOSE, OnPreviewClose)
   ON_COMMAND(AFX_ID_PREVIEW_PRINT, OnPreviewPrint)
END_MESSAGE_MAP()


// CPreviewPrint ��ͼ

void CPreviewPrint::OnDraw(CDC* pDC)
{
	CPreviewView::OnDraw(pDC);
	m_pToolBar->PostMessage(WM_IDLEUPDATECMDUI, (WPARAM)TRUE);
}


// CPreviewPrint ���

#ifdef _DEBUG
void CPreviewPrint::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPreviewPrint::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPreviewPrint ��Ϣ�������

void CPreviewPrint::OnPreviewClose()
{
	CPrintFrame*	pFrame	= (CPrintFrame*)::AfxGetMainWnd();
	CWinApp*		pApp	= AfxGetApp();    

	pApp->m_pMainWnd	= pFrame->m_pMainDlg;
	if(!m_bIsCloseFrame)
		pFrame->DestroyWindow();
}

void CPreviewPrint::OnPreviewPrint()
{
   m_pPrintView->SendMessage(WM_COMMAND, ID_FILE_PRINT);
}
