// WndStation.cpp : 实现文件
//

#include "stdafx.h"
#include "WasherTest.h"
#include "WndStation.h"
#include "afxdialogex.h"


// CWndStation 对话框

IMPLEMENT_DYNAMIC(CWndStation, CDialogEx)

CWndStation::CWndStation(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWndStation::IDD, pParent)
{

}

CWndStation::~CWndStation()
{
}

void CWndStation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWndStation, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWndStation::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CWndStation::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_LISTTIME, &CWndStation::OnBnClickedListtime)
	ON_BN_CLICKED(IDC_PRINTCURVE, &CWndStation::OnBnClickedPrintcurve)
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CWndStation 消息处理程序


BOOL CWndStation::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_wndGraphic.ShowWindow(SW_SHOW);
	m_wndListTime.ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CWndStation::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CWndStation::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}


void CWndStation::OnBnClickedListtime()
{
	if (IsDlgButtonChecked(IDC_LISTTIME))
	{
		m_wndGraphic.ShowWindow(SW_HIDE);
		m_wndListTime.ShowWindow(SW_SHOW);
	}
	else
	{
		m_wndGraphic.ShowWindow(SW_SHOW);
		m_wndListTime.ShowWindow(SW_HIDE);
	}
}


void CWndStation::OnBnClickedPrintcurve()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CWndStation::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (IsWindow(m_wndListTime.GetSafeHwnd()))
	{
		m_wndListTime.MoveWindow(0, 35, cx, cy - 30);
		m_wndGraphic.MoveWindow(0, 35, cx, cy - 30);
	}
	// TODO:  在此处添加消息处理程序代码
}


int CWndStation::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndGraphic.Create(CWndGraphic::IDD, this);
	m_wndListTime.Create(CWndListTime::IDD, this);



	return 0;
}
