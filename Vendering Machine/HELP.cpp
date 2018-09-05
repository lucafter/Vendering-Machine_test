// HELP.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "HELP.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"

// CHELP �Ի���

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


// CHELP ��Ϣ�������


void CHELP::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//����GOODS�Ի���
}




BOOL CHELP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1, 1000, NULL);

	//�������������
	CFont *m_pFont1;//�����µ�����
	m_pFont1 = new CFont;
	m_pFont1->CreateFont(23,							 // ����߶�
		0,							 // ������
		0,							 // ������б��
		0,							 // ������б��
		FW_SEMIBOLD,				         // ����Ĵ�ϸ
		FALSE,						 // �����Ƿ�Ϊб��
		FALSE,						 // �����Ƿ����»���
		0,							 // �����Ƿ���ɾ����
		ANSI_CHARSET,				         // ����ʹ�õ��ַ���
		OUT_DEFAULT_PRECIS,		     	                 // ָ�����ѡ����ʵ�����
		CLIP_DEFAULT_PRECIS,    		                 // ȷ���ü��ľ���
		DEFAULT_QUALITY,			                 // ��ô����ѡ������������
		DEFAULT_PITCH | FF_SWISS,	                         // ����־�����Ա�־
		_T("΢���ź�"));				         // ���������

	//��ǩ�ؼ�
	Q1.SetFont(m_pFont1, false);	//���༭�����������������
	Q2.SetFont(m_pFont1, false);
	Q3.SetFont(m_pFont1, false);
	Q4.SetFont(m_pFont1, false);
	Q5.SetFont(m_pFont1, false);

	//���ûش������
	CFont *m_pFont2;//�����µ�����
	m_pFont2 = new CFont;
	m_pFont2->CreateFont(19,							 // ����߶�
		0,							 // ������
		0,							 // ������б��
		0,							 // ������б��
		FW_EXTRALIGHT,				         // ����Ĵ�ϸ
		FALSE,						 // �����Ƿ�Ϊб��
		FALSE,						 // �����Ƿ����»���
		0,							 // �����Ƿ���ɾ����
		ANSI_CHARSET,				         // ����ʹ�õ��ַ���
		OUT_DEFAULT_PRECIS,		     	                 // ָ�����ѡ����ʵ�����
		CLIP_DEFAULT_PRECIS,    		                 // ȷ���ü��ľ���
		DEFAULT_QUALITY,			                 // ��ô����ѡ������������
		DEFAULT_PITCH | FF_SWISS,	                         // ����־�����Ա�־
		_T("΢���ź�"));				         // ���������

	//��ǩ�ؼ�
	A1.SetFont(m_pFont2, false);	
	A2.SetFont(m_pFont2, false);
	A3.SetFont(m_pFont2, false);
	A5.SetFont(m_pFont2, false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CHELP::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
	CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
	dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2);                 //������Դ  
	BITMAP   m_bitmap;                                     //ͼƬ����                  
	bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
	CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
	//���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
		m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.SetStretchBltMode(COLORONCOLOR);// ��ֹͼƬʧ�� 
}


HBRUSH CHELP::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if (pWnd->GetDlgCtrlID() == IDC_INFO3)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME3)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q1)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(72, 118, 255)); //������ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q2)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(72, 118, 255)); //������ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q3)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(72, 118, 255)); //������ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q4)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(72, 118, 255)); //������ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_Q5)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(72, 118, 255)); //������ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A1)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(82,82,82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A2)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A3)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_A5)
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		pDC->SetTextColor(RGB(82, 82, 82));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CHELP::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_adv.Empty();
	UpdateData(FALSE);
}


void CHELP::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strl=m_adv.GetString();
	if (strl.IsEmpty())
	{
		CString str = TEXT("����������Ч����^ ^");
		MessageBox(str);
	}
	
	if (!strl.IsEmpty())
	{
		CString strn = TEXT("�ύ�ɹ�^ ^");
		MessageBox(strn);

		
	}
	m_adv.Empty();
	UpdateData(FALSE);
}


void CHELP::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
