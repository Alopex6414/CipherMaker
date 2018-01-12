
// CipherMakerDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include "ConfigDlg.h"
#include "DeCryptDlg.h"
#include "EnCryptDlg.h"


// CCipherMakerDlg dialog
class CCipherMakerDlg : public CDialogEx
{
// Construction
public:
	CCipherMakerDlg(CWnd* pParent = NULL);	// standard constructor

// 成员
private:
	CRect m_cWindowRect;			//窗口区域尺寸
	CRect m_cTabMainRect;			//选项卡区域尺寸
	CRect m_cChildRect;				//子窗口区域尺寸

	CConfigDlg m_cConfigDlg;		//设置对话框
	CDeCryptDlg m_cDeCryptDlg;		//解密对话框
	CEnCryptDlg m_cEnCryptDlg;		//加密对话框

public:
	CString m_csArray[16];
	CString m_csCheck;
	int m_nArray[16];
	int m_nCheck;

// 成员函数
public:
	void Construction();			//初始化构造函数
	void InitWindowSharp();			//初始化窗口形状
	void InitWindowLayOut();		//初始化窗口布局
	void InitWindowItemLayOut();	//初始化窗口控件布局
	void InitChildLayOut();			//初始化子窗口布局

	void ReadConfigFile();			//读取配置文件
	void WriteConfigFile();			//写入配置文件
	void ArrayCopy(int* pSrc, int* pDest, int nLen);

// Dialog Data
	enum { IDD = IDD_CIPHERMAKER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabMain;
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnCancel();
};
