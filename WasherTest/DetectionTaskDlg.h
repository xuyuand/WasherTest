#pragma once
#include "EXPANDINGDIALOG.H"

// CDetectionTaskDlg �Ի���

class CDetectionTaskDlg : public CExpandingDialog
{
	DECLARE_DYNAMIC(CDetectionTaskDlg)

public:
	CDetectionTaskDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetectionTaskDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECTIONTASK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//��������ѡ��
	afx_msg void OnBnClickedButtonSave();
	//ȡ��
	afx_msg void OnBnClickedButtonCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnadvance();
};
