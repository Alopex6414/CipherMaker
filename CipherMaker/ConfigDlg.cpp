// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CipherMaker.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"


// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialogEx)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfigDlg::IDD, pParent)
	, m_ridUseMsg(0)
	, m_ridNoUseMsg(0)
{
	Construction();
}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_CONFIG_CRYPTTYPE, m_gbxCryptType);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LUCKYNUMBER, m_gbxLuckyNumber);
	DDX_Control(pDX, IDC_STATIC_CONFIG_CRYPTTYPESELECT, m_sticCryptTypeTip);
	DDX_Control(pDX, IDC_STATIC_CONFIG_CHANGELUCKYNUMBER, m_sticLuckyNumberTip);
	DDX_Control(pDX, IDC_STATIC_CONFIG_ARR1, m_sticArray1);
	DDX_Control(pDX, IDC_STATIC_CONFIG_ARR2, m_sticArray2);
	DDX_Control(pDX, IDC_STATIC_CONFIG_ARR3, m_sticArray3);
	DDX_Control(pDX, IDC_STATIC_CONFIG_ARR4, m_sticArray4);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER1, m_edtLucky1);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER2, m_edtLucky2);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER3, m_edtLucky3);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER4, m_edtLucky4);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER5, m_edtLucky5);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER6, m_edtLucky6);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER7, m_edtLucky7);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER8, m_edtLucky8);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER9, m_edtLucky9);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER10, m_edtLucky10);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER11, m_edtLucky11);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER12, m_edtLucky12);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER13, m_edtLucky13);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER14, m_edtLucky14);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER15, m_edtLucky15);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKYNUMBER16, m_edtLucky16);
	DDX_Control(pDX, IDC_STATIC_CONFIG1, m_sticLink1);
	DDX_Control(pDX, IDC_STATIC_CONFIG2, m_sticLink2);
	DDX_Control(pDX, IDC_STATIC_CONFIG3, m_sticLink3);
	DDX_Control(pDX, IDC_STATIC_CONFIG4, m_sticLink4);
	DDX_Control(pDX, IDC_STATIC_CONFIG5, m_sticLink5);
	DDX_Control(pDX, IDC_STATIC_CONFIG6, m_sticLink6);
	DDX_Control(pDX, IDC_STATIC_CONFIG7, m_sticLink7);
	DDX_Control(pDX, IDC_STATIC_CONFIG8, m_sticLink8);
	DDX_Control(pDX, IDC_STATIC_CONFIG9, m_sticLink9);
	DDX_Control(pDX, IDC_STATIC_CONFIG10, m_sticLink10);
	DDX_Control(pDX, IDC_STATIC_CONFIG11, m_sticLink11);
	DDX_Control(pDX, IDC_STATIC_CONFIG12, m_sticLink12);
	DDX_Control(pDX, IDC_BUTTON_CONFIG_DEFAULT, m_btnDefault);
	DDX_Control(pDX, IDC_BUTTON_CONFIG_SAVE, m_btnSave);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_CONFIG_DEFAULT, &CConfigDlg::OnBnClickedButtonConfigDefault)
	ON_BN_CLICKED(IDC_BUTTON_CONFIG_SAVE, &CConfigDlg::OnBnClickedButtonConfigSave)
END_MESSAGE_MAP()


// CConfigDlg 消息处理程序

BOOL CConfigDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CConfigDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	RePaintWindow(dc);
}

//------------------------------------------
// CConfigDlg ~用户定义函数
//------------------------------------------

// CConfigDlg ~构造函数
void CConfigDlg::Construction()
{
	m_ridUseMsg = 0;
	m_ridNoUseMsg = 0;
}

// CConfigDlg ~初始化窗口形状
void CConfigDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CConfigDlg ~初始化窗口布局
void CConfigDlg::InitWindowLayOut()
{
	int X = 0;
	int Y = 0;
	int nWidth = 0;
	int nHeight = 0;
	int TempX = 0;
	int TempY = 0;
	CRect Rect;

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() / 6;
	m_gbxCryptType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	m_sticCryptTypeTip.ShowWindow(SW_HIDE);

	X += 50;
	Y += nHeight / 2 - 5;
	GetDlgItem(IDC_RADIO_CONFIG_USE_MSG)->SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	GetDlgItem(IDC_RADIO_CONFIG_USE_MSG)->GetWindowRect(&Rect);

	X += Rect.Width() + 250;
	Y += 0;
	GetDlgItem(IDC_RADIO_CONFIG_NOUSE_MSG2)->SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	GetDlgItem(IDC_RADIO_CONFIG_NOUSE_MSG2)->GetWindowRect(&Rect);

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top + m_cWindowRect.Height() / 6 + 5;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() * 2 / 3;
	m_gbxLuckyNumber.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	TempX = X;
	TempY = Y;

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticLuckyNumberTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLuckyNumberTip.GetWindowRect(&Rect);

	TempX = X;
	TempY = Y;

	//Array1
	X += 30;
	Y += Rect.Height() + 20;
	m_sticArray1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray1.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky1.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink1.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky2.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink2.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky3.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink3.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky4.GetWindowRect(&Rect);

	//Array2
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 2 - 10;
	m_sticArray2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray2.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky5.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky5.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink4.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky6.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky6.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink5.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink5.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky7.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky7.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink6.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink6.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky8.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky8.GetWindowRect(&Rect);

	//Array3
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 3 - 10;
	m_sticArray3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray3.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky9.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky9.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink7.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink7.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky10.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky10.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink8.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink8.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky11.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky11.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink9.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink9.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky12.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky12.GetWindowRect(&Rect);

	//Array3
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 4 - 10;
	m_sticArray4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray4.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky13.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky13.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink10.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink10.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky14.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky14.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink11.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink11.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky15.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky15.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink12.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink12.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky16.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky16.GetWindowRect(&Rect);

	X = m_cWindowRect.right - 75;
	Y = m_cWindowRect.bottom - 24;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height();
	m_btnSave.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnSave.GetWindowRect(&Rect);

	X += -Rect.Width() - 20;
	Y += 0;
	m_btnDefault.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnDefault.GetWindowRect(&Rect);
}

// CConfigDlg ~初始化窗口控件布局
void CConfigDlg::InitWindowItemLayOut()
{
	((CButton*)GetDlgItem(IDC_RADIO_CONFIG_USE_MSG))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_CONFIG_NOUSE_MSG2))->SetCheck(FALSE);
}

// CConfigDlg ~重绘窗口
void CConfigDlg::RePaintWindow(CDC& dc)
{
	CDC MemDC;
	CBitmap MemBitmap;
	CRect MemRect;

	GetClientRect(&MemRect);

	MemDC.CreateCompatibleDC(&dc);
	MemBitmap.CreateCompatibleBitmap(&dc, MemRect.Width(), MemRect.Height());

	MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(&MemRect, RGB(255, 255, 255)); // RGB(110, 142, 199)

	dc.BitBlt(m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), &MemDC, MemRect.left, MemRect.top, SRCCOPY);

	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}

//------------------------------------------
// CConfigDlg ~控件响应函数
//------------------------------------------

// CConfigDlg ~默认
void CConfigDlg::OnBnClickedButtonConfigDefault()
{
	// TODO:  在此添加控件通知处理程序代码
}

// CConfigDlg ~保存
void CConfigDlg::OnBnClickedButtonConfigSave()
{
	// TODO:  在此添加控件通知处理程序代码
}
