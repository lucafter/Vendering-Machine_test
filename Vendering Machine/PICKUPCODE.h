#pragma once


// CPICKUPCODE �Ի���

class CPICKUPCODE : public CDialogEx
{
	DECLARE_DYNAMIC(CPICKUPCODE)

public:
	CPICKUPCODE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPICKUPCODE();

// �Ի�������
	enum { IDD = IDD_PICKUPCODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton11();
};
