// WndGraphic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "WndGraphic.h"
#include "afxdialogex.h"


// CWndGraphic �Ի���

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


// CWndGraphic ��Ϣ�������


void CWndGraphic::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CWndGraphic::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
