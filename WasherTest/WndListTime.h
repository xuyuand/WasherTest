#pragma once


// CWndListTime �Ի���

class CWndListTime : public CDialogEx
{
	DECLARE_DYNAMIC(CWndListTime)

public:
	CWndListTime(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWndListTime();

// �Ի�������
	enum { IDD = IDD_DLGLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
