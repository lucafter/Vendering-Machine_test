// SHOPPINGCART.cpp : 实现文件
//

#include "stdafx.h"
#include "Vendering Machine.h"
#include "SHOPPINGCART.h"
#include "afxdialogex.h"
#include "Vendering MachineDlg.h"


CListCtrl m_programLangList;

int summeryprice = 0;


// CSHOPPINGCART 对话框

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


// CSHOPPINGCART 消息处理程序


void CSHOPPINGCART::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);//跳到商品对话框
}


void CSHOPPINGCART::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CVenderingMachineDlg *pMMD = (CVenderingMachineDlg*)AfxGetMainWnd();
	pMMD->ShowPage(6);//跳到支付对话框
}


BOOL CSHOPPINGCART::OnInitDialog()
{
	CDialogEx::OnInitDialog();

   InitControl();


	// TODO:  在此添加额外的初始化
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE

	

}


void CSHOPPINGCART::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
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


HBRUSH CSHOPPINGCART::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_INFO6)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID() == IDC_TIME6)
	{
		pDC->SetTextColor(RGB(0, 0, 0));   //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSHOPPINGCART::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void CSHOPPINGCART::InitControl()
{
	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框
	RECT  m_rect;
	m_programLangList.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度  

	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
		LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE |
		LVS_EX_UNDERLINEHOT|LVS_EX_CHECKBOXES;
	m_programLangList.SetExtendedStyle(dwExStyle);

	m_programLangList.InsertColumn(0, _T("商品"), LVCFMT_CENTER, m_rect.right / 3);
	m_programLangList.InsertColumn(1, _T("数量"), LVCFMT_CENTER, m_rect.right / 3);
	m_programLangList.InsertColumn(2, _T("单价"), LVCFMT_CENTER, m_rect.right / 3);

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
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < m_programLangList.GetItemCount(); i++) {
		m_programLangList.SetCheck(i, TRUE);
		m_programLangList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);

		addprice();

	}



}


void CSHOPPINGCART::OnBnClickedFanxuan()
{
	// TODO:  在此添加控件通知处理程序代码

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


//void CSHOPPINGCART::OnClickListInportdll(NMHDR *pNMHDR, LRESULT *pResult)  //NM_CLICK单击
//{
//	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//
//	addprice();
//	// TODO:  在此添加控件通知处理程序代码
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
//		nSelect = m_programLangList.GetNextSelectedItem(Pos);    //nSelect能获得第几行
//	}
//
//	CString szFirstTrunk ;
//	szFirstTrunk=m_programLangList.GetItemText(nSelect, 3);  //获得想要的列值给szFirstTrunk
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
	// TODO:  在此添加控件通知处理程序代码
}


//void CSHOPPINGCART::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult) //第二次取消单击?????
//{
//	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO:  在此添加控件通知处理程序代码
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


void CSHOPPINGCART::addprice()                           //总价变化的函数，具体实现为：
{   GetDlgItem(IDC_SumPrice)->SetWindowTextW(_T("0.0")); //先将总价置零

   double temp = 0.0;
   double temp1;
   double temp2;
	for (int i = 0; i<m_programLangList.GetItemCount(); i++)//m_programLangList.GetItemCount()是列表的总行数，就是每一行都遍历
		{
		if (m_programLangList.GetCheck(i))                 //m_programLangList.GetCheck(i)检查这一行的复选框有没有勾选
			{                                              //如果勾选了
			CString shuliang;
			shuliang = m_programLangList.GetItemText(i, 1);  //获得想要的列值给szFirstTrunk，就是商品的数量和单价
			CString danjia;
			danjia = m_programLangList.GetItemText(i, 2);

			temp1 = atof((LPSTR)(LPCTSTR)shuliang)*atof((LPSTR)(LPCTSTR)danjia);//这就是这件商品的总价
			temp2 = temp;                     
			temp = (temp1 + temp2);
			
			}
		//遍历结束，temp就是总价格，写到静态文本框里
		    CString ch;
			ch.Format(_T("%.1lf"), temp);
			GetDlgItem(IDC_SumPrice)->SetWindowTextW(ch); 
		}

}


void CSHOPPINGCART::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{    
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
   /*GetDlgItem(IDC_SumPrice)->SetWindowTextW(_T("0.0"));

	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));

	m_programLangList.ScreenToClient(&point);

	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;

	UINT nFlag;
	int nItem = m_programLangList.HitTest(point, &nFlag);
	//判断是否点在checkbox上
	if (nFlag == LVHT_ONITEMSTATEICON)
	{
		
	      
		addprice();
		}


		*/

	//
	////////////下面这些都是拿来在列表里添加下拉框的/////////////////////////

	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	printf("行：%d，列：%d\n", pEditCtrl->iItem, pEditCtrl->iSubItem);
	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 1)//如果不是数量选项
	{
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
			}
			else//点中的单元格是之前创建好的
			{
				m_Edit.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
			addprice();
		}
	}
	else//如果是数量选项，在单元格处生成下拉列表项
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_programLangList, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_programLangList, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"1");
				m_comBox.AddString(L"2");
				m_comBox.AddString(L"2");
				m_comBox.AddString(L"3");
				m_comBox.AddString(L"4");
				m_comBox.ShowDropDown();//自动下拉
			}
			else//点中的单元格是之前创建好的
			{
				m_comBox.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
			addprice();
			m_comBox.AddString(L"0");
			m_comBox.AddString(L"1");
			m_comBox.AddString(L"2");
			m_comBox.AddString(L"3");
			m_comBox.AddString(L"4");
			m_comBox.ShowDropDown();//自动下拉
		}
	}


	/////////////////////////每次单击，都重新查一遍总价格变化/////////////////////////////////
	addprice();

	*pResult = 0;
}




////////////下面这些都是拿来在列表里添加下拉框的/////////////////////////
//创建单元格编辑框函数 
//pEditCtrl为列表对象指针，createdit为编辑框指针对象，      
//Item为创建单元格在列表中的行，SubItem则为列，havecreat为对象创建标准

void CSHOPPINGCART::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, 0/*IDC_EDIT_CREATEID*/);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号3000，在文章开头定义
	havecreat = true;
	createdit->SetFont(this->GetFont(), FALSE);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_programLangList);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_programLangList.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_programLangList.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_programLangList.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void CSHOPPINGCART::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

//创建单元格下拉列表框函数
//pEditCtrl为列表对象指针，createccombobox为下拉列表框指针对象，
//Item为创建单元格在列表中的行，SubItem则为列，havecreat为对象创建标准

void CSHOPPINGCART::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, 0/*IDC_COMBOX_CREATEID*/);
	createccomboboxobj->SetFont(this->GetFont(), FALSE);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_programLangList);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_programLangList.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_programLangList.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_programLangList.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void CSHOPPINGCART::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}


