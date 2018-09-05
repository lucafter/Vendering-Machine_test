// PAY.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "PAY.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


// CPAY 对话框

IMPLEMENT_DYNAMIC(CPAY, CDialogEx)

CPAY::CPAY(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPAY::IDD, pParent)
{

}

CPAY::~CPAY()
{
}

void CPAY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPAY, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPAY::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CPAY 消息处理程序


void CPAY::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(5);//跳到购物车对话框
}


BOOL CPAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CPAY::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	if (((CStatic*)GetDlgItem(IDC_TIME4))->GetSafeHwnd())
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_TIME4);
		ASSERT(pStatic);
		CRect rc;
		pStatic->GetWindowRect(&rc);
		ScreenToClient(&rc);
		InvalidateRect(&rc);
	}

	SetDlgItemText(IDC_TIME4, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CPAY::OnPaint()
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


HBRUSH CPAY::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == IDC_INFO4)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME4)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
