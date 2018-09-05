
// Vendering MachineDlg.h : ͷ�ļ�
//

#pragma once
#include "GOODS.h"
#include "HELP.h"
#include "LOGIN.h"
#include "PICKUPCODE.h"
#include "ADMINISTRATOR.h"
#include "SHOPPINGCART.h"
#include "PAY.h"
#include "InfoFile.h"
// CVenderingMachineDlg �Ի���
class CVenderingMachineDlg : public CDialogEx
{
// ����
public:
	CVenderingMachineDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VENDERINGMACHINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��



// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CGOODS   *cgoods;
	CHELP *chelp;
	CLOGIN *clogin;
	CPICKUPCODE *cpickupcode;
	CADMINISTRATOR *cadministrator;
	CSHOPPINGCART *cshoppingcart;
	CPAY *cpay;
	enum
	{
		DLG_CGOODS = 0,
		DLG_CHELP,
		DLG_CLOGIN,
		DLG_CPICKUPCODE,
		DLG_CADMINISTRATOR,
		DLG_CSHOPPINGCART,
		DLG_CPAY,
	};

	///���ؽ���
	BOOL AddPage(CDialog * pDlg, UINT ID);
	///�л�����
	void ShowPage(int CurrentPage);

	//////��Ӷ����
	CDialog *m_pDlgPages[7];///�Զ�����Ҫ��ʾ�Ľ������
	UINT        m_DlgIDD[7];      ///ÿ���Ի����Ӧ��ID
	int m_nDlgPageIdx ;
	CRect m_ShowRect;
	

	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
