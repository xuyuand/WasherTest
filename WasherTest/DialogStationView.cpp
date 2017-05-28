// DialogStationView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "DialogStationView.h"
#include "afxdialogex.h"


// CDialogStationView �Ի���

IMPLEMENT_DYNAMIC(CDialogStationView, CDialogEx)

CDialogStationView::CDialogStationView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogStationView::IDD, pParent)
{

}

CDialogStationView::~CDialogStationView()
{
}

void CDialogStationView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_START, m_BtnOk);
}


BEGIN_MESSAGE_MAP(CDialogStationView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDialogStationView::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDialogStationView::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_PRINTCURVE, &CDialogStationView::OnBnClickedButtonPrintcurve)
END_MESSAGE_MAP()


// CDialogStationView ��Ϣ�������


void CDialogStationView::OnBnClickedButtonStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDetectionTaskDlg detectionTaskDlg;
	detectionTaskDlg.DoModal();
}


BOOL CDialogStationView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(FALSE);
	//GetDlgItem(IDC_BUTTON_PRINTCURVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_REALTIMEDATA)->EnableWindow(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDialogStationView::OnBnClickedButtonStop()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDialogStationView::OnBnClickedButtonPrintcurve()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CPrintDlg printDlg;
	printDlg.DoModal();
}
