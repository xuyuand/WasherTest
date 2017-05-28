#pragma once
#include "afxwin.h"

/************************************************************************/
/* 
  @ brief ����ʼ�趨 gxw 2017-5-23 
*/
/************************************************************************/

// CInitializeDlg �Ի���  

class CInitializeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInitializeDlg)

public:
	CInitializeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInitializeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_INITIALIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//ǰһ����λ
	afx_msg void OnBnClickedButtonPre();
	//��һ����λ
	afx_msg void OnBnClickedButtonNext();
	//��ת
	afx_msg void OnBnClickedButtonJump();
	//��������
	afx_msg void OnBnClickedButtonSave();
	CEdit m_CurrentStation;
	CComboBox m_ProductName;
	CEdit m_Model;
	CEdit m_Manufacturer;
	virtual BOOL OnInitDialog();
};
