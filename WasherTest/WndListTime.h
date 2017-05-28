#pragma once


// CWndListTime 对话框

class CWndListTime : public CDialogEx
{
	DECLARE_DYNAMIC(CWndListTime)

public:
	CWndListTime(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWndListTime();

// 对话框数据
	enum { IDD = IDD_DLGLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
