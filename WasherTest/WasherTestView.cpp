
// WasherTestView.cpp : CWasherTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "WasherTest.h"
#endif

#include "WasherTestDoc.h"
#include "WasherTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWasherTestView

IMPLEMENT_DYNCREATE(CWasherTestView, CFormView)

BEGIN_MESSAGE_MAP(CWasherTestView, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CWasherTestView 构造/析构

CWasherTestView::CWasherTestView()
	: CFormView(CWasherTestView::IDD)
{
	// TODO:  在此处添加构造代码

}

CWasherTestView::~CWasherTestView()
{
}

void CWasherTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABSTATION, m_tabStation);
}

BOOL CWasherTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CWasherTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_tabStation.InsertItem(0, _T("工位1"));
	m_tabStation.InsertItem(1, _T("工位2"));
	m_tabStation.InsertItem(2, _T("工位3"));

	m_wndStation[0].Create(CWndStation::IDD, &m_tabStation);
	m_wndStation[1].Create(CWndStation::IDD, &m_tabStation);
	m_wndStation[2].Create(CWndStation::IDD, &m_tabStation);

	m_wndStation[0].ShowWindow(SW_SHOW);
	m_wndStation[1].ShowWindow(SW_SHOW);
	m_wndStation[2].ShowWindow(SW_SHOW);

}


// CWasherTestView 诊断

#ifdef _DEBUG
void CWasherTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWasherTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CWasherTestDoc* CWasherTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWasherTestDoc)));
	return (CWasherTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CWasherTestView 消息处理程序


void CWasherTestView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	if (m_wndStation[0].GetSafeHwnd() != NULL)
	{
		m_tabStation.MoveWindow(0, 0, cx, cy);
		m_wndStation[0].MoveWindow(0, 20, cx, cy - 20);
		m_wndStation[1].MoveWindow(0, 20, cx, cy - 20);
		m_wndStation[2].MoveWindow(0, 20, cx, cy - 20);
	}
}
