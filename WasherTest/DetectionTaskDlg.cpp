// DetectionTaskDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "DetectionTaskDlg.h"
#include "afxdialogex.h"


// CDetectionTaskDlg �Ի���

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


// CDetectionTaskDlg ��Ϣ�������


void CDetectionTaskDlg::OnBnClickedButtonSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDetectionTaskDlg::OnBnClickedButtonCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SendMessage(WM_CLOSE);
}


BOOL CDetectionTaskDlg::OnInitDialog()
{
	CExpandingDialog::OnInitDialog();

	Expand(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDetectionTaskDlg::OnBnClickedBtnadvance()
{
	static int bExpand = false;
	Expand(!bExpand);
	bExpand = !bExpand;
}
