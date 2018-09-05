
// Vendering MachineDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "Vendering MachineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVenderingMachineDlg 对话框



CVenderingMachineDlg::CVenderingMachineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVenderingMachineDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVenderingMachineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVenderingMachineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CVenderingMachineDlg 消息处理程序

BOOL CVenderingMachineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CRect   temprect(0, 0, 470, 700);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	//商品界面初始化


	cgoods = new CGOODS;
	cgoods->Create(IDD_GOODS, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(),m_ShowRect.Height());
	cgoods->MoveWindow(m_ShowRect);
	cgoods->ShowWindow(SW_HIDE);
	//帮助界面初始化
	chelp = new CHELP;
	chelp->Create(IDD_HELP, this);
	chelp->ShowWindow(SW_HIDE);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	chelp->MoveWindow(m_ShowRect);
	//管理员登陆界面初始化
	clogin = new CLOGIN;
	clogin->Create(IDD_LOGIN, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	clogin->MoveWindow(m_ShowRect);
	clogin->ShowWindow(SW_HIDE);
	//取货码界面初始化
	cpickupcode = new CPICKUPCODE;
	cpickupcode->Create(IDD_PICKUPCODE, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cpickupcode->MoveWindow(m_ShowRect);
	cpickupcode->ShowWindow(SW_HIDE);
	//管理员界面初始化
	cadministrator = new CADMINISTRATOR;
	cadministrator->Create(IDD_ADMINISTRATOR, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cadministrator->MoveWindow(m_ShowRect);
	cadministrator->ShowWindow(SW_HIDE);
	//购物车界面初始化
	cshoppingcart = new CSHOPPINGCART;
	cshoppingcart->Create(IDD_SHOPPINGCART, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cshoppingcart->MoveWindow(m_ShowRect);
	cshoppingcart->ShowWindow(SW_HIDE);
	//管理员登陆界面初始化
	cpay = new CPAY;
	cpay->Create(IDD_PAY, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cpay->MoveWindow(m_ShowRect);
	cpay->ShowWindow(SW_HIDE);
	ShowPage(0);

	SetTimer(1, 1000, NULL);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CVenderingMachineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVenderingMachineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//注释该语句：防止重复调用重画函数  
		//CDialogEx::OnPaint();  

		//添加代码对话框背景贴图  
		CPaintDC   dc(this);
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

		/******************************************************/
		/** StretchBlt()                                     **/
		/** 参数x、y位图目标矩形左上角x、y的坐标值 居中      **/
		/** nWidth、nHeigth位图目标矩形的逻辑宽度和高度      **/
		/** pSrcDC表示源设备CDC指针                          **/
		/** xSrc、ySrc表示位图源矩形的左上角的x、y逻辑坐标值 **/
		/** dwRop表示显示位图的光栅操作方式                  **/
		/** SRCCOPY用于直接将位图复制到目标环境中            **/
		/******************************************************/
		dc.SetStretchBltMode(COLORONCOLOR);// 防止图片失真 
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVenderingMachineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
BOOL CVenderingMachineDlg::AddPage(CDialog * pDlg, UINT ID)
{

	m_pDlgPages[m_nDlgPageIdx] = pDlg;
	m_DlgIDD[m_nDlgPageIdx] = ID;
	m_pDlgPages[m_nDlgPageIdx]->Create(ID, this);
	m_pDlgPages[m_nDlgPageIdx]->MoveWindow(m_ShowRect);
	m_nDlgPageIdx++;

	return TRUE;
}
void CVenderingMachineDlg::ShowPage(int CurrentPage)
{
	switch (CurrentPage)
	{
	case DLG_CGOODS:
	{
		cgoods->ShowWindow(SW_SHOW);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CHELP:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_SHOW);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CLOGIN:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_SHOW);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CPICKUPCODE:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_SHOW);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CADMINISTRATOR:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_SHOW);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CSHOPPINGCART:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_SHOW);
		cpay->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_CPAY:
	{
		cgoods->ShowWindow(SW_HIDE);
		chelp->ShowWindow(SW_HIDE);
		clogin->ShowWindow(SW_HIDE);
		cpickupcode->ShowWindow(SW_HIDE);
		cadministrator->ShowWindow(SW_HIDE);
		cshoppingcart->ShowWindow(SW_HIDE);
		cpay->ShowWindow(SW_SHOW);
	}
	break;
	}
}

void CVenderingMachineDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	SetDlgItemText(IDC_TIME7, strTime);
	CDialogEx::OnTimer(nIDEvent);
}
