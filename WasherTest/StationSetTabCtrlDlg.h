#pragma once
#include "afxwin.h"


// CStationSetTabCtrlDlg �Ի���

class CStationSetTabCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStationSetTabCtrlDlg)

public:
	CStationSetTabCtrlDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStationSetTabCtrlDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATIONSET_TABCTRL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboTemptype();
	CEdit m_stationName;
	CComboBox m_tempType;
	CEdit m_tempAddr;
	CComboBox m_tempCom;
	//CEdit m_sweepSpacing;
	CEdit m_channel1;
	CEdit m_channel1Name;
	CEdit m_channel1SensorType;
	CEdit m_channel1SensorSubType;
	CEdit m_channel2;
	CEdit m_channel2Name;
	CEdit m_channel2SensorType;
	CEdit m_channel2SensorSubType;
	CEdit m_channel3;
	CEdit m_channel3Name;
	CEdit m_channel3SensorType;
	CEdit m_channel3SensorSubType;
};
