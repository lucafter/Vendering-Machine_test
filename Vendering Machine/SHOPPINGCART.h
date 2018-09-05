#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSHOPPINGCART 对话框



class CSHOPPINGCART : public CDialogEx
{
	DECLARE_DYNAMIC(CSHOPPINGCART)

public:
	CSHOPPINGCART(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSHOPPINGCART();


	void InitControl();//初始化列表，初始化表头
	static void InsertList(CString str,int num,double price);//修改列表中的信息
	static int judge(CString str);//判断某一个名称的商品位于购物车列表第几行，str就是这个商品的名字


	void addprice();//遍历列表，改变静态文本框里的总价格


	////////////下面这些都是拿来在列表里添加下拉框的/////////////////////////
	int e_Item;    //刚编辑的行  
	int e_SubItem; //刚编辑的列  

	CEdit m_Edit;  //生成单元编辑框对象
	bool haveeditcreate;//标志编辑框已经被创建
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);//创建单元格编辑框函数
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);//销毁单元格编辑框对象

	CComboBox m_comBox;//生产单元格下拉列表对象
	bool haveccomboboxcreate;//标志下拉列表框已经被创建
	void createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat);//创建单元格下拉列表框函数
	void distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem);//销毁

	int numberchangeprice();



// 对话框数据
	enum { IDD = IDD_SHOPPINGCART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);

	
	
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedQuanxuan();
	afx_msg void OnBnClickedFanxuan();

	afx_msg void OnStnClickedSumprice();
	CStatic Price;                                          //静态文本显示总价
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};

 extern CListCtrl m_programLangList;//全局变量