#pragma once


// CWndGraphic 对话框

class CWndGraphic : public CDialogEx
{
	DECLARE_DYNAMIC(CWndGraphic)

public:
	CWndGraphic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWndGraphic();

// 对话框数据
	enum { IDD = IDD_DLGGRAPHIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
