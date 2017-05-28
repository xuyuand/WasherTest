
// WasherTestView.cpp : CWasherTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CWasherTestView ����/����

CWasherTestView::CWasherTestView()
	: CFormView(CWasherTestView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CWasherTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_tabStation.InsertItem(0, _T("��λ1"));
	m_tabStation.InsertItem(1, _T("��λ2"));
	m_tabStation.InsertItem(2, _T("��λ3"));

	m_wndStation[0].Create(CWndStation::IDD, &m_tabStation);
	m_wndStation[1].Create(CWndStation::IDD, &m_tabStation);
	m_wndStation[2].Create(CWndStation::IDD, &m_tabStation);

	m_wndStation[0].ShowWindow(SW_SHOW);
	m_wndStation[1].ShowWindow(SW_SHOW);
	m_wndStation[2].ShowWindow(SW_SHOW);

}


// CWasherTestView ���

#ifdef _DEBUG
void CWasherTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWasherTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CWasherTestDoc* CWasherTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWasherTestDoc)));
	return (CWasherTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CWasherTestView ��Ϣ�������


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
