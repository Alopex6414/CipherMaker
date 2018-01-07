// DeCryptDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CipherMaker.h"
#include "DeCryptDlg.h"
#include "afxdialogex.h"

#include "Common.h"

// CDeCryptDlg �Ի���

IMPLEMENT_DYNAMIC(CDeCryptDlg, CDialogEx)

CDeCryptDlg::CDeCryptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeCryptDlg::IDD, pParent)
{
	Construction();
}

CDeCryptDlg::~CDeCryptDlg()
{
}

void CDeCryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DECRYPT_DECRYPTOPTION, m_gbxDeCryptOptions);
	DDX_Control(pDX, IDC_STATIC_DECRYPT_ORIGINFILEPATH, m_sticOriginPath);
	DDX_Control(pDX, IDC_EDIT_DECRYPT_ORIGINFILEPATH, m_edtOriginPath);
	DDX_Control(pDX, IDC_BUTTON_DECRYPT_ORIGINPATHSELECT, m_btnImport);
	DDX_Control(pDX, IDC_STATIC_DECRYPT_DECRYPTFILEPATH, m_sticDeCryptPath);
	DDX_Control(pDX, IDC_EDIT_DECRYPT_DECRYPTFILEPATH, m_edtDeCryptPath);
	DDX_Control(pDX, IDC_BUTTON_DECRYPT_DECRYPTPATHSELECT, m_btnExport);
	DDX_Control(pDX, IDC_STATIC_DECRYPT_CONVERTSTATE, m_sticConvertStatus);
	DDX_Control(pDX, IDC_STATIC_DECRYPT_CONVERTREMARK, m_sticConvertTip);
	DDX_Control(pDX, IDC_BUTTON_DECRYPT_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON__DECRYPT_OK, m_btnOk);
}


BEGIN_MESSAGE_MAP(CDeCryptDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT_ORIGINPATHSELECT, &CDeCryptDlg::OnBnClickedButtonDecryptOriginpathselect)
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT_DECRYPTPATHSELECT, &CDeCryptDlg::OnBnClickedButtonDecryptDecryptpathselect)
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT_CANCEL, &CDeCryptDlg::OnBnClickedButtonDecryptCancel)
	ON_BN_CLICKED(IDC_BUTTON__DECRYPT_OK, &CDeCryptDlg::OnBnClickedButton)
END_MESSAGE_MAP()


// CDeCryptDlg ��Ϣ�������


BOOL CDeCryptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CDeCryptDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	RePaintWindow(dc);
}

//------------------------------------------
// CDeCryptDlg ~�û����庯��
//------------------------------------------

// CDeCryptDlg ~���캯��
void CDeCryptDlg::Construction()
{
	m_csImport = L"";
	m_csExport = L"";
}

// CDeCryptDlg ~��ʼ��������״
void CDeCryptDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CDeCryptDlg ~��ʼ�����ڲ���
void CDeCryptDlg::InitWindowLayOut()
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
	nHeight = m_cWindowRect.Height() * 5 / 6;
	m_gbxDeCryptOptions.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	TempX = X;
	TempY = Y;

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticOriginPath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticOriginPath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtOriginPath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtOriginPath.GetWindowRect(&Rect);

	X += Rect.Width() + 35;
	Y += 0;
	m_btnImport.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnImport.GetWindowRect(&Rect);

	X = TempX;
	Y = TempY;

	X += 20;
	Y += nHeight / 8 - 5 + Rect.Height() + 50;
	m_sticDeCryptPath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticDeCryptPath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtDeCryptPath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtDeCryptPath.GetWindowRect(&Rect);

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

// CDeCryptDlg ~��ʼ�����ڿؼ�����
void CDeCryptDlg::InitWindowItemLayOut()
{
	// ����״̬Static
	m_sticConvertTip.ShowWindow(SW_HIDE);
}

// CDeCryptDlg ~�ػ洰��
void CDeCryptDlg::RePaintWindow(CDC& dc)
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
// CDeCryptDlg ~�ؼ���Ӧ����
//------------------------------------------

// CDeCryptDlg ~����·��
void CDeCryptDlg::OnBnClickedButtonDecryptOriginpathselect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL bIsOpen = TRUE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"C:\\";
	csFileName = L"";

	CString csCryptType = L"udf";

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
		m_edtOriginPath.SetWindowText(csDefaultPath);

		CString csExportDefaultPath;
		int nPos;

		nPos = csDefaultPath.ReverseFind('.');
		csExportDefaultPath = csDefaultPath.Left(nPos);
		csExportDefaultPath += L"." + csCryptType;
		m_csExport = csExportDefaultPath;
		m_edtDeCryptPath.SetWindowText(csExportDefaultPath);
	}
}

// CDeCryptDlg ~����·��
void CDeCryptDlg::OnBnClickedButtonDecryptDecryptpathselect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL bIsOpen = FALSE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"udf";

	CString csImportPath;
	int nLen;
	int nPos;

	m_edtOriginPath.GetWindowText(csImportPath);
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

	csFileFilter = L"�ļ� (*.udf)|*.udf||";

	CString csCryptType = L"";

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
		m_edtDeCryptPath.SetWindowText(csDefaultPath);
	}
}

// CDeCryptDlg ~ȡ��
void CDeCryptDlg::OnBnClickedButtonDecryptCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetParent()->SendMessage(WM_CLOSE);
	OnCancel();
}

// CDeCryptDlg ~ȷ��
void CDeCryptDlg::OnBnClickedButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString csOriginPath;
	CString csDeCryptPath;

	m_edtOriginPath.GetWindowText(csOriginPath);
	m_edtDeCryptPath.GetWindowText(csDeCryptPath);

	if (csOriginPath != L"" && csDeCryptPath != L"")\
	{
		m_sticConvertTip.SetWindowText(L"Please Wait...");
		m_sticConvertTip.ShowWindow(SW_SHOW);

		CPlumCrypt* pCrypt = new CPlumCrypt;
		char *pArrayOrigin = NULL;
		char *pArrayDeCrypt = NULL;
		int nLen = 0;
		int nPos = 0;

		nPos = csDeCryptPath.ReverseFind('\\');
		csDeCryptPath = csDeCryptPath.Left(nPos);

		nLen = WideCharToMultiByte(CP_ACP, 0, csOriginPath, -1, NULL, 0, NULL, NULL);
		pArrayOrigin = new char[nLen + 1];
		WideCharToMultiByte(CP_ACP, 0, csOriginPath, -1, pArrayOrigin, nLen, NULL, NULL);
		nLen = WideCharToMultiByte(CP_ACP, 0, csDeCryptPath, -1, NULL, 0, NULL, NULL);
		pArrayDeCrypt = new char[nLen + 1];
		WideCharToMultiByte(CP_ACP, 0, csDeCryptPath, -1, pArrayDeCrypt, nLen, NULL, NULL);

		pCrypt->PlumDeCryptFileNoExA((const char*)pArrayOrigin, (const char*)pArrayDeCrypt);

		delete[] pArrayDeCrypt;
		delete[] pArrayOrigin;
		delete pCrypt;

		m_sticConvertTip.SetWindowText(L"Finish!");
		m_sticConvertTip.ShowWindow(SW_HIDE);
		m_sticConvertTip.ShowWindow(SW_SHOW);
	}

}
