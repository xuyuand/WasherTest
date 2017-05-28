
// WasherTestView.h : CWasherTestView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "WndStation.h"

class CWasherTestView : public CFormView
{
protected: // 仅从序列化创建
	CWasherTestView();
	DECLARE_DYNCREATE(CWasherTestView)

public:
	enum{ IDD = IDD_WASHERTEST_FORM };

// 特性
public:
	CWasherTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWasherTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabStation;
	CWndStation m_wndStation[3];
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // WasherTestView.cpp 中的调试版本
inline CWasherTestDoc* CWasherTestView::GetDocument() const
   { return reinterpret_cast<CWasherTestDoc*>(m_pDocument); }
#endif

