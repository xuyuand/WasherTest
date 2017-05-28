// PrintDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WasherTest.h"
#include "PrintDlg.h"
#include "afxdialogex.h"


// CPrintDlg �Ի���

IMPLEMENT_DYNAMIC(CPrintDlg, CDialogEx)

CPrintDlg::CPrintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPrintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pPrintFrame = NULL;
}

CPrintDlg::~CPrintDlg()
{
}

void CPrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_VIEW, m_List);
}


BEGIN_MESSAGE_MAP(CPrintDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PRINTVIEW, &CPrintDlg::OnBnClickedButtonPrintview)
	ON_MESSAGE(WM_MAINFRAME_PRINT, OnPrintWindow)
	ON_MESSAGE(WM_MAINFRAME_BEGIN_PRINTING, OnBeginPrinting)
	ON_MESSAGE(WM_MAINFRAME_END_PRINTING, OnEndPrinting)
END_MESSAGE_MAP()


// CPrintDlg ��Ϣ�������


void CPrintDlg::OnBnClickedButtonPrintview()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_pPrintFrame = new CPrintFrame(this);

	//GetWindowGraph();
	m_pPrintFrame->DoPrintView();
}


BOOL CPrintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_ListFont.CreatePointFont(100, "Times New Roman");

	DWORD dwExStyle = m_List.GetExStyle();
	dwExStyle &= ~LVS_EX_CHECKBOXES;

	m_List.SetFont(&m_ListFont);
	m_List.SetExtendedStyle(dwExStyle | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);

	m_List.InsertColumn(0, "ʱ��", LVCFMT_LEFT, 70, -1);
	m_List.InsertColumn(1, "ͨ��1�¶�", LVCFMT_LEFT, 70, -1);
	m_List.InsertColumn(2, "ͨ��2�¶�", LVCFMT_LEFT, 70, -1);
	m_List.InsertColumn(3, "ͨ��3�¶�", LVCFMT_LEFT, 70, -1);

	m_List.InsertColumn(4, "ת��", LVCFMT_LEFT, 80, -1);
	m_List.InsertColumn(5, "��ֵ5", LVCFMT_LEFT, 80, -1);
	m_List.InsertColumn(6, "��ֵ6", LVCFMT_LEFT, 80, -1);

	int i;
	for (i = 0; i < 151; i++)
	{
		CString str[7];

		str[0].Format("%.3f", (double)(i + 1));
		str[1].Format("%.3f", 1 + sin((double)i));
		str[2].Format("%.3f", 1 + cos((double)i));
		str[3].Format("%.3f", 1 + sin((double)0.5*i));

		str[4].Format("%.3f", 1 + cos((double)0.5*i));
		str[5].Format("%.3f", 1 + sin((double)0.1*i));
		str[6].Format("%.3f", 1 + cos((double)0.1*i));
		m_List.InsertItem(i, str[0], -1);
		for (int j = 1; j <= 6; j++)
			m_List.SetItemText(i, j, str[j]);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPrintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CPrintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPrintDlg::PrintPageHeader(CDC* pDC, UINT nPageNumber, CPrintInfo* pInfo)
{
	CFont *pOldFont;
	CFont fontHeader;
	fontHeader.CreatePointFont(100, "FixedSys", pDC);
	pOldFont = (CFont *)(pDC->SelectObject(&fontHeader));
	int nPosY, nPosX;
	nPosY = 3 * m_cyPrinter;
	nPosX = m_cxOffset;
	pDC->TextOut(nPosX, nPosY, CString("�Ͼ����պ����ѧ"));
	CString str;
	str.Format("�� %d ҳ / �� %d ҳ", nPageNumber, pInfo->GetMaxPage());
	CSize size = pDC->GetTextExtent(str);
	nPosX = m_cxOffset + m_cxWidth - size.cx;
	pDC->TextOut(nPosX, nPosY, str);
	pDC->MoveTo(m_cxOffset, 4 * m_cyPrinter);
	pDC->LineTo(m_cxOffset + m_cxWidth, 4 * m_cyPrinter);
	pDC->SelectObject(pOldFont);
	fontHeader.DeleteObject();
}

LRESULT CPrintDlg::OnBeginPrinting(WPARAM wParam, LPARAM lParam)
{
	CDC* pDC = (CDC*)wParam;
	CPrintInfo* pInfo = (CPrintInfo *)lParam;

	if (m_fontPrinter.m_hObject == NULL)
		m_fontPrinter.CreatePointFont(120, "FixedSys", pDC);

	TEXTMETRIC tm;
	CFont* pOldFont = pDC->SelectObject(&m_fontPrinter);
	pDC->GetTextMetrics(&tm);
	m_cyPrinter = tm.tmHeight + tm.tmExternalLeading;//ÿ�и߶�

	CSize size = pDC->GetTextExtent(_T("---------1---------2---------" \
		"3---------4---------5---------6---------7---------8---"), 81);
	pDC->SelectObject(pOldFont);
	m_cxWidth = size.cx;     //��ӡ���

	m_nLinesPerPage = (pDC->GetDeviceCaps(VERTRES) -
		(m_cyPrinter * (3 + (2 * PRINTMARGIN)))) / m_cyPrinter;//ÿҳ����

	int nMax = (151 + m_nLinesPerPage - 1) / m_nLinesPerPage;
	pInfo->SetMaxPage(nMax);

	m_cxOffset = (pDC->GetDeviceCaps(HORZRES) - size.cx) / 2;
	return TRUE;
}

LRESULT CPrintDlg::OnEndPrinting(WPARAM wParam, LPARAM lParam)
{
	if (m_fontPrinter.m_hObject != NULL)
		m_fontPrinter.DeleteObject();
	return TRUE;
}



LRESULT CPrintDlg::OnPrintWindow(WPARAM wParam, LPARAM lParam)
{
	UINT gl_uNumOfPoints = 151;

	CDC* pDC = (CDC*)wParam;
	CPrintInfo* pInfo = (CPrintInfo *)lParam;
	int nPageNumber = pInfo->m_nCurPage;
	int i, j;
	CFont *pOldFont;
	CFont DataFont;
	DataFont.CreatePointFont(120, "����", pDC);

	TCHAR *pszTitle[7] = { "Time", "��ֵ1", "��ֵ2", "��ֵ3", "��ֵ4", "��ֵ5", "��ֵ6" };
	pOldFont = pDC->SelectObject(&DataFont);
	pDC->Rectangle(m_cxOffset, (int)((2.5 + PRINTMARGIN)*m_cyPrinter), m_cxOffset + m_cxWidth, (m_nLinesPerPage + 3 + PRINTMARGIN)*m_cyPrinter + 20);
	for (i = 1; i < 7; i++)
	{
		pDC->MoveTo(m_cxOffset + i*m_cxWidth / 7, (int)((2.5 + PRINTMARGIN)*m_cyPrinter));
		pDC->LineTo(m_cxOffset + i*m_cxWidth / 7, (3 + m_nLinesPerPage + PRINTMARGIN)*m_cyPrinter + 20);
	}
	pDC->MoveTo(m_cxOffset, (4 + PRINTMARGIN)*m_cyPrinter);
	pDC->LineTo(m_cxOffset + m_cxWidth, (4 + PRINTMARGIN)*m_cyPrinter);
	for (i = 0; i < 7; i++)
	{
		pDC->TextOut(m_cxOffset + 50 + i*m_cxWidth / 7, (int)((2.8 + PRINTMARGIN)*m_cyPrinter), CString(pszTitle[i]));
	}
	for (i = 0; i < (int)m_nLinesPerPage - 1; i++)
	{
		CString str[7];
		int nIndex = (nPageNumber - 1)*(m_nLinesPerPage - 1) + i;
		if (nIndex < (int)gl_uNumOfPoints)
		{

			str[0].Format("%.3f", (double)(nIndex + 1));
			str[1].Format("%.3f", 1 + sin((double)i));
			str[2].Format("%.3f", 1 + cos((double)i));
			str[3].Format("%.3f", 1 + sin((double)0.5*i));

			str[4].Format("%.3f", 1 + cos((double)0.5*i));
			str[5].Format("%.3f", 1 + sin((double)0.1*i));
			str[6].Format("%.3f", 1 + cos((double)0.1*i));


			for (j = 0; j < 7; j++)
			{
				pDC->TextOut(m_cxOffset + 50 + j*m_cxWidth / 7, (4 + PRINTMARGIN + i)*m_cyPrinter + 5, str[j]);
			}
		}
	}
	pDC->SelectObject(pOldFont);
	PrintPageHeader(pDC, pInfo->m_nCurPage, pInfo);
	return TRUE;
}