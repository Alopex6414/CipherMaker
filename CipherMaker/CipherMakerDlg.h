
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

// ��Ա
private:
	CRect m_cWindowRect;			//��������ߴ�
	CRect m_cTabMainRect;			//ѡ�����ߴ�
	CRect m_cChildRect;				//�Ӵ�������ߴ�

	CConfigDlg m_cConfigDlg;		//���öԻ���
	CDeCryptDlg m_cDeCryptDlg;		//���ܶԻ���
	CEnCryptDlg m_cEnCryptDlg;		//���ܶԻ���

// ��Ա����
public:
	void InitWindowSharp();			//��ʼ��������״
	void InitWindowLayOut();		//��ʼ�����ڲ���
	void InitWindowItemLayOut();	//��ʼ�����ڿؼ�����
	void InitChildLayOut();			//��ʼ���Ӵ��ڲ���

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
};