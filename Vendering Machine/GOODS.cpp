// GOODS.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "GOODS.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"

#include "SHOPPINGCART.h"


// CGOODS 对话框

int shopping1 = 0;
int shopping2 = 0;
int shopping3 = 0;
int shopping4 = 0;
int shopping5 = 0;
int shopping6 = 0;
int shopping7 = 0;
int shopping8 = 0;

//这些全局变量是拿来测试是不是第一次点击加入购物车，如果是，就新建一行，如果已经添加过了，就在原来那一行上修改内容



IMPLEMENT_DYNAMIC(CGOODS, CDialogEx)

CGOODS::CGOODS(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGOODS::IDD, pParent)
{

}

CGOODS::~CGOODS()
{
}

void CGOODS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_1, my1);
	DDX_Control(pDX, IDC_2, my2);
	DDX_Control(pDX, IDC_3, my3);
	DDX_Control(pDX, IDC_4, my4);
	DDX_Control(pDX, IDC_5, my5);
	DDX_Control(pDX, IDC_6, my6);
	DDX_Control(pDX, IDC_7, my7);
	DDX_Control(pDX, IDC_8, my8);
	DDX_Control(pDX, IDC_9, my9);
	DDX_Control(pDX, IDC_10, my10);
	DDX_Control(pDX, IDC_15, my11);
	DDX_Control(pDX, IDC_11, my15);
	DDX_Control(pDX, IDC_16, my16);
	DDX_Control(pDX, IDC_12, my12);
	DDX_Control(pDX, IDC_17, my17);
	DDX_Control(pDX, IDC_14, my14);
	DDX_Control(pDX, IDC_13, my13);
	DDX_Control(pDX, IDC_18, my18);
	DDX_Control(pDX, IDC_19, my19);
	DDX_Control(pDX, IDC_20, my20);
	DDX_Control(pDX, IDC_21, my21);
	DDX_Control(pDX, IDC_22, my22);
	DDX_Control(pDX, IDC_23, my23);
	DDX_Control(pDX, IDC_24, my24);
}


BEGIN_MESSAGE_MAP(CGOODS, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGOODS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CGOODS::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CGOODS::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CGOODS::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_shopping3, &CGOODS::OnBnClickedshopping3)
	ON_BN_CLICKED(IDC_shopping1, &CGOODS::OnBnClickedshopping1)
	ON_BN_CLICKED(IDC_shopping8, &CGOODS::OnBnClickedshopping8)
	ON_BN_CLICKED(IDC_shopping2, &CGOODS::OnBnClickedshopping2)
	ON_BN_CLICKED(IDC_shopping5, &CGOODS::OnBnClickedshopping5)
END_MESSAGE_MAP()


// CGOODS 消息处理程序


void CGOODS::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);//跳到帮助对话框
}





void CGOODS::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);//跳到取货码对话框
}


void CGOODS::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);//跳到管理员登陆对话框
}


void CGOODS::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(5);//跳到购物车对话框
}


BOOL CGOODS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 1000, NULL);
	//获得指向静态控件的指针  
	CStatic   *pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
	//获得位图句柄  
	HBITMAP   hBitmap1 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP8));
	//LONG result = SetWindowLong(pStatic->GetSafeHwnd(),GWL_STYLE,style);
	//设置静态控件的样式，使其可以使用位图，并试位标显示使居中  
	pStatic1->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	//设置静态控件显示位图  
	pStatic1->SetBitmap(hBitmap1);

	CStatic   *pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2); 
	HBITMAP   hBitmap2 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP12));
	pStatic2->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic2->SetBitmap(hBitmap2);

	CStatic   *pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
	HBITMAP   hBitmap3 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP6));
	pStatic3->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic3->SetBitmap(hBitmap3);

	CStatic   *pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	HBITMAP   hBitmap4 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP11));
	pStatic4->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic4->SetBitmap(hBitmap4);



	CStatic   *pStatic9 = (CStatic*)GetDlgItem(IDC_STATIC9);
	HBITMAP   hBitmap9 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP4));
	pStatic9->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic9->SetBitmap(hBitmap9);

	CStatic   *pStatic10 = (CStatic*)GetDlgItem(IDC_STATIC10);
	HBITMAP   hBitmap10 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP7));
	pStatic10->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic10->SetBitmap(hBitmap10);

	CStatic   *pStatic11 = (CStatic*)GetDlgItem(IDC_STATIC11);
	HBITMAP   hBitmap11 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP3));
	pStatic11->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic11->SetBitmap(hBitmap11);

	CStatic   *pStatic12 = (CStatic*)GetDlgItem(IDC_STATIC12);
	HBITMAP   hBitmap12 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP13));
	pStatic12->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic12->SetBitmap(hBitmap12);

	


	CFont *m_pFont;//创建新的字体
	m_pFont = new CFont;
	m_pFont->CreateFont(20,							 // 字体高度
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
	my1.SetFont(m_pFont, false);	//将编辑框与设置字体相关联
	my2.SetFont(m_pFont, false);
	my3.SetFont(m_pFont, false);
	my4.SetFont(m_pFont, false);
	my5.SetFont(m_pFont, false);
	my6.SetFont(m_pFont, false);
	my7.SetFont(m_pFont, false);
	my8.SetFont(m_pFont, false);
	my9.SetFont(m_pFont, false);
	my10.SetFont(m_pFont, false);
	my11.SetFont(m_pFont, false);
	my15.SetFont(m_pFont, false);
	my16.SetFont(m_pFont, false);
	my12.SetFont(m_pFont, false);
	my17.SetFont(m_pFont, false);
	my14.SetFont(m_pFont, false);
	my13.SetFont(m_pFont, false);
	my18.SetFont(m_pFont, false);
	my19.SetFont(m_pFont, false);
	my20.SetFont(m_pFont, false);
	my21.SetFont(m_pFont, false);
	my22.SetFont(m_pFont, false);
	my23.SetFont(m_pFont, false);
	my24.SetFont(m_pFont, false);

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CGOODS::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();
	strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
    if (((CStatic*)GetDlgItem(IDC_TIME2))->GetSafeHwnd())
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_TIME2);
		ASSERT(pStatic);
		CRect rc;
		pStatic->GetWindowRect(&rc);
		ScreenToClient(&rc);
		InvalidateRect(&rc);
	}

	SetDlgItemText(IDC_TIME2, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CGOODS::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	//添加代码对话框背景贴图  
	
	CRect   rect;
	GetClientRect(&rect);                                 //获取对话框长宽         
	CDC   dcBmp;                                           //定义并创建一个内存设备环境  
	dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2);                 //载入资源中的IDB_BITMAP1图片  
	BITMAP   m_bitmap;                                     //图片变量                  
	bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
	CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
	//调用函数显示图片 StretchBlt显示形状可变  
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
		m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.SetStretchBltMode(COLORONCOLOR);// 防止图片失真 

}


HBRUSH CGOODS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_1)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_2)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_3)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_4)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_5)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_6)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_7)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_8)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	
	if (pWnd->GetDlgCtrlID() == IDC_9)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_10)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_11)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_12)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_17)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_14)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_15)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_16)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_13)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_18)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_19)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_20)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_22)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_23)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_21)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}
	if (pWnd->GetDlgCtrlID() == IDC_24)//如果是静态编辑框
	{
		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
		return m_brush;//返回背景色
	}

	if (pWnd->GetDlgCtrlID() == IDC_INFO1)
	{
		pDC->SetTextColor(RGB(0,0,0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME2)
	{
		pDC->SetTextColor(RGB(0,0,0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	
    return hbr;

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

}


void CGOODS::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

	CString strText;
	((CButton *)GetDlgItem(nIDCtl))->GetWindowText(strText);

	SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	//if (lpDrawItemStruct->itemState&ODS_SELECTED)
	{
		CBrush brush(RGB(30,144,255));
		dc.FillRect(&(lpDrawItemStruct->rcItem), &brush);
		DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	}
	dc.Detach();


}



void CGOODS::OnBnClickedshopping3()
{
	// TODO:  在此添加控件通知处理程序代码

	shopping3++;
	if (shopping3 == 1)
	{
		CSHOPPINGCART::InsertList(_T("怡宝"), shopping3, 2.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping3);
		int hang = CSHOPPINGCART::judge(_T("怡宝"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
		
	}
}


void CGOODS::OnBnClickedshopping1()
{
	// TODO:  在此添加控件通知处理程序代码
	shopping1++;
	if (shopping1 == 1)
	{
		CSHOPPINGCART::InsertList(_T("农夫山泉"), shopping1, 2.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping1);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("农夫山泉"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
		
	}
}


void CGOODS::OnBnClickedshopping8()
{
	// TODO:  在此添加控件通知处理程序代码
	shopping8++;
	if (shopping8 == 1)
	{
		CSHOPPINGCART::InsertList(_T("茶π（玫瑰荔枝）"), shopping8,6.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping8);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("茶π（玫瑰荔枝）"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}


}


void CGOODS::OnBnClickedshopping2()
{
	// TODO:  在此添加控件通知处理程序代码
	shopping2++;
	if (shopping2 == 1)
	{
		CSHOPPINGCART::InsertList(_T("海之言（柠檬）"), shopping2, 2.0);
	
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping2);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("海之言（柠檬）"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}
}


void CGOODS::OnBnClickedshopping5()
{
	// TODO:  在此添加控件通知处理程序代码
	shopping5++;
	if (shopping5 == 1)
	{
		CSHOPPINGCART::InsertList(_T("可口可乐"), shopping5 , 3.0);

	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping5);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("可口可乐"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}
}
