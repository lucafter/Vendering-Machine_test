// GOODS.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "GOODS.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"

#include "SHOPPINGCART.h"


// CGOODS �Ի���

int shopping1 = 0;
int shopping2 = 0;
int shopping3 = 0;
int shopping4 = 0;
int shopping5 = 0;
int shopping6 = 0;
int shopping7 = 0;
int shopping8 = 0;

//��Щȫ�ֱ��������������ǲ��ǵ�һ�ε�����빺�ﳵ������ǣ����½�һ�У�����Ѿ���ӹ��ˣ�����ԭ����һ�����޸�����



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


// CGOODS ��Ϣ�������


void CGOODS::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);//���������Ի���
}





void CGOODS::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);//����ȡ����Ի���
}


void CGOODS::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);//��������Ա��½�Ի���
}


void CGOODS::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(5);//�������ﳵ�Ի���
}


BOOL CGOODS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1, 1000, NULL);
	//���ָ��̬�ؼ���ָ��  
	CStatic   *pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
	//���λͼ���  
	HBITMAP   hBitmap1 = ::LoadBitmap(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP8));
	//LONG result = SetWindowLong(pStatic->GetSafeHwnd(),GWL_STYLE,style);
	//���þ�̬�ؼ�����ʽ��ʹ�����ʹ��λͼ������λ����ʾʹ����  
	pStatic1->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	//���þ�̬�ؼ���ʾλͼ  
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

	


	CFont *m_pFont;//�����µ�����
	m_pFont = new CFont;
	m_pFont->CreateFont(20,							 // ����߶�
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
	my1.SetFont(m_pFont, false);	//���༭�����������������
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
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CGOODS::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//��Ӵ���Ի��򱳾���ͼ  
	
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
	dc.SetStretchBltMode(COLORONCOLOR);// ��ֹͼƬʧ�� 

}


HBRUSH CGOODS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_1)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_2)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_3)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_4)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_5)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_6)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_7)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_8)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	
	if (pWnd->GetDlgCtrlID() == IDC_9)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_10)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_11)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_12)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_17)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_14)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_15)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_16)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_13)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_18)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_19)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_20)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_22)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_23)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_21)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}
	if (pWnd->GetDlgCtrlID() == IDC_24)//����Ǿ�̬�༭��
	{
		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
		return m_brush;//���ر���ɫ
	}

	if (pWnd->GetDlgCtrlID() == IDC_INFO1)
	{
		pDC->SetTextColor(RGB(0,0,0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME2)
	{
		pDC->SetTextColor(RGB(0,0,0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	
    return hbr;

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������

}


void CGOODS::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	shopping3++;
	if (shopping3 == 1)
	{
		CSHOPPINGCART::InsertList(_T("����"), shopping3, 2.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping3);
		int hang = CSHOPPINGCART::judge(_T("����"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
		
	}
}


void CGOODS::OnBnClickedshopping1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	shopping1++;
	if (shopping1 == 1)
	{
		CSHOPPINGCART::InsertList(_T("ũ��ɽȪ"), shopping1, 2.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping1);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("ũ��ɽȪ"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
		
	}
}


void CGOODS::OnBnClickedshopping8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	shopping8++;
	if (shopping8 == 1)
	{
		CSHOPPINGCART::InsertList(_T("��У�õ����֦��"), shopping8,6.0);
		
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping8);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("��У�õ����֦��"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}


}


void CGOODS::OnBnClickedshopping2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	shopping2++;
	if (shopping2 == 1)
	{
		CSHOPPINGCART::InsertList(_T("��֮�ԣ����ʣ�"), shopping2, 2.0);
	
	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping2);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("��֮�ԣ����ʣ�"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}
}


void CGOODS::OnBnClickedshopping5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	shopping5++;
	if (shopping5 == 1)
	{
		CSHOPPINGCART::InsertList(_T("�ɿڿ���"), shopping5 , 3.0);

	}
	else
	{
		CString str1;
		str1.Format(_T("%d"), shopping5);
		m_programLangList.SetItemText(0, 1, str1);
		int hang = CSHOPPINGCART::judge(_T("�ɿڿ���"));
		m_programLangList.SetItemText(hang, 1, (LPTSTR)(LPCTSTR)str1);
	}
}
