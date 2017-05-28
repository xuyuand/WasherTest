// InitializeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "InitializeDlg.h"
#include "afxdialogex.h"


// CInitializeDlg �Ի���

IMPLEMENT_DYNAMIC(CInitializeDlg, CDialogEx)

CInitializeDlg::CInitializeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInitializeDlg::IDD, pParent)
{

}

CInitializeDlg::~CInitializeDlg()
{
}

void CInitializeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CURRENTSTATION, m_CurrentStation);
	DDX_Control(pDX, IDC_COMBO_PRODUCTNAME, m_ProductName);
	DDX_Control(pDX, IDC_EDIT_MODEL, m_Model);
	DDX_Control(pDX, IDC_EDIT_MANUFACTURER, m_Manufacturer);
}


BEGIN_MESSAGE_MAP(CInitializeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PRE, &CInitializeDlg::OnBnClickedButtonPre)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CInitializeDlg::OnBnClickedButtonNext)
	//ON_BN_CLICKED(IDC_BUTTON_JUMP, &CInitializeDlg::OnBnClickedButtonJump)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CInitializeDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CInitializeDlg ��Ϣ�������


void CInitializeDlg::OnBnClickedButtonPre()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strStation;
	m_CurrentStation.GetWindowText(strStation);
	int nStation = _ttoi(strStation);
	nStation--;
	if (!nStation)
	{
		m_CurrentStation.SetWindowText(_T("3"));
	}
	else
	{
		strStation.Format(TEXT("%d"), nStation);
		m_CurrentStation.SetWindowText(strStation);
	}
}


void CInitializeDlg::OnBnClickedButtonNext()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strStation;
	m_CurrentStation.GetWindowText(strStation);
	int nStation = _ttoi(strStation);
	nStation++;
	if (nStation == 4)
	{
		m_CurrentStation.SetWindowText(_T("1"));
	}
	else
	{
		strStation.Format(TEXT("%d"), nStation);
		m_CurrentStation.SetWindowText(strStation);
	}
}


void CInitializeDlg::OnBnClickedButtonJump()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CInitializeDlg::OnBnClickedButtonSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CInitializeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_CurrentStation.SetWindowText(_T("1"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
