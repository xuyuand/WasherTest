#pragma once


// CWndGraphic �Ի���

class CWndGraphic : public CDialogEx
{
	DECLARE_DYNAMIC(CWndGraphic)

public:
	CWndGraphic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWndGraphic();

// �Ի�������
	enum { IDD = IDD_DLGGRAPHIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
