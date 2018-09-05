#pragma once


// CADMINISTRATOR 对话框

class CADMINISTRATOR : public CDialogEx
{
	DECLARE_DYNAMIC(CADMINISTRATOR)

public:
	CADMINISTRATOR(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CADMINISTRATOR();

// 对话框数据
	enum { IDD = IDD_ADMINISTRATOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
