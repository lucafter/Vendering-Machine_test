#pragma once



// CMyFormView1 ������ͼ

class CMyFormView1 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView1)

protected:
	CMyFormView1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyFormView1();

public:
	enum { IDD = IDD_GOODS };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


#pragma once



// CMyFormView1 ������ͼ

class CMyFormView1 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView1)

protected:
	CMyFormView1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyFormView1();

public:
	enum { IDD = IDD_GOODS };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


