#pragma once


// CLOGIN �Ի���

class CLOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(CLOGIN)

public:
	CLOGIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLOGIN();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_pwd;
	virtual void OnOK();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnPaint();
};
