// PAY.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "PAY.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


// CPAY �Ի���

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


// CPAY ��Ϣ�������


void CPAY::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(5);//�������ﳵ�Ի���
}


BOOL CPAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPAY::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


HBRUSH CPAY::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == IDC_INFO4)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME4)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
