#pragma once


// CPAY �Ի���

class CPAY : public CDialogEx
{
	DECLARE_DYNAMIC(CPAY)

public:
	CPAY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPAY();

// �Ի�������
	enum { IDD = IDD_PAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
