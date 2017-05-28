#pragma once

#define		WM_MAINFRAME_PRINT				WM_USER+1001	//��ӡ��Ϣ
#define		WM_MAINFRAME_BEGIN_PRINTING		WM_USER+1002	//׼����ӡ
#define		WM_MAINFRAME_END_PRINTING		WM_USER+1003	//������ӡ
#define		PRINTMARGIN						2

// CPrintView ��ͼ

class CPrintView : public CScrollView
{
	DECLARE_DYNCREATE(CPrintView)

public:
	CPrintView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPrintView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	afx_msg void	OnFilePrintPreview();

	static BOOL CALLBACK	ProcClosePrintPreview(CFrameWnd* pFrameWnd);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	DECLARE_MESSAGE_MAP()
};