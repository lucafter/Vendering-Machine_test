// ADMINISTRATOR.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "ADMINISTRATOR.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


// CADMINISTRATOR 对话框

IMPLEMENT_DYNAMIC(CADMINISTRATOR, CDialogEx)

CADMINISTRATOR::CADMINISTRATOR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CADMINISTRATOR::IDD, pParent)
{

}

CADMINISTRATOR::~CADMINISTRATOR()
{
}

void CADMINISTRATOR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CADMINISTRATOR, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CADMINISTRATOR::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CADMINISTRATOR::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CADMINISTRATOR 消息处理程序


void CADMINISTRATOR::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//跳到商品对话框
}


void CADMINISTRATOR::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	exit(0);
}


BOOL CADMINISTRATOR::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CADMINISTRATOR::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();

	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	SetDlgItemText(IDC_TIME1, strTime);

	CDialogEx::OnTimer(nIDEvent);
}
