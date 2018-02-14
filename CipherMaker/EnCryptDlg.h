#pragma once
#include "afxwin.h"


// CEnCryptDlg �Ի���

class CEnCryptDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEnCryptDlg)

public:
	CEnCryptDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEnCryptDlg();

// ��Ա
private:
	CRect m_cWindowRect;

	CString m_csImport;
	CString m_csExport;

	CBrush m_Brush;

public:
	int m_nArray[16];
	int m_nCheck;

// ��Ա����
public:
	void Construction();

	const void SetWindowRect(CRect& Rect) { m_cWindowRect = Rect; }
	void SetWindowData(int* pArray, int nCheck);
	void InitWindowSharp();
	void InitWindowLayOut();
	void InitWindowItemLayOut();

	void RePaintWindow(CDC& dc);

// �Ի�������
	enum { IDD = IDD_DIALOG_ENCRYPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CStatic m_gbxConfig;
	CStatic m_gbxOption;
	CStatic m_sticOriginFileType;
	CStatic m_sticEnCryptFileType;
	CComboBox m_cbxOriginFileType;
	CEdit m_edtEnCryptFileType;
	CStatic m_sticOriginFilePath;
	CStatic m_sticEnCryptFilePath;
	CEdit m_edtOriginFitePath;
	CEdit m_edtEnCryptFilePath;
	CStatic m_sticConvertStatus;
	CStatic m_sticConvertTip;
	CButton m_btnImport;
	CButton m_btnExport;
	CButton m_btnCancel;
	CButton m_btnOk;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonEncryptOriginpathselect();
	afx_msg void OnBnClickedButtonEncryptEncryptpathselect();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnBnClickedButtonOk();
};
