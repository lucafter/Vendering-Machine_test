#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSHOPPINGCART �Ի���



class CSHOPPINGCART : public CDialogEx
{
	DECLARE_DYNAMIC(CSHOPPINGCART)

public:
	CSHOPPINGCART(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSHOPPINGCART();


	void InitControl();//��ʼ���б���ʼ����ͷ
	static void InsertList(CString str,int num,double price);//�޸��б��е���Ϣ
	static int judge(CString str);//�ж�ĳһ�����Ƶ���Ʒλ�ڹ��ﳵ�б�ڼ��У�str���������Ʒ������


	void addprice();//�����б��ı侲̬�ı�������ܼ۸�


	////////////������Щ�����������б�������������/////////////////////////
	int e_Item;    //�ձ༭����  
	int e_SubItem; //�ձ༭����  

	CEdit m_Edit;  //���ɵ�Ԫ�༭�����
	bool haveeditcreate;//��־�༭���Ѿ�������
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);//������Ԫ��༭����
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);//���ٵ�Ԫ��༭�����

	CComboBox m_comBox;//������Ԫ�������б����
	bool haveccomboboxcreate;//��־�����б���Ѿ�������
	void createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat);//������Ԫ�������б����
	void distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem);//����

	int numberchangeprice();



// �Ի�������
	enum { IDD = IDD_SHOPPINGCART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	CStatic Price;                                          //��̬�ı���ʾ�ܼ�
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};

 extern CListCtrl m_programLangList;//ȫ�ֱ���