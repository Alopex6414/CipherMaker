// EnCryptDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CipherMaker.h"
#include "EnCryptDlg.h"
#include "afxdialogex.h"

#include "Common.h"


// CEnCryptDlg 对话框

IMPLEMENT_DYNAMIC(CEnCryptDlg, CDialogEx)

CEnCryptDlg::CEnCryptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEnCryptDlg::IDD, pParent)
{
	Construction();
}

CEnCryptDlg::~CEnCryptDlg()
{
	m_Brush.DeleteObject();
}

void CEnCryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_CONFIG, m_gbxConfig);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_ENCRYPTOPTION, m_gbxOption);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_ORIGINFILETYPE, m_sticOriginFileType);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_ENCRYPTFILETYPE, m_sticEnCryptFileType);
	DDX_Control(pDX, IDC_COMBO_ENCRYPT_ORIGINFILETYPE, m_cbxOriginFileType);
	DDX_Control(pDX, IDC_EDIT_ENCRYPT_ENCRYPTFILETYPE, m_edtEnCryptFileType);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_ORIGINFILEPATH, m_sticOriginFilePath);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_ENCRYPTFILEPATH, m_sticEnCryptFilePath);
	DDX_Control(pDX, IDC_EDIT_ENCRYPT_ORIGINFILEPATH, m_edtOriginFitePath);
	DDX_Control(pDX, IDC_EDIT_ENCRYPT_ENCRYPTFILEPATH, m_edtEnCryptFilePath);
	DDX_Control(pDX, IDC_BUTTON_ENCRYPT_ORIGINPATHSELECT, m_btnImport);
	DDX_Control(pDX, IDC_BUTTON_ENCRYPT_ENCRYPTPATHSELECT, m_btnExport);
	DDX_Control(pDX, IDC_BUTTON_ENCRYPT_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_ENCRYPT_OK, m_btnOk);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_CONVERTSTATE, m_sticConvertStatus);
	DDX_Control(pDX, IDC_STATIC_ENCRYPT_CONVERTREMARK, m_sticConvertTip);
}


BEGIN_MESSAGE_MAP(CEnCryptDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT_ORIGINPATHSELECT, &CEnCryptDlg::OnBnClickedButtonEncryptOriginpathselect)
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT_ENCRYPTPATHSELECT, &CEnCryptDlg::OnBnClickedButtonEncryptEncryptpathselect)
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT_CANCEL, &CEnCryptDlg::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT_OK, &CEnCryptDlg::OnBnClickedButtonOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEnCryptDlg 消息处理程序

BOOL CEnCryptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CEnCryptDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	RePaintWindow(dc);
}

HBRUSH CEnCryptDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(255, 255, 255));
		return m_Brush;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CEnCryptDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
}

//------------------------------------------
// CEnCryptDlg ~用户定义函数
//------------------------------------------

// CEnCryptDlg ~构造函数
void CEnCryptDlg::Construction()
{
	m_csImport = L"";
	m_csExport = L"";

	m_nCheck = 0;
	memset(m_nArray, 0, 16);

	m_nArray[0] = 170;
	m_nArray[1] = 187;
	m_nArray[2] = 204;
	m_nArray[3] = 221;

	m_nArray[4] = 18;
	m_nArray[5] = 72;
	m_nArray[6] = 132;
	m_nArray[7] = 33;

	m_nArray[8] = 18;
	m_nArray[9] = 52;
	m_nArray[10] = 86;
	m_nArray[11] = 120;

	m_nArray[12] = 255;
	m_nArray[13] = 255;
	m_nArray[14] = 255;
	m_nArray[15] = 255;

	m_Brush.CreateSolidBrush(RGB(255, 255, 255));
}

// CEnCryptDlg ~初始化窗口形状
void CEnCryptDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CEnCryptDlg ~设置窗口数据
void CEnCryptDlg::SetWindowData(int* pArray, int nCheck)
{
	m_nCheck = nCheck;
	for (int i = 0; i < 16; ++i)
	{
		m_nArray[i] = *(pArray + i);
	}
}

// CEnCryptDlg ~初始化窗口布局
void CEnCryptDlg::InitWindowLayOut()
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
	m_gbxConfig.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	X += 20;
	Y += nHeight / 2 - 5;
	m_sticOriginFileType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticOriginFileType.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -2;
	m_cbxOriginFileType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_cbxOriginFileType.GetWindowRect(&Rect);

	X += Rect.Width() + 90;
	Y += 2;
	m_sticEnCryptFileType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticEnCryptFileType.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -4;
	m_edtEnCryptFileType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtEnCryptFileType.GetWindowRect(&Rect);

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top + m_cWindowRect.Height() / 6 + 5;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() * 2 / 3;
	m_gbxOption.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	TempX = X;
	TempY = Y;

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticOriginFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticOriginFilePath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtOriginFitePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtOriginFitePath.GetWindowRect(&Rect);

	X += Rect.Width() + 35;
	Y += 0;
	m_btnImport.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnImport.GetWindowRect(&Rect);

	X = TempX;
	Y = TempY;

	X += 20;
	Y += nHeight / 8 - 5 + Rect.Height() + 50;
	m_sticEnCryptFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticEnCryptFilePath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtEnCryptFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtEnCryptFilePath.GetWindowRect(&Rect);

	X += Rect.Width() + 35;
	Y += 0;
	m_btnExport.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnExport.GetWindowRect(&Rect);

	X = TempX;
	Y = TempY;

	X += 20;
	Y += nHeight / 8 - 5 + (Rect.Height() + 50) * 2;
	m_sticConvertStatus.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticConvertStatus.GetWindowRect(&Rect);

	X += 20;
	Y += Rect.Height() + 20;
	m_sticConvertTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticConvertTip.GetWindowRect(&Rect);

	X = m_cWindowRect.right - 75;
	Y = m_cWindowRect.bottom - 24;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height();
	m_btnOk.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnOk.GetWindowRect(&Rect);

	X += -Rect.Width() - 20;
	Y += 0;
	m_btnCancel.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnCancel.GetWindowRect(&Rect);
}

// CEnCryptDlg ~初始化窗口控件布局
void CEnCryptDlg::InitWindowItemLayOut()
{
	// 关于ComboBox设置
	m_cbxOriginFileType.ResetContent();

	m_cbxOriginFileType.InsertString(0, L"No Filter");
	m_cbxOriginFileType.InsertString(1, L"PNG");
	m_cbxOriginFileType.InsertString(2, L"JPG");
	m_cbxOriginFileType.InsertString(3, L"BMP");
	m_cbxOriginFileType.InsertString(4, L"WAV");
	m_cbxOriginFileType.InsertString(5, L"MID");

	m_cbxOriginFileType.SetCurSel(0);

	// 关于Edit设置
	m_edtEnCryptFileType.LimitText(3);

	// 关于状态Static
	m_sticConvertTip.ShowWindow(SW_HIDE);
}

// CEnCryptDlg ~重绘窗口
void CEnCryptDlg::RePaintWindow(CDC& dc)
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
// CEnCryptDlg ~控件响应函数
//------------------------------------------

// CEnCryptDlg ~导入路径
void CEnCryptDlg::OnBnClickedButtonEncryptOriginpathselect()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = TRUE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;
	
	int nCurSel;
	CString csTemp;

	csDefaultDir = L"C:\\";
	csFileName = L"";

	nCurSel = m_cbxOriginFileType.GetCurSel();
	m_cbxOriginFileType.GetLBText(nCurSel, csTemp);
	if (csTemp == L"No Filter")
	{
		csFileFilter = L"文件|||";
	}
	else
	{
		csFileFilter = L"文件 (*." + csTemp + L")|*." + csTemp + L"||";
	}

	CString csCryptType = L"";

	m_edtEnCryptFileType.GetWindowText(csCryptType);
	if (csCryptType == L"")
	{
		MessageBox(L"EnCrypt File Type Can not be Empty!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}
	else if (csCryptType.Find('.') != -1)
	{
		MessageBox(L"EnCrypt File Type Can not have '.'!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	CString csDefaultPath;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_HIDEREADONLY | OFN_READONLY | OFN_NOCHANGEDIR, csFileFilter, NULL);
	INT_PTR nResult;

	if (m_csImport == L"")
	{
		GetModuleFileName(AfxGetInstanceHandle(), csDefaultPath.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
		csDefaultPath = csDefaultPath.Left(csDefaultPath.ReverseFind('\\'));
	}
	else
	{
		csDefaultPath = m_csImport;
	}

	FileDlg.GetOFN().lpstrInitialDir = csDefaultPath;
	nResult = FileDlg.DoModal();
	if (nResult == IDOK)
	{
		csDefaultPath = FileDlg.GetPathName();
		m_csImport = csDefaultPath;
		m_edtOriginFitePath.SetWindowText(csDefaultPath);

		CString csExportDefaultPath;
		int nPos;

		nPos = csDefaultPath.ReverseFind('.');
		csExportDefaultPath = csDefaultPath.Left(nPos);
		csExportDefaultPath += L"." + csCryptType;
		m_csExport = csExportDefaultPath;
		m_edtEnCryptFilePath.SetWindowText(csExportDefaultPath);
	}

}

// CEnCryptDlg ~导出路径
void CEnCryptDlg::OnBnClickedButtonEncryptEncryptpathselect()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = FALSE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"C:\\";

	CString csImportPath;
	int nLen;
	int nPos;

	m_edtOriginFitePath.GetWindowText(csImportPath);
	if (csImportPath == L"")
	{
		MessageBox(L"Please Select Import File Path!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	nLen = csImportPath.GetLength();
	nPos = csImportPath.ReverseFind('\\');
	csImportPath = csImportPath.Right(nLen - nPos - 1);
	nPos = csImportPath.ReverseFind('.');
	csFileName = csImportPath.Left(nPos);

	CString csCryptType = L"";

	m_edtEnCryptFileType.GetWindowText(csCryptType);
	if (csCryptType == L"")
	{
		MessageBox(L"EnCrypt File Type Can not be Empty!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}
	else if (csCryptType.Find('.') != -1)
	{
		MessageBox(L"EnCrypt File Type Can not have '.'!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	csFileFilter = L"文件 (*." + csCryptType + L")|*." + csCryptType + L"||";

	CString csDefaultPath;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, csFileFilter, NULL);
	INT_PTR nResult;

	if (m_csExport == L"")
	{
		GetModuleFileName(AfxGetInstanceHandle(), csDefaultPath.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
		csDefaultPath = csDefaultPath.Left(csDefaultPath.ReverseFind('\\'));
	}
	else
	{
		csDefaultPath = m_csExport;
	}

	FileDlg.GetOFN().lpstrInitialDir = csDefaultPath;
	nResult = FileDlg.DoModal();
	if (nResult == IDOK)
	{
		csDefaultPath = FileDlg.GetPathName();
		m_csExport = csDefaultPath;
		m_edtEnCryptFilePath.SetWindowText(csDefaultPath);
	}

}

// CEnCryptDlg ~取消
void CEnCryptDlg::OnBnClickedButtonCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	GetParent()->SendMessage(WM_CLOSE);
	OnCancel();
}

// CEnCryptDlg ~确认
void CEnCryptDlg::OnBnClickedButtonOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString csOriginPath;
	CString csEnCryptPath;

	m_edtOriginFitePath.GetWindowText(csOriginPath);
	m_edtEnCryptFilePath.GetWindowText(csEnCryptPath);

	if (csOriginPath != L"" && csEnCryptPath != L"")
	{
		m_sticConvertTip.SetWindowText(L"Please Wait...");
		m_sticConvertTip.ShowWindow(SW_SHOW);

		DWORD dwLuckyNumberArr[4] =
		{
			0x00000000,
			0x00000000,
			0x00000000,
			0x00000000,
		};

		CPlumCrypt* pCrypt = new CPlumCrypt;
		char *pArrayOrigin = NULL;
		char *pArrayEnCrypt = NULL;
		int nLen = 0;

		for (int i = 0; i < 4; ++i)
		{
			dwLuckyNumberArr[i] = m_nArray[4 * i + 0] * (1 << 24)
								+ m_nArray[4 * i + 1] * (1 << 16)
								+ m_nArray[4 * i + 2] * (1 << 8)
								+ m_nArray[4 * i + 3] * (1 << 0);
		}

		nLen = WideCharToMultiByte(CP_ACP, 0, csOriginPath, -1, NULL, 0, NULL, NULL);
		pArrayOrigin = new char[nLen + 1];
		WideCharToMultiByte(CP_ACP, 0, csOriginPath, -1, pArrayOrigin, nLen, NULL, NULL);
		nLen = WideCharToMultiByte(CP_ACP, 0, csEnCryptPath, -1, NULL, 0, NULL, NULL);
		pArrayEnCrypt = new char[nLen + 1];
		WideCharToMultiByte(CP_ACP, 0, csEnCryptPath, -1, pArrayEnCrypt, nLen, NULL, NULL);

		pCrypt->PlumEnCryptFileExA((const char*)pArrayOrigin, (const char*)pArrayEnCrypt, dwLuckyNumberArr);

		delete[] pArrayEnCrypt;
		delete[] pArrayOrigin;
		delete pCrypt;

		m_sticConvertTip.SetWindowText(L"Finish!");
		m_sticConvertTip.ShowWindow(SW_HIDE);
		m_sticConvertTip.ShowWindow(SW_SHOW);
	}

}
