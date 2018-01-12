#pragma once
#include "afxwin.h"


// CDeCryptDlg 对话框

class CDeCryptDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeCryptDlg)

public:
	CDeCryptDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeCryptDlg();

// 成员
private:
	CRect m_cWindowRect;

	CString m_csImport;
	CString m_csExport;

public:
	int m_nArray[16];
	int m_nCheck;

// 成员函数
public:
	void Construction();

	const void SetWindowRect(CRect& Rect) { m_cWindowRect = Rect; }
	void SetWindowData(int* pArray, int nCheck);
	void InitWindowSharp();
	void InitWindowLayOut();
	void InitWindowItemLayOut();

	void RePaintWindow(CDC& dc);

// 对话框数据
	enum { IDD = IDD_DIALOG_DECRYPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CStatic m_gbxDeCryptOptions;
	CStatic m_sticOriginPath;
	CEdit m_edtOriginPath;
	CButton m_btnImport;
	CStatic m_sticDeCryptPath;
	CEdit m_edtDeCryptPath;
	CButton m_btnExport;
	CStatic m_sticConvertStatus;
	CStatic m_sticConvertTip;
	CButton m_btnCancel;
	CButton m_btnOk;
	afx_msg void OnBnClickedButtonDecryptOriginpathselect();
	afx_msg void OnBnClickedButtonDecryptDecryptpathselect();
	afx_msg void OnBnClickedButtonDecryptCancel();
	afx_msg void OnBnClickedButton();
};
