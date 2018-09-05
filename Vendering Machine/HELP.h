#pragma once
#include "afxwin.h"


// CHELP �Ի���

class CHELP : public CDialogEx
{
	DECLARE_DYNAMIC(CHELP)

public:
	CHELP(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHELP();

// �Ի�������
	enum { IDD = IDD_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CStatic Q1;
	CStatic Q2;
	CStatic Q3;
	CStatic Q4;
	CStatic Q5;
	CStatic A1;
	CStatic A2;
	CStatic A3;
	CStatic A5;
//	CEdit m_ADV;
public:
	afx_msg void OnBnClickedButton2();
private:
	CString m_adv;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
};
