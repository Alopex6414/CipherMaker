
// CipherMakerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CipherMaker.h"
#include "CipherMakerDlg.h"
#include "afxdialogex.h"

#include "Common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCipherMakerDlg dialog



CCipherMakerDlg::CCipherMakerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCipherMakerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCipherMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);
}

BEGIN_MESSAGE_MAP(CCipherMakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CCipherMakerDlg::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// CCipherMakerDlg message handlers

BOOL CCipherMakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();
	InitChildLayOut();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCipherMakerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCipherMakerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCipherMakerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//------------------------------------------
// CCipherMakerDlg ~用户定义函数
//------------------------------------------

// CCipherMakerDlg ~初始化窗口形状
void CCipherMakerDlg::InitWindowSharp()
{
	int X = 0;
	int Y = 0;
	int nScreenWidth = 0;
	int nScreenHeight = 0;

	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (nScreenWidth >= USER_WIDTH && nScreenHeight >= USER_HEIGHT)
	{
		X = (nScreenWidth - USER_WIDTH) >> 1;
		Y = (nScreenHeight - USER_HEIGHT) >> 1;
	}

	m_cWindowRect.left = X;
	m_cWindowRect.top = Y;
	m_cWindowRect.right = m_cWindowRect.left + USER_WIDTH;
	m_cWindowRect.bottom = m_cWindowRect.top + USER_HEIGHT;

	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_SHOWWINDOW);
}

// CCipherMakerDlg ~初始化窗口布局
void CCipherMakerDlg::InitWindowLayOut()
{
	CRect Rect;

	GetClientRect(&Rect);

	m_cTabMainRect.left = Rect.left + 10;
	m_cTabMainRect.top = Rect.top + 10;
	m_cTabMainRect.right = Rect.right - 10;
	m_cTabMainRect.bottom = Rect.bottom - 10;

	m_tabMain.SetWindowPos(NULL, m_cTabMainRect.left, m_cTabMainRect.top, m_cTabMainRect.Width(), m_cTabMainRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

// CCipherMakerDlg ~初始化窗口控件布局
void CCipherMakerDlg::InitWindowItemLayOut()
{
	m_tabMain.InsertItem(0, L"EnCrypt");	//加密
	m_tabMain.InsertItem(1, L"DeCrypt");	//解密
	m_tabMain.InsertItem(2, L"Config");		//设置

	m_tabMain.SetCurSel(0);
}

// CCipherMakerDlg ~初始化子窗口布局
void CCipherMakerDlg::InitChildLayOut()
{
	m_cChildRect = m_cTabMainRect;
	m_cChildRect.left += 10;
	m_cChildRect.top += 24;
	m_cChildRect.right -= 10;
	m_cChildRect.bottom -= 5;

	m_cEnCryptDlg.SetWindowRect(m_cChildRect);
	m_cEnCryptDlg.Create(IDD_DIALOG_ENCRYPT, this);
	m_cEnCryptDlg.ShowWindow(SW_SHOW);

	m_cDeCryptDlg.SetWindowRect(m_cChildRect);
	m_cDeCryptDlg.Create(IDD_DIALOG_DECRYPT, this);
	m_cDeCryptDlg.ShowWindow(SW_HIDE);

	m_cConfigDlg.SetWindowRect(m_cChildRect);
	m_cConfigDlg.Create(IDD_DIALOG_CONFIG, this);
	m_cConfigDlg.ShowWindow(SW_HIDE);
}

//------------------------------------------
// CCipherMakerDlg ~控件响应函数
//------------------------------------------

// CCipherMakerDlg ~TabControl选项卡选中改变
void CCipherMakerDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int nCurSel;

	nCurSel = m_tabMain.GetCurSel();
	switch (nCurSel)
	{
	case 0:
		m_cEnCryptDlg.ShowWindow(SW_SHOW);
		m_cDeCryptDlg.ShowWindow(SW_HIDE);
		m_cConfigDlg.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_cEnCryptDlg.ShowWindow(SW_HIDE);
		m_cDeCryptDlg.ShowWindow(SW_SHOW);
		m_cConfigDlg.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_cEnCryptDlg.ShowWindow(SW_HIDE);
		m_cDeCryptDlg.ShowWindow(SW_HIDE);
		m_cConfigDlg.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}

	*pResult = 0;
}
