#pragma once
#include "afxwin.h"


// CGOODS 对话框

class CGOODS : public CDialogEx
{
	DECLARE_DYNAMIC(CGOODS)

public:
	CGOODS(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGOODS();



// 对话框数据
	enum { IDD = IDD_GOODS };
	CBrush m_brush;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

private:
	CStatic my1;
	CStatic my2;
	CStatic my3;
	CStatic my4;
	CStatic my5;
	CStatic my6;
	CStatic my7;
	CStatic my8;
public:
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	CString strTime;
	CStatic my9;
	CStatic my10;
	CStatic my11;
	CStatic my15;
	CStatic my16;
	CStatic my12;
	CStatic my17;
	CStatic my14;
	CStatic my13;
	CStatic my18;
	CStatic my19;
	CStatic my20;
	CStatic my21;
	CStatic my22;
	CStatic my23;
	CStatic my24;
public:
	afx_msg void OnBnClickedshopping3();
	afx_msg void OnBnClickedshopping1();
	afx_msg void OnBnClickedshopping8();


	afx_msg void OnBnClickedshopping2();
	afx_msg void OnBnClickedshopping5();
};

