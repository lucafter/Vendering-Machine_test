#pragma once


// CADMINISTRATOR �Ի���

class CADMINISTRATOR : public CDialogEx
{
	DECLARE_DYNAMIC(CADMINISTRATOR)

public:
	CADMINISTRATOR(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CADMINISTRATOR();

// �Ի�������
	enum { IDD = IDD_ADMINISTRATOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
