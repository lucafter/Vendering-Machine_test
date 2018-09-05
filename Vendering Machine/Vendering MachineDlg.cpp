
// Vendering MachineDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "Vendering MachineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CVenderingMachineDlg �Ի���



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


// CVenderingMachineDlg ��Ϣ�������

BOOL CVenderingMachineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CRect   temprect(0, 0, 470, 700);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	//��Ʒ�����ʼ��


	cgoods = new CGOODS;
	cgoods->Create(IDD_GOODS, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(),m_ShowRect.Height());
	cgoods->MoveWindow(m_ShowRect);
	cgoods->ShowWindow(SW_HIDE);
	//���������ʼ��
	chelp = new CHELP;
	chelp->Create(IDD_HELP, this);
	chelp->ShowWindow(SW_HIDE);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	chelp->MoveWindow(m_ShowRect);
	//����Ա��½�����ʼ��
	clogin = new CLOGIN;
	clogin->Create(IDD_LOGIN, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	clogin->MoveWindow(m_ShowRect);
	clogin->ShowWindow(SW_HIDE);
	//ȡ��������ʼ��
	cpickupcode = new CPICKUPCODE;
	cpickupcode->Create(IDD_PICKUPCODE, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cpickupcode->MoveWindow(m_ShowRect);
	cpickupcode->ShowWindow(SW_HIDE);
	//����Ա�����ʼ��
	cadministrator = new CADMINISTRATOR;
	cadministrator->Create(IDD_ADMINISTRATOR, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cadministrator->MoveWindow(m_ShowRect);
	cadministrator->ShowWindow(SW_HIDE);
	//���ﳵ�����ʼ��
	cshoppingcart = new CSHOPPINGCART;
	cshoppingcart->Create(IDD_SHOPPINGCART, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cshoppingcart->MoveWindow(m_ShowRect);
	cshoppingcart->ShowWindow(SW_HIDE);
	//����Ա��½�����ʼ��
	cpay = new CPAY;
	cpay->Create(IDD_PAY, this);
	GetWindowRect(m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	cpay->MoveWindow(m_ShowRect);
	cpay->ShowWindow(SW_HIDE);
	ShowPage(0);

	SetTimer(1, 1000, NULL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVenderingMachineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//ע�͸���䣺��ֹ�ظ������ػ�����  
		//CDialogEx::OnPaint();  

		//��Ӵ���Ի��򱳾���ͼ  
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
		CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
		dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP2);                 //������Դ�е�IDB_BITMAP1ͼƬ  
		BITMAP   m_bitmap;                                     //ͼƬ����                  
		bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
		CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
		//���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);

		/******************************************************/
		/** StretchBlt()                                     **/
		/** ����x��yλͼĿ��������Ͻ�x��y������ֵ ����      **/
		/** nWidth��nHeigthλͼĿ����ε��߼���Ⱥ͸߶�      **/
		/** pSrcDC��ʾԴ�豸CDCָ��                          **/
		/** xSrc��ySrc��ʾλͼԴ���ε����Ͻǵ�x��y�߼�����ֵ **/
		/** dwRop��ʾ��ʾλͼ�Ĺ�դ������ʽ                  **/
		/** SRCCOPY����ֱ�ӽ�λͼ���Ƶ�Ŀ�껷����            **/
		/******************************************************/
		dc.SetStretchBltMode(COLORONCOLOR);// ��ֹͼƬʧ�� 
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	SetDlgItemText(IDC_TIME7, strTime);
	CDialogEx::OnTimer(nIDEvent);
}
