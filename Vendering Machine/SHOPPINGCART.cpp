// SHOPPINGCART.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "SHOPPINGCART.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


CListCtrl m_programLangList;

int summeryprice = 0;


// CSHOPPINGCART �Ի���

IMPLEMENT_DYNAMIC(CSHOPPINGCART, CDialogEx)

CSHOPPINGCART::CSHOPPINGCART(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSHOPPINGCART::IDD, pParent)
{

}

CSHOPPINGCART::~CSHOPPINGCART()
{
}

void CSHOPPINGCART::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_programLangList);
	DDX_Control(pDX, IDC_SumPrice, Price);
	DDX_Control(pDX, IDC_LIST1, m_programLangList);
}


BEGIN_MESSAGE_MAP(CSHOPPINGCART, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CSHOPPINGCART::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSHOPPINGCART::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CSHOPPINGCART::OnLvnItemchangedList1)
	//ON_BN_CLICKED(IDC_CHECK2, &CSHOPPINGCART::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_QuanXuan, &CSHOPPINGCART::OnBnClickedQuanxuan)
	ON_BN_CLICKED(IDC_FanXuan, &CSHOPPINGCART::OnBnClickedFanxuan)
	//ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSHOPPINGCART::OnClickListInportdll)
	ON_STN_CLICKED(IDC_SumPrice, &CSHOPPINGCART::OnStnClickedSumprice)
	//ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CSHOPPINGCART::OnNMRClickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSHOPPINGCART::OnNMClickList1)
END_MESSAGE_MAP()


// CSHOPPINGCART ��Ϣ�������


void CSHOPPINGCART::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//������Ʒ�Ի���
}


void CSHOPPINGCART::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(6);//����֧���Ի���
}


BOOL CSHOPPINGCART::OnInitDialog()
{
	CDialogEx::OnInitDialog();

   InitControl();


	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE

	

}


void CSHOPPINGCART::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
	if (((CStatic*)GetDlgItem(IDC_TIME6))->GetSafeHwnd())
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_TIME6);
		ASSERT(pStatic);
		CRect rc;
		pStatic->GetWindowRect(&rc);
		ScreenToClient(&rc);
		InvalidateRect(&rc);
	}

	SetDlgItemText(IDC_TIME6, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CSHOPPINGCART::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
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


HBRUSH CSHOPPINGCART::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_INFO6)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME6)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //����������ɫ
		pDC->SetBkMode(TRANSPARENT); //�������屳��Ϊ͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CSHOPPINGCART::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CSHOPPINGCART::InitControl()
{
	haveeditcreate = false;//��ʼ����־λ����ʾ��û�д����༭��
	haveccomboboxcreate = false;//��ʼ����־λ����ʾ��û�д��������б��
	RECT  m_rect;
	m_programLangList.GetClientRect(&m_rect); //��ȡlist�Ŀͻ���,�������ÿһ�еĿ��  

	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
		LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE |
		LVS_EX_UNDERLINEHOT|LVS_EX_CHECKBOXES;
	m_programLangList.SetExtendedStyle(dwExStyle);

	m_programLangList.InsertColumn(0, _T("��Ʒ"), LVCFMT_CENTER, m_rect.right / 3);
	m_programLangList.InsertColumn(1, _T("����"), LVCFMT_CENTER, m_rect.right / 3);
	m_programLangList.InsertColumn(2, _T("����"), LVCFMT_CENTER, m_rect.right / 3);

	m_programLangList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
	m_programLangList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);

}

void CSHOPPINGCART::InsertList(CString str, int num, double price)
{
	m_programLangList.InsertItem(0, (LPTSTR)(LPCTSTR)str);
	CString strnum;
	strnum.Format(_T("%d"), num);
	CString strprice;
	strprice.Format(_T("%.1lf"),  price);
	m_programLangList.SetItemText(0, 1,  (LPTSTR)(LPCTSTR)strnum);
	m_programLangList.SetItemText(0, 2,  (LPTSTR)(LPCTSTR)strprice);

}


int CSHOPPINGCART::judge(CString str)
{
	int i=0;
	while (str != m_programLangList.GetItemText(i, 0))
	{
		i++;
	}
	return i;

}



void CSHOPPINGCART::OnBnClickedQuanxuan()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_programLangList.GetItemCount(); i++) {
		m_programLangList.SetCheck(i, TRUE);
		m_programLangList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);

		addprice();

	}



}


void CSHOPPINGCART::OnBnClickedFanxuan()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	BOOL state;


	for (int i = 0; i < m_programLangList.GetItemCount(); i++) {
		state = m_programLangList.GetCheck(i);
			if (state == FALSE) {
				m_programLangList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
				m_programLangList.SetCheck(i, TRUE);
			}
			else 
			{
				m_programLangList.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);
				m_programLangList.SetCheck(i, FALSE);

		}
		}

	addprice();

}


//void CSHOPPINGCART::OnClickListInportdll(NMHDR *pNMHDR, LRESULT *pResult)  //NM_CLICK����
//{
//	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//
//	addprice();
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	  // DWORD dwPos = GetMessagePos();
//		//CPoint point(LOWORD(dwPos), HIWORD(dwPos));
//		//m_programLangList.ScreenToClient(&point);
//		//LVHITTESTINFO lvinfo;
//		//lvinfo.pt = point;
//		//lvinfo.flags = LVHT_ABOVE;
//		//int nItem = m_programLangList.SubItemHitTest(&lvinfo);
//		//if (nItem != -1)
//		//{
//			//m_strColumn.Format(_T("%d"), lvinfo.iItem);
//			//UpdateData(FALSE);
//
//		//}
//
//	/*POSITION Pos = m_programLangList.GetFirstSelectedItemPosition();
//	int nSelect = -1;
//
//	while (Pos)
//	{
//		nSelect = m_programLangList.GetNextSelectedItem(Pos);    //nSelect�ܻ�õڼ���
//	}
//
//	CString szFirstTrunk ;
//	szFirstTrunk=m_programLangList.GetItemText(nSelect, 3);  //�����Ҫ����ֵ��szFirstTrunk
//	double temp1= atof((LPSTR)(LPCTSTR)szFirstTrunk) ;
//	double temp2 = summeryprice;
//	double summeryprice =( temp1+temp2);
//	CString ch;
//	ch.Format(_T("%.1lf"), summeryprice);
//	GetDlgItem(IDC_SumPrice)->SetWindowTextW(ch);*/
//	/////////////////////////////////////////////////////
//
//	*pResult = 0;
//}


void CSHOPPINGCART::OnStnClickedSumprice()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


//void CSHOPPINGCART::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult) //�ڶ���ȡ������?????
//{
//	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//
//	//addprice();
//
//	//NM_LISTVIEW *pNMListView = (NM_LISTVIEW*)pNMHDR;
//		//if (pNMListView->iItem != -1)
//		//{
//		//	DWORD dwPos = GetMessagePos();
//		//	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
//			//CMenu menu;
//			//VERIFY(menu.LoadMenu(IDR_MENU));
//			//CMenu *popup = menu.GetSubMenu(0);
//			//ASSERT(popup != NULL);
//			//popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
//		//	* pResult = 0;
//
//		//}
//
//
//
//	*pResult = 0;
//}


void CSHOPPINGCART::addprice()                           //�ܼ۱仯�ĺ���������ʵ��Ϊ��
{   GetDlgItem(IDC_SumPrice)->SetWindowTextW(_T("0.0")); //�Ƚ��ܼ�����

   double temp = 0.0;
   double temp1;
   double temp2;
	for (int i = 0; i<m_programLangList.GetItemCount(); i++)//m_programLangList.GetItemCount()���б��������������ÿһ�ж�����
		{
		if (m_programLangList.GetCheck(i))                 //m_programLangList.GetCheck(i)�����һ�еĸ�ѡ����û�й�ѡ
			{                                              //�����ѡ��
			CString shuliang;
			shuliang = m_programLangList.GetItemText(i, 1);  //�����Ҫ����ֵ��szFirstTrunk��������Ʒ�������͵���
			CString danjia;
			danjia = m_programLangList.GetItemText(i, 2);

			temp1 = atof((LPSTR)(LPCTSTR)shuliang)*atof((LPSTR)(LPCTSTR)danjia);//����������Ʒ���ܼ�
			temp2 = temp;                     
			temp = (temp1 + temp2);
			
			}
		//����������temp�����ܼ۸�д����̬�ı�����
		    CString ch;
			ch.Format(_T("%.1lf"), temp);
			GetDlgItem(IDC_SumPrice)->SetWindowTextW(ch); 
		}

}


void CSHOPPINGCART::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{    
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
   /*GetDlgItem(IDC_SumPrice)->SetWindowTextW(_T("0.0"));

	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));

	m_programLangList.ScreenToClient(&point);

	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;

	UINT nFlag;
	int nItem = m_programLangList.HitTest(point, &nFlag);
	//�ж��Ƿ����checkbox��
	if (nFlag == LVHT_ONITEMSTATEICON)
	{
		
	      
		addprice();
		}


		*/

	//
	////////////������Щ�����������б�������������/////////////////////////

	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	printf("�У�%d���У�%d\n", pEditCtrl->iItem, pEditCtrl->iSubItem);
	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 1)//�����������ѡ��
	{
		if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
			}
			else//���еĵ�Ԫ����֮ǰ�����õ�
			{
				m_Edit.SetFocus();//����Ϊ���� 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
			addprice();
		}
	}
	else//���������ѡ��ڵ�Ԫ�����������б���
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"1");
				m_comBox.AddString(L"2");
				m_comBox.AddString(L"2");
				m_comBox.AddString(L"3");
				m_comBox.AddString(L"4");
				m_comBox.ShowDropDown();//�Զ�����
			}
			else//���еĵ�Ԫ����֮ǰ�����õ�
			{
				m_comBox.SetFocus();//����Ϊ���� 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
			addprice();
			m_comBox.AddString(L"0");
			m_comBox.AddString(L"1");
			m_comBox.AddString(L"2");
			m_comBox.AddString(L"3");
			m_comBox.AddString(L"4");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}


	/////////////////////////ÿ�ε����������²�һ���ܼ۸�仯/////////////////////////////////
	addprice();

	*pResult = 0;
}




////////////������Щ�����������б�������������/////////////////////////
//������Ԫ��༭���� 
//pEditCtrlΪ�б����ָ�룬createditΪ�༭��ָ�����      
//ItemΪ������Ԫ�����б��е��У�SubItem��Ϊ�У�havecreatΪ���󴴽���׼

void CSHOPPINGCART::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, 0/*IDC_EDIT_CREATEID*/);//�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��3000�������¿�ͷ����
	havecreat = true;
	createdit->SetFont(this->GetFont(), FALSE);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_programLangList);//��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_programLangList.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_programLangList.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_programLangList.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createdit->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createdit->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
	createdit->SetFocus();//����Ϊ���� 
	createdit->SetSel(-1);//���ù�����ı������ֵ����
}

void CSHOPPINGCART::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//�����Ӧ��Ԫ���ַ�
	distroyedit->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

//������Ԫ�������б����
//pEditCtrlΪ�б����ָ�룬createccomboboxΪ�����б��ָ�����
//ItemΪ������Ԫ�����б��е��У�SubItem��Ϊ�У�havecreatΪ���󴴽���׼

void CSHOPPINGCART::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, 0/*IDC_COMBOX_CREATEID*/);
	createccomboboxobj->SetFont(this->GetFont(), FALSE);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createccomboboxobj->SetParent(&m_programLangList);//��list control����Ϊ������,���ɵ�Ccombobox������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_programLangList.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_programLangList.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_programLangList.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createccomboboxobj->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createccomboboxobj->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createccomboboxobj->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
}

void CSHOPPINGCART::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//������Ӧ��Ԫ���ַ�
	distroyccomboboxobj->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}


