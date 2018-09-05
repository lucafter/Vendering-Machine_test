// LOGIN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "LOGIN.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


// CLOGIN �Ի���

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


// CLOGIN ��Ϣ�������


void CLOGIN::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//������Ʒ�Ի���
}


void CLOGIN::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CInfoFile cinfofile;
	CString pwd;
	cinfofile.ReadLogin(pwd);
	if (m_pwd == pwd)
	{
		CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);//��������Ա�Ի���
		m_pwd.Empty();
		UpdateData(FALSE);
	}
	else
	{
		MessageBox(TEXT("�����������"));
	}
}


void CLOGIN::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLOGIN::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '9';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '8';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '7';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '6';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '1';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '5';
	UpdateData(FALSE);
}



void CLOGIN::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '4';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '3';
	UpdateData(FALSE);

}


void CLOGIN::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '2';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pwd = m_pwd + '0';
	UpdateData(FALSE);
}


void CLOGIN::OnBnClickedButton13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
