
// WasherTestView.h : CWasherTestView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "WndStation.h"

class CWasherTestView : public CFormView
{
protected: // �������л�����
	CWasherTestView();
	DECLARE_DYNCREATE(CWasherTestView)

public:
	enum{ IDD = IDD_WASHERTEST_FORM };

// ����
public:
	CWasherTestDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CWasherTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabStation;
	CWndStation m_wndStation[3];
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // WasherTestView.cpp �еĵ��԰汾
inline CWasherTestDoc* CWasherTestView::GetDocument() const
   { return reinterpret_cast<CWasherTestDoc*>(m_pDocument); }
#endif

