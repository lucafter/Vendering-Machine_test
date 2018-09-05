// PICKUPCODE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "PICKUPCODE.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"

// CPICKUPCODE �Ի���

IMPLEMENT_DYNAMIC(CPICKUPCODE, CDialogEx)

CPICKUPCODE::CPICKUPCODE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPICKUPCODE::IDD, pParent)
{

}

CPICKUPCODE::~CPICKUPCODE()
{
}

void CPICKUPCODE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPICKUPCODE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPICKUPCODE::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON0, &CPICKUPCODE::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON11, &CPICKUPCODE::OnBnClickedButton11)
END_MESSAGE_MAP()


// CPICKUPCODE ��Ϣ�������


void CPICKUPCODE::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//������Ʒ�Ի���
}


BOOL CPICKUPCODE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPICKUPCODE::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	if (((CStatic*)GetDlgItem(IDC_TIME5))->GetSafeHwnd())
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_TIME5);
		ASSERT(pStatic);
		CRect rc;
		pStatic->GetWindowRect(&rc);
		ScreenToClient(&rc);
		InvalidateRect(&rc);
	}

	SetDlgItemText(IDC_TIME5, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CPICKUPCODE::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
	CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
	dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP16);                 //������Դ�е�IDB_BITMAP1ͼƬ  
	BITMAP   m_bitmap;                                     //ͼƬ����                  
	bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
	CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
	//���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
		m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.SetStretchBltMode(COLORONCOLOR);// ��ֹͼƬʧ�� 
}


HBRUSH CPICKUPCODE::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_INFO5)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME5)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CPICKUPCODE::OnBnClickedButton0()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


void CPICKUPCODE::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//������Ʒ�Ի���
}
