// WndGraphic.cpp : 实现文件
//

#include "stdafx.h"
#include "WasherTest.h"
#include "WndGraphic.h"
#include "afxdialogex.h"


// CWndGraphic 对话框

IMPLEMENT_DYNAMIC(CWndGraphic, CDialogEx)

CWndGraphic::CWndGraphic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWndGraphic::IDD, pParent)
{

}

CWndGraphic::~CWndGraphic()
{
}

void CWndGraphic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWndGraphic, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWndGraphic::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CWndGraphic::OnBnClickedCancel)
END_MESSAGE_MAP()


// CWndGraphic 消息处理程序


void CWndGraphic::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CWndGraphic::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}
