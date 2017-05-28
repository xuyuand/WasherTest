// DetectionTaskDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WasherTest.h"
#include "DetectionTaskDlg.h"
#include "afxdialogex.h"


// CDetectionTaskDlg 对话框

IMPLEMENT_DYNAMIC(CDetectionTaskDlg, CExpandingDialog)

CDetectionTaskDlg::CDetectionTaskDlg(CWnd* pParent /*=NULL*/)
: CExpandingDialog(CDetectionTaskDlg::IDD, pParent, IDC_DEFAULTBOX, TRUE)
{

}

CDetectionTaskDlg::~CDetectionTaskDlg()
{
}

void CDetectionTaskDlg::DoDataExchange(CDataExchange* pDX)
{
	CExpandingDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDetectionTaskDlg, CExpandingDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDetectionTaskDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CDetectionTaskDlg::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BTNADVANCE, &CDetectionTaskDlg::OnBnClickedBtnadvance)
END_MESSAGE_MAP()


// CDetectionTaskDlg 消息处理程序


void CDetectionTaskDlg::OnBnClickedButtonSave()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CDetectionTaskDlg::OnBnClickedButtonCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE);
}


BOOL CDetectionTaskDlg::OnInitDialog()
{
	CExpandingDialog::OnInitDialog();

	Expand(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDetectionTaskDlg::OnBnClickedBtnadvance()
{
	static int bExpand = false;
	Expand(!bExpand);
	bExpand = !bExpand;
}
