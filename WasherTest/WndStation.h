#pragma once

#include "WndGraphic.h"
#include "WndListTime.h"
// CWndStation 对话框

class CWndStation : public CDialogEx
{
	DECLARE_DYNAMIC(CWndStation)

public:
	CWndStation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWndStation();

// 对话框数据
	enum { IDD = IDD_DLGSTATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

protected:
	CWndGraphic m_wndGraphic;
	CWndListTime m_wndListTime;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedListtime();
	afx_msg void OnBnClickedPrintcurve();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
