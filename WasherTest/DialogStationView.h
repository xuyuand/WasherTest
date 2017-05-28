#pragma once
#include "afxwin.h"
#include <iostream>
#include "DetectionTaskDlg.h"
#include "PrintDlg.h"
using namespace std;

// CDialogStationView �Ի���

class CDialogStationView : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogStationView)

public:
	CDialogStationView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogStationView();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATIONVIEW };

	//��־λ 1/2/3��λ
	int m_nType;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_BtnOk;
	//��ʼ���
	afx_msg void OnBnClickedButtonStart();
	//���в���
	virtual BOOL OnInitDialog();
	//��ͣ���
	afx_msg void OnBnClickedButtonStop();
	//��ӡʵʱ����
	afx_msg void OnBnClickedButtonPrintcurve();
};
