#pragma once
#include "StationSetTabCtrlDlg.h"
#include "afxcmn.h"
#include "GlobalData.h"
/**
   @ brief : ��λ����Dialog
   */

// CStationSet �Ի���

class CStationSet : public CDialogEx
{
	DECLARE_DYNAMIC(CStationSet)

public:
	CStationSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStationSet();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATIONSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStationnumOk();
	afx_msg void OnBnClickedButtonStationsetOk();
	afx_msg void OnBnClickedButtonStationsetCancel();
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab_StationSet;
	CStationSetTabCtrlDlg *m_pStationSetTabCtrlDlg[MAXSTATION];
	afx_msg void OnTcnSelchangeTabStationset(NMHDR *pNMHDR, LRESULT *pResult);

private:
	/**
	   @ brief : ��λ��Ϣ�Ƿ���д����
	   @ return : true : ������false��������
	   */
	bool isInfoComplete();
public:
	afx_msg void OnEnChangeEditStationnum();
};
