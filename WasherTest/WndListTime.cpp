// WndListTime.cpp : 实现文件
//

#include "stdafx.h"
#include "WasherTest.h"
#include "WndListTime.h"
#include "afxdialogex.h"


// CWndListTime 对话框

IMPLEMENT_DYNAMIC(CWndListTime, CDialogEx)

CWndListTime::CWndListTime(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWndListTime::IDD, pParent)
{

}

CWndListTime::~CWndListTime()
{
}

void CWndListTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWndListTime, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWndListTime::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CWndListTime::OnBnClickedCancel)
END_MESSAGE_MAP()


// CWndListTime 消息处理程序


void CWndListTime::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CWndListTime::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}
