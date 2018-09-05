// HELP.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "HELP.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"

// CHELP 对话框

IMPLEMENT_DYNAMIC(CHELP, CDialogEx)

CHELP::CHELP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHELP::IDD, pParent)
	, m_adv(_T(""))
{

}

CHELP::~CHELP()
{
}

void CHELP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Q1, Q1);
	DDX_Control(pDX, IDC_Q2, Q2);
	DDX_Control(pDX, IDC_Q3, Q3);
	DDX_Control(pDX, IDC_Q4, Q4);
	DDX_Control(pDX, IDC_Q5, Q5);
	DDX_Control(pDX, IDC_A1, A1);
	DDX_Control(pDX, IDC_A2, A2);
	DDX_Control(pDX, IDC_A3, A3);
	DDX_Control(pDX, IDC_A5, A5);
	//  DDX_Control(pDX, IDC_EDIT1, m_ADV);
	DDX_Text(pDX, IDC_EDIT1, m_adv);
}


BEGIN_MESSAGE_MAP(CHELP, CDialogEx)
	ON_BN_CLICKED(IDOK, &CHELP::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CHELP::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CHELP::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CHELP::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CHELP 消息处理程序


void CHELP::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//跳到GOODS对话框
}




BOOL CHELP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 1000, NULL);

	//设置问题的字体
	CFont *m_pFont1;//创建新的字体
	m_pFont1 = new CFont;
	m_pFont1->CreateFont(23,							 // 字体高度
		0,							 // 字体宽度
		0,							 // 字体倾斜角
		0,							 // 字体倾斜角
		FW_SEMIBOLD,				         // 字体的粗细
		FALSE,						 // 字体是否为斜体
		FALSE,						 // 字体是否有下划线
		0,							 // 字体是否有删除线
		ANSI_CHARSET,				         // 字体使用的字符集
		OUT_DEFAULT_PRECIS,		     	                 // 指定如何选择合适的字体
		CLIP_DEFAULT_PRECIS,    		                 // 确定裁剪的精度
		DEFAULT_QUALITY,			                 // 怎么样跟选择的字体相符合
		DEFAULT_PITCH | FF_SWISS,	                         // 间距标志和属性标志
		_T("微软雅黑"));				         // 字体的名称

	//标签控件
	Q1.SetFont(m_pFont1, false);	//将编辑框与设置字体相关联
	Q2.SetFont(m_pFont1, false);
	Q3.SetFont(m_pFont1, false);
	Q4.SetFont(m_pFont1, false);
	Q5.SetFont(m_pFont1, false);

	//设置回答的字体
	CFont *m_pFont2;//创建新的字体
	m_pFont2 = new CFont;
	m_pFont2->CreateFont(19,							 // 字体高度
		0,							 // 字体宽度
		0,							 // 字体倾斜角
		0,							 // 字体倾斜角
		FW_EXTRALIGHT,				         // 字体的粗细
		FALSE,						 // 字体是否为斜体
		FALSE,						 // 字体是否有下划线
		0,							 // 字体是否有删除线
		ANSI_CHARSET,				         // 字体使用的字符集
		OUT_DEFAULT_PRECIS,		     	                 // 指定如何选择合适的字体
		CLIP_DEFAULT_PRECIS,    		                 // 确定裁剪的精度
		DEFAULT_QUALITY,			                 // 怎么样跟选择的字体相符合
		DEFAULT_PITCH | FF_SWISS,	                         // 间距标志和属性标志
		_T("微软雅黑"));				         // 字体的名称

	//标签控件
	A1.SetFont(m_pFont2, false);	
	A2.SetFont(m_pFont2, false);
	A3.SetFont(m_pFont2, false);
	A5.SetFont(m_pFont2, false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CHELP::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	if (((CStatic*)GetDlgItem(IDC_TIME3))->GetSafeHwnd())
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_TIME3);
		ASSERT(pStatic);
		CRect rc;
		pStatic->GetWindowRect(&rc);
		ScreenToClient(&rc);
		InvalidateRect(&rc);
	}

	SetDlgItemText(IDC_TIME3, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CHELP::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);                                 //获取对话框长宽         
	CDC   dcBmp;                                           //定义并创建一个内存设备环境  
	dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2);                 //载入资源  
	BITMAP   m_bitmap;                                     //图片变量                  
	bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
	CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
	//调用函数显示图片 StretchBlt显示形状可变  
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
		m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.SetStretchBltMode(COLORONCOLOR);// 防止图片失真 
}


HBRUSH CHELP::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (pWnd->GetDlgCtrlID() == IDC_INFO3)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME3)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q1)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(72, 118, 255)); //文字颜色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q2)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(72, 118, 255)); //文字颜色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q3)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(72, 118, 255)); //文字颜色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q4)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(72, 118, 255)); //文字颜色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q5)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(72, 118, 255)); //文字颜色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A1)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(82,82,82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A2)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A3)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A5)
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CHELP::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_adv.Empty();
	UpdateData(FALSE);
}


void CHELP::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strl=m_adv.GetString();
	if (strl.IsEmpty())
	{
		CString str = TEXT("请您输入有效反馈^ ^");
		MessageBox(str);
	}
	
	if (!strl.IsEmpty())
	{
		CString strn = TEXT("提交成功^ ^");
		MessageBox(strn);

		
	}
	m_adv.Empty();
	UpdateData(FALSE);
}


void CHELP::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
