#pragma once

#include <afxpriv.h>

// CPreviewPrint ��ͼ

class CPreviewPrint : public CPreviewView
{
	DECLARE_DYNCREATE(CPreviewPrint)

	BOOL	m_bIsCloseFrame;

public:
	CPreviewPrint();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPreviewPrint();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	afx_msg void OnPreviewClose();
	afx_msg void OnPreviewPrint();

protected:
	DECLARE_MESSAGE_MAP()
};


