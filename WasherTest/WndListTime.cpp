// WndListTime.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "WndListTime.h"
#include "afxdialogex.h"


// CWndListTime �Ի���

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


// CWndListTime ��Ϣ�������


void CWndListTime::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CWndListTime::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
