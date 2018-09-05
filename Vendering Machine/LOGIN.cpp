// LOGIN.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "LOGIN.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


// CLOGIN 对话框

IMPLEMENT_DYNAMIC(CLOGIN, CDialogEx)

CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLOGIN::IDD, pParent)
	, m_pwd(_T(""))
{

}

CLOGIN::~CLOGIN()
{
}

void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_pwd);
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLOGIN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLOGIN::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CLOGIN::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CLOGIN::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CLOGIN::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &CLOGIN::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CLOGIN::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON7, &CLOGIN::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CLOGIN::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON11, &CLOGIN::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CLOGIN::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CLOGIN::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CLOGIN::OnBnClickedButton13)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLOGIN 消息处理程序


void CLOGIN::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//跳到商品对话框
}


void CLOGIN::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CInfoFile cinfofile;
	CString pwd;
	cinfofile.ReadLogin(pwd);
	if (m_pwd == pwd)
	{
		CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);//跳到管理员对话框
		m_pwd.Empty();
		UpdateData(FALSE);
	}
	else
	{
		MessageBox(TEXT("输入密码错误"));
	}
}


void CLOGIN::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLOGIN::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '9';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '8';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '7';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '6';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '1';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '5';
	UpdateData(FALSE);
}



void CLOGIN::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '4';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '3';
	UpdateData(FALSE);

}


void CLOGIN::OnBnClickedButton10()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '2';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_pwd = m_pwd + '0';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton13()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!m_pwd.IsEmpty())
	{
		m_pwd = m_pwd.Left(m_pwd.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CLOGIN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);                                 //获取对话框长宽         
	CDC   dcBmp;                                           //定义并创建一个内存设备环境  
	dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP16);                 //载入资源中的IDB_BITMAP1图片  
	BITMAP   m_bitmap;                                     //图片变量                  
	bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
	CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
	//调用函数显示图片 StretchBlt显示形状可变  
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
		m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.SetStretchBltMode(COLORONCOLOR);// 防止图片失真 
}
