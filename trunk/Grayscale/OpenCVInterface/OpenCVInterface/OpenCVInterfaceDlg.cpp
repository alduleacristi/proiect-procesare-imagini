
// OpenCVInterfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "OpenCVInterfaceDlg.h"
#include "afxdialogex.h"

#include <time.h>

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


// COpenCVInterfaceDlg dialog




COpenCVInterfaceDlg::COpenCVInterfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenCVInterfaceDlg::IDD, pParent)
	, ImageBrush(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


COpenCVInterfaceDlg::~COpenCVInterfaceDlg()
{
	if(ImageBrush) delete ImageBrush;
}
void COpenCVInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenCVInterfaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN32771, &COpenCVInterfaceDlg::OnFileOpen32771)
	ON_COMMAND(ID_TOOLS_INVERT, &COpenCVInterfaceDlg::OnToolsInvert)
	ON_COMMAND(ID_LOAD_IM, &COpenCVInterfaceDlg::OnLoadPrelImage)
	ON_COMMAND(ID_FILE_SAVE32776, &COpenCVInterfaceDlg::OnFileSave32776)
END_MESSAGE_MAP()


// COpenCVInterfaceDlg message handlers

BOOL COpenCVInterfaceDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COpenCVInterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void COpenCVInterfaceDlg::ResetImageBrush(void)
{
	CBitmap bmpB;
	int nrPixels=mainImage.cols*mainImage.rows;
	COLORREF *RGB_buffer=new COLORREF[nrPixels];
	for(int x=0;x<nrPixels;x++)
	{
		int i=x/mainImage.cols;
		int j=x%mainImage.cols;
		//RGB_buffer[x]=RGB(mainImage.at<Vec3b>(i,j)[0],mainImage.at<Vec3b>(i,j)[1],mainImage.at<Vec3b>(i,j)[2]);
		RGB_buffer[x]=RGB(mainImage.at<uchar>(i,j),mainImage.at<uchar>(i,j),mainImage.at<uchar>(i,j));
	}
	
	
	bmpB.CreateBitmap(mainImage.cols,mainImage.rows,4,8,RGB_buffer);
	delete []RGB_buffer;
	if(ImageBrush) delete ImageBrush;
	ImageBrush=new CBrush(&bmpB);
}
void COpenCVInterfaceDlg::OnPaint()
{
		CPaintDC dc(this); // device context for painting

		//In variabila r1 pastrez dimensiunile ferestrei picture1
		CRect r1;
		GetClientRect(&r1);

		int w,h;
		
		if(mainImage.cols)
		{
				//aleg minimul dintre dimensiunile imag si ale ferestrei de afisare
			if(mainImage.cols<r1.Width()) w=mainImage.cols;
			else w=r1.Width();
			if(mainImage.rows<r1.Height()) h=mainImage.rows;
			else h=r1.Height();
	
			//creez un dreptunghi cu dimensiunile minime si il umplu cu peria imagine
			CRect r(0,0,w-1,h-1);
			dc.FillRect(r,ImageBrush);

		}
}
		
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COpenCVInterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenCVInterfaceDlg::OnFileOpen32771()
{
	CFileDialog fOpenDlg(TRUE, "bmp", "", OFN_HIDEREADONLY|OFN_FILEMUSTEXIST, 
	"Bitmap Files (*.bmp)|*.bmp||", NULL);
	CFile m_dataFile;
	
	if(fOpenDlg.DoModal()==IDOK)
	{
		CString s=fOpenDlg.GetPathName();
	
		PSTR szFileName=strdup(s);
	
		//IplImage* img  = cvLoadImage(szFileName); 
		Mat temp;
		//temp=imread(szFileName,CV_LOAD_IMAGE_ANYDEPTH |CV_LOAD_IMAGE_COLOR);
		//temp=imread(szFileName,CV_LOAD_IMAGE_UNCHANGED);
		temp=imread(szFileName,CV_LOAD_IMAGE_GRAYSCALE);
		if(temp.cols>0)
		{
			mainImage=temp;
			ResetImageBrush();
			Invalidate();
		}
		else AfxMessageBox("error in opening file");
	}
}
void COpenCVInterfaceDlg::OnFileSave32776()
{
	CFileDialog fSaveDlg(FALSE, "bmp", "", OFN_HIDEREADONLY, 
	"Bitmap Files (*.bmp)|*.bmp||", NULL);
	CFile m_dataFile;
	
	if(fSaveDlg.DoModal()==IDOK)
	{
		CString s=fSaveDlg.GetPathName();
		PSTR szFileName=strdup(s);
		imwrite(szFileName,mainImage);	
	}
	
}
Mat COpenCVInterfaceDlg::InitImage(int rows, int cols)
{
	//Mat rez(rows,cols,CV_8UC3,Scalar(0,0,0));
	Mat rez(rows,cols,CV_8UC1,Scalar(0));
	return rez;
}

void COpenCVInterfaceDlg::ShowResult(Mat result)
{
	m_Result= CResultPtr(new CResultDlg(prelImage,this));
	m_Result->Create(CResultDlg::IDD,0);
	m_Result->ShowWindow(SW_SHOW);
}

void COpenCVInterfaceDlg::OnLoadPrelImage()
{
	mainImage=prelImage;
	ResetImageBrush();
	Invalidate();
}

void COpenCVInterfaceDlg::OnToolsInvert()
{
	prelImage=InitImage(mainImage.rows,mainImage.cols);
	for(int i=0;i<mainImage.rows;i++)
		for(int j=0;j<mainImage.cols;j++)
		{
			prelImage.at<uchar>(i,j)=255-mainImage.at<uchar>(i,j);
		}
	ShowResult(prelImage);

}


